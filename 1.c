#include <stdio.h>
#include <omp.h>

int main()
{
    int sum = 0;

#pragma omp parallel shared(sum)
    {
        int local_sum = 0;

#pragma omp for
        for (int i = 0; i < 100; i++)
        {
            local_sum += i + 1;
        }

#pragma omp critical
        {
            sum += local_sum;
        }
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}

/*
Sum of array elements: 5050
*/