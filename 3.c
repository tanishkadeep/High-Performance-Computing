#include <omp.h>
#include <stdio.h>

int main()
{
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf("Hello from thread %d\n", thread_id);
    }
    return 0;
}

/*
Hello from thread 1
Hello from thread 23
Hello from thread 2
Hello from thread 16
Hello from thread 0
Hello from thread 22
Hello from thread 17
Hello from thread 20
Hello from thread 8
Hello from thread 10
Hello from thread 11
Hello from thread 6
Hello from thread 9
Hello from thread 12
Hello from thread 5
Hello from thread 3
Hello from thread 13
Hello from thread 4
Hello from thread 21
Hello from thread 7
Hello from thread 15
Hello from thread 18
Hello from thread 19
Hello from thread 14
*/