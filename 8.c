#include <stdio.h>
#include <cuda_runtime.h>

__global__ void vectorAddBroadcast(int *A, int *C, int n, int broadcast_value) {
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    
    if (index < n) {
        C[index] = A[index] + broadcast_value;
    }
}

int main() {
    const int N = 10;
    const int blockSize = 256;
    const int numBlocks = (N + blockSize - 1) / blockSize;  
    int h_A[N], h_C[N];
    int broadcast_value = 5;
    
    for (int i = 0; i < N; i++) {
        h_A[i] = i;
    }
    
    int *d_A, *d_C;
    cudaMalloc((void**)&d_A, N * sizeof(int));
    cudaMalloc((void**)&d_C, N * sizeof(int));
    cudaMemcpy(d_A, h_A, N * sizeof(int), cudaMemcpyHostToDevice);
    
    vectorAddBroadcast<<<numBlocks, blockSize>>>(d_A, d_C, N, broadcast_value);
    cudaMemcpy(h_C, d_C, N * sizeof(int), cudaMemcpyDeviceToHost);
    
    printf("Result: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", h_C[i]);
    }
    printf("\n");
    
    cudaFree(d_A);
    cudaFree(d_C);
    
    return 0;
}


/*
%%writefile vector_add_broadcast.cu


!nvcc -o vector_add_broadcast vector_add_broadcast.cu                                                                                              # Step 4: Run the compiled program
!./vector_add_broadcast
*/