#include <omp.h>
#include <stdio.h>

int main()
{
    int n = 16;

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
