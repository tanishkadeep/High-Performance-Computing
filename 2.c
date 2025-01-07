#include <stdio.h>
#include <omp.h>

#define N 10

int main() {
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

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

        // Work-sharing loop
        #pragma omp for
        for (int i = 0; i < N; i++) {
            printf("Thread %d processing element %d\n", omp_get_thread_num(), arr[i]);
        }
    }

    return 0;
}


/*
Initialization done by thread 0
Section 1 executed by thread 1
Section 2 executed by thread 3
Thread 0 processing element 1
Thread 0 processing element 2
Thread 0 processing element 3
Thread 1 processing element 4
Thread 3 processing element 9
Thread 3 processing element 10
Thread 1 processing element 5
Thread 1 processing element 6
Thread 2 processing element 7
Thread 2 processing element 8
*/