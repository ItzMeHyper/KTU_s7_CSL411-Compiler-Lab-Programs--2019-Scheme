
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double original_time, optimized_time;

    int a, b, c, d;

    // Before Optimization
    start = clock();

    a = 10;
    b = 20;
    a = 10;          // Redundant statement
    c = a + b;
    d = a + b;       // Repeated calculation

    printf("Before Optimization:\n");
    printf("Result = %d\n", d);

    end = clock();

    original_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // After Optimization
    start = clock();

    a = 10;
    b = 20;
    d = a + b;

    printf("\nAfter Optimization:\n");
    printf("Result = %d\n", d);

    end = clock();

    optimized_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n========== COMPARISON ==========\n");
    printf("Original Time  = %f seconds\n", original_time);
    printf("Optimized Time = %f seconds\n", optimized_time);

    if (optimized_time < original_time)
        printf("Optimized program is faster.\n");
    else
        printf("No significant improvement in execution time.\n");

    return 0;
}
