#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double original_time, optimized_time;

    start = clock();

    int a1 = 5;
    int b1 = 10;
    int c1 = a1 + b1;

    printf("Original Program (Without Constant Propagation):\n");
    printf("a = %d\n", a1);
    printf("b = %d\n", b1);
    printf("Sum: %d\n", c1);

    end = clock();

    original_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n\n", original_time);

    start = clock();

    int a2 = 5;
    int b2 = 10;
    int c2 = 5 + 10;

    printf("Optimized Program (With Constant Propagation):\n");
    printf("a = %d\n", a2);
    printf("b = %d\n", b2);
    printf("Sum: %d\n", c2);

    end = clock();

    optimized_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n\n", optimized_time);

    printf("========== COMPARISON ==========\n");
    printf("Original Time  : %f seconds\n", original_time);
    printf("Optimized Time : %f seconds\n", optimized_time);

    if (optimized_time < original_time)
        printf("Optimized program is faster.\n");
    else if (optimized_time > original_time)
        printf("Original program is faster.\n");
    else
        printf("Both programs have approximately the same execution time.\n");

    return 0;
}