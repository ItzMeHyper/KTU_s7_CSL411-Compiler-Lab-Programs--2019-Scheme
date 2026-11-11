
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double original_time, optimized_time;
    int a, b;

    // Before Optimization
    start = clock();

    b = 10;
    a = b * 2;

    printf("Before Optimization:\n");
    printf("Result = %d\n", a);

    end = clock();
    original_time = (double)(end - start) / CLOCKS_PER_SEC;

    // After Optimization
    start = clock();

    b = 10;
    a = b + b;

    printf("\nAfter Optimization:\n");
    printf("Result = %d\n", a);

    end = clock();
    optimized_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nOriginal Time = %f seconds\n", original_time);
    printf("Optimized Time = %f seconds\n", optimized_time);

    return 0;
}
