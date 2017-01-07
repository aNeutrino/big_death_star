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
