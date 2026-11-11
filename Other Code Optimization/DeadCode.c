
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double original_time, optimized_time;
    int a, b;

    // Before Optimization
    start = clock();

    a = 10;
    b = 50;
    a = 20;       // First assignment is unnecessary

    printf("Before Optimization:\n");
    printf("a = %d\n", a);

    end = clock();
    original_time = (double)(end - start) / CLOCKS_PER_SEC;

    // After Optimization
    start = clock();

    a = 20;

    printf("\nAfter Optimization:\n");
    printf("a = %d\n", a);

    end = clock();
    optimized_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nOriginal Time = %f seconds\n", original_time);
    printf("Optimized Time = %f seconds\n", optimized_time);

    return 0;
}
