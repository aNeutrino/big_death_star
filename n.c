#include<stdio.h>
#define FLOATS 8
double a[FLOATS];

void init_floats_with_different_values_to_avoid_optimisations() {
    for (int j = 0; j < FLOATS; ++j){
        a[j] = j + 1.0;
    }
}
void printf_floats() {
    for (int j = 0; j < FLOATS; ++j){
        printf("%lf,", a[j]);
    }
    printf("\n");
}

int main() {
    double m = 1.000001f;
    unsigned long long i = 0;
    unsigned long long max = 1000ull * 1000 * 1000;

    init_floats_with_different_values_to_avoid_optimisations();

    for (i = 0; i < max; i++) {
        for (int j = 0; j < FLOATS; ++j) {
            a[j] *= m;
        }
    }

    printf_floats();

    return 0;
}

