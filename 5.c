#include <omp.h>
#include <stdio.h>

int counter = 0; // Shared variable

#pragma omp threadprivate(counter) // Declare counter as thread-private

int main() {
    #pragma omp parallel
    {
        // Each thread has its own private copy of counter
        counter++;
        printf("Thread %d: counter = %d\n", omp_get_thread_num(), counter);
    }

    return 0;
}
