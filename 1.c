#include<stdio.h>

main() {
    double a1 = 1.0;
    double m = 1.000001f;
    unsigned long long i = 0;
    unsigned long long max = 1000ull * 1000 * 1000;
    for (i = 0; i < max; i++) {
        a1 *= m;
    }
    printf("%lf\n", a1);
}
