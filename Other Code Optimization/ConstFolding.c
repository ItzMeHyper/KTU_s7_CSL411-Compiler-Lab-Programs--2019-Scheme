
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double original_time, optimized_time;
    int a, b;

    // Before Optimization
    start = clock();

    a = 10 + 20;
    b = 5 * 4;

    printf("Before Optimization:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    end = clock();
    original_time = (double)(end - start) / CLOCKS_PER_SEC;

    // After Optimization
    start = clock();

    a = 30;
    b = 20;

    printf("\nAfter Optimization:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    end = clock();
    optimized_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nOriginal Time = %f seconds\n", original_time);
    printf("Optimized Time = %f seconds\n", optimized_time);

    return 0;
}
