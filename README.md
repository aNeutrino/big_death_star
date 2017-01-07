# big death star FLOAT problem
### why this code is not using my 8 FLOPS CPU capability, and looks like my CPU can do 1 FLOPS?
    #include<stdio.h>
    
    int main() {
        double a1 = 1.0;
        double m = 1.000001f;
        unsigned long long i = 0;
        unsigned long long max = 1000ull * 1000 * 1000;
        for (i = 0; i < max; i++) {
            a1 *= m;
        }
        printf("%lf\n", a1);
        return 0;
    }
### Lets consider similar code when 4 Double Precision Floating operations, are NOT depending from eachother crate one sequence in code.

    #include<stdio.h>

    int main() {
        double a1 = 1.0, a2 = 2.0, a3 = 3.0, a4 = 4.0;
        double m = 1.000001f;
        unsigned long long i = 0;
        unsigned long long max = 1000ull * 1000 * 1000;
        for (i = 0; i < max; i++) {
            a1 *= m;
            a2 *= m;
            a3 *= m;
            a4 *= m;
        }
        printf("%lf,%lf,%lf,%lf\n", a1, a2, a3, a4);
        return 0;
    }
    
###Measuring 16G Floating operations on 2 core 2 HT CPU with 3GHz clock:
runing code `1.c` on 16 threads took **6.697seconds**

runing code `4.c` on 4 threads took **2.731seconds**


    ./run_code_on_all_processors.sh 1.c 4
    Testing 1.c with 16 threads.
    Thread 2 inf
    Thread 12 inf
    Thread 11 inf
    Thread 9 inf
    Thread 14 inf
    Thread 13 inf
    Thread 4 inf
    Thread 7 inf
    Thread 1 inf
    Thread 15 inf
    Thread 0 inf
    Thread 8 inf
    Thread 3 inf
    Thread 10 inf
    Thread 5 inf
    Thread 6 inf
    
    real	0m6.697s
    user	0m25.900s
    sys	0m0.012s
    MHz : 3099.877 MHz : 3099.877 MHz : 3099.877 MHz : 3099.877
    

    ./run_code_on_all_processors.sh 4.c 1
    Testing 4.c with 4 threads.
    Thread 1 inf,inf,inf,inf
    Thread 0 inf,inf,inf,inf
    Thread 3 inf,inf,inf,inf
    Thread 2 inf,inf,inf,inf

    real	0m2.731s
    user	0m10.120s
    sys	0m0.012s
    MHz : 3099.877 MHz : 3100.036 MHz : 3173.034 MHz : 3185.571

    

### Comparison of generated Double Precision (DP) `MULSD` instructions inside of `for` loops by gcc 6.3 with `-O3`

`1.c`: https://godbolt.org/g/R3TJ2h

    .L2:
            sub     rax, 1
            mulsd   xmm0, xmm1
            jne     .L2

`4.c`: https://godbolt.org/g/KHFpE5

    .L2:
        sub     rax, 1
        mulsd   xmm0, xmm4
        mulsd   xmm1, xmm4
        mulsd   xmm2, xmm4
        mulsd   xmm3, xmm4
        jne     .L2
        
### Conclusion

CPU can use its ability of runing in 1 cycle many DoublePrecision or SinglePrecision Floating operations sequences **if operations in sequence are not depending from eachoter**
