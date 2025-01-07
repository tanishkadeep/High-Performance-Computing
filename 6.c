#include <omp.h>
#include <stdio.h>

int main()
{
    int n = 16;
    omp_set_num_threads(4);

    // Demonstrating Static Scheduling
    printf("\nDemonstrating Static Scheduling (Chunk Size: 4)\n");
#pragma omp parallel for schedule(static, 4)
    for (int i = 0; i < n; i++)
    {
        printf("Static Scheduling - Thread %d working on iteration %d\n", omp_get_thread_num(), i);
    }

    // Demonstrating Dynamic Scheduling
    printf("\nDemonstrating Dynamic Scheduling (Chunk Size: 4)\n");
#pragma omp parallel for schedule(dynamic, 4)
    for (int i = 0; i < n; i++)
    {
        printf("Dynamic Scheduling - Thread %d working on iteration %d\n", omp_get_thread_num(), i);
    }

    // Demonstrating Guided Scheduling
    printf("\nDemonstrating Guided Scheduling (Chunk Size: 4)\n");
#pragma omp parallel for schedule(guided, 4)
    for (int i = 0; i < n; i++)
    {
        printf("Guided Scheduling - Thread %d working on iteration %d\n", omp_get_thread_num(), i);
    }

    // Demonstrating Auto Scheduling
    printf("\nDemonstrating Auto Scheduling (Chunk Size: 0)\n");
#pragma omp parallel for schedule(auto)
    for (int i = 0; i < n; i++)
    {
        printf("Auto Scheduling - Thread %d working on iteration %d\n", omp_get_thread_num(), i);
    }

    return 0;
}


/*
Demonstrating Static Scheduling (Chunk Size: 4)
Static Scheduling - Thread 1 working on iteration 4
Static Scheduling - Thread 1 working on iteration 5
Static Scheduling - Thread 1 working on iteration 6
Static Scheduling - Thread 1 working on iteration 7
Static Scheduling - Thread 0 working on iteration 0
Static Scheduling - Thread 0 working on iteration 1
Static Scheduling - Thread 0 working on iteration 2
Static Scheduling - Thread 0 working on iteration 3
Static Scheduling - Thread 3 working on iteration 12
Static Scheduling - Thread 3 working on iteration 13
Static Scheduling - Thread 3 working on iteration 14
Static Scheduling - Thread 3 working on iteration 15
Static Scheduling - Thread 2 working on iteration 8
Static Scheduling - Thread 2 working on iteration 9
Static Scheduling - Thread 2 working on iteration 10
Static Scheduling - Thread 2 working on iteration 11

Demonstrating Dynamic Scheduling (Chunk Size: 4)
Dynamic Scheduling - Thread 10 working on iteration 0
Dynamic Scheduling - Thread 10 working on iteration 1
Dynamic Scheduling - Thread 10 working on iteration 2
Dynamic Scheduling - Thread 10 working on iteration 3
Dynamic Scheduling - Thread 15 working on iteration 12
Dynamic Scheduling - Thread 15 working on iteration 13
Dynamic Scheduling - Thread 15 working on iteration 14
Dynamic Scheduling - Thread 15 working on iteration 15
Dynamic Scheduling - Thread 9 working on iteration 8
Dynamic Scheduling - Thread 9 working on iteration 9
Dynamic Scheduling - Thread 9 working on iteration 10
Dynamic Scheduling - Thread 9 working on iteration 11
Dynamic Scheduling - Thread 6 working on iteration 4
Dynamic Scheduling - Thread 6 working on iteration 5
Dynamic Scheduling - Thread 6 working on iteration 6
Dynamic Scheduling - Thread 6 working on iteration 7

Demonstrating Guided Scheduling (Chunk Size: 4)
Guided Scheduling - Thread 18 working on iteration 0
Guided Scheduling - Thread 18 working on iteration 1
Guided Scheduling - Thread 18 working on iteration 2
Guided Scheduling - Thread 18 working on iteration 3
Guided Scheduling - Thread 16 working on iteration 8
Guided Scheduling - Thread 16 working on iteration 9
Guided Scheduling - Thread 16 working on iteration 10
Guided Scheduling - Thread 3 working on iteration 12
Guided Scheduling - Thread 3 working on iteration 13
Guided Scheduling - Thread 1 working on iteration 4
Guided Scheduling - Thread 1 working on iteration 5
Guided Scheduling - Thread 1 working on iteration 6
Guided Scheduling - Thread 1 working on iteration 7
Guided Scheduling - Thread 3 working on iteration 14
Guided Scheduling - Thread 3 working on iteration 15
Guided Scheduling - Thread 16 working on iteration 11

Demonstrating Auto Scheduling (Chunk Size: 0)
Auto Scheduling - Thread 14 working on iteration 14
Auto Scheduling - Thread 4 working on iteration 4
Auto Scheduling - Thread 9 working on iteration 9
Auto Scheduling - Thread 13 working on iteration 13
Auto Scheduling - Thread 11 working on iteration 11
Auto Scheduling - Thread 2 working on iteration 2
Auto Scheduling - Thread 15 working on iteration 15
Auto Scheduling - Thread 8 working on iteration 8
Auto Scheduling - Thread 1 working on iteration 1
Auto Scheduling - Thread 3 working on iteration 3
Auto Scheduling - Thread 6 working on iteration 6
Auto Scheduling - Thread 5 working on iteration 5
Auto Scheduling - Thread 12 working on iteration 12
Auto Scheduling - Thread 7 working on iteration 7
Auto Scheduling - Thread 10 working on iteration 10
Auto Scheduling - Thread 0 working on iteration 0
*/