
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double original_time, optimized_time;
    int a, b, c;

    // Before Optimization
    start = clock();

    b = 10;
    a = b;
    c = a + 10;

    printf("Before Optimization:\n");
    printf("a = %d\n", a);
    printf("c = %d\n", c);

    end = clock();
    original_time = (double)(end - start) / CLOCKS_PER_SEC;

    // After Optimization
    start = clock();

    b = 10;
    a = b;
    c = b + 10;

    printf("\nAfter Optimization:\n");
    printf("a = %d\n", a);
    printf("c = %d\n", c);

    end = clock();
    optimized_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nOriginal Time = %f seconds\n", original_time);
    printf("Optimized Time = %f seconds\n", optimized_time);

    return 0;
}
