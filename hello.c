#include <stdio.h>
#include <omp.h>
int main()
{
#pragma omp parallel
    printf("Hello, world! This is thread %d of %d\n", omp_get_thread_num(),
           omp_get_num_threads());
}

/*
gcc -fopenmp hello.c -o hello.exe
hello.exe

Hello, world! This is thread 0 of 4
Hello, world! This is thread 3 of 4
Hello, world! This is thread 1 of 4
Hello, world! This is thread 2 of 4
*/