#include <omp.h>
#include <stdio.h>

int main()
{
#pragma omp parallel
    {
#pragma omp single
        {
            for (int i = 0; i < 5; i++)
            {
#pragma omp task
                {
                    printf("Task %d is being processed by thread %d\n", i, omp_get_thread_num());
                }
            }
        }
    }
    return 0;
}

/*
Task 0 is being processed by thread 4
Task 1 is being processed by thread 4
Task 2 is being processed by thread 4
Task 3 is being processed by thread 1
Task 4 is being processed by thread 16
*/