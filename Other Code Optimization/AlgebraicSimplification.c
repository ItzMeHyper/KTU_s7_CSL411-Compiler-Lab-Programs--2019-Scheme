
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double original_time, optimized_time;
    int a, b, c, d;

    // Before Optimization
    start = clock();

    b = 10;
    a = b + 0;
    c = b * 1;
    d = b * 0;

    printf("Before Optimization:\n");
    printf("a = %d\n", a);
    printf("c = %d\n", c);
    printf("d = %d\n", d);

    end = clock();
    original_time = (double)(end - start) / CLOCKS_PER_SEC;

    // After Optimization
    start = clock();

    b = 10;
    a = b;
    c = b;
    d = 0;

    printf("\nAfter Optimization:\n");
    printf("a = %d\n", a);
    printf("c = %d\n", c);
    printf("d = %d\n", d);

    end = clock();
    optimized_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nOriginal Time = %f seconds\n", original_time);
    printf("Optimized Time = %f seconds\n", optimized_time);

    return 0;
}
