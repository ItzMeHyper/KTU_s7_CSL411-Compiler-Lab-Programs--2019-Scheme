#include <stdio.h>
#include <time.h>

clock_t start, end;

double with_loop();
double out_loop();

double with_loop(){
    start = clock();

    for (int i = 0; i < 20; i++){
        printf("Hello ");
        //printf("\n");
    }

    end = clock();

    double time_taken;
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    return time_taken;
}

double out_loop(){
    start = clock();

    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");
    printf("Hello ");

    end = clock();

    double time_taken;
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    return time_taken;
}

int main(){
    double time_with_loop;
    double time_without_loop;

    printf("Output with loop:\n");
    time_with_loop = with_loop();

    printf("\n\nOutput without loop:\n");
    time_without_loop = out_loop();

    printf("\n\nTime with loop: %f seconds\n", time_with_loop);
    printf("Time without loop: %f seconds\n", time_without_loop);

    return 0;
}