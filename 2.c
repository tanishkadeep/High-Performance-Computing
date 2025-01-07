#include <stdio.h>
#include <omp.h>

int main()
{

#pragma omp parallel
    {
// Single block to initialize
#pragma omp single
        {
            printf("Initialization done by thread %d\n", omp_get_thread_num());
        }

// Sections for different tasks
#pragma omp sections
        {
#pragma omp section
            {
                printf("Section 1 executed by thread %d\n", omp_get_thread_num());
            }

#pragma omp section
            {
                printf("Section 2 executed by thread %d\n", omp_get_thread_num());
            }
        }

#pragma omp for
        for (int i = 0; i < 5; i++)
        {
            printf("Thread %d is processing iteration %d\n", omp_get_thread_num(), i);
        }
    }

    return 0;
}

/*
Initialization done by thread 1
Section 1 executed by thread 7
Section 2 executed by thread 0
Thread 1 is processing iteration 1
Thread 2 is processing iteration 2
Thread 4 is processing iteration 4
Thread 3 is processing iteration 3
Thread 0 is processing iteration 0
*/