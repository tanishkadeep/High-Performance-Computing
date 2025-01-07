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

/*
Thread 1: counter = 1
Thread 8: counter = 1
Thread 6: counter = 1
Thread 0: counter = 1
Thread 20: counter = 1
Thread 10: counter = 1
Thread 11: counter = 1
Thread 4: counter = 1
Thread 3: counter = 1
Thread 12: counter = 1
Thread 13: counter = 1
Thread 14: counter = 1
Thread 16: counter = 1
Thread 15: counter = 1
Thread 17: counter = 1
Thread 21: counter = 1
Thread 22: counter = 1
Thread 18: counter = 1
Thread 2: counter = 1
Thread 9: counter = 1
Thread 5: counter = 1
Thread 19: counter = 1
Thread 7: counter = 1
Thread 23: counter = 1
*/