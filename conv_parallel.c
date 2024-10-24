#include<stdio.h>
#include<stdlib.h>
#include <omp.h>
#include <unistd.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    double start, end, parallel_time;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }

    int* R = (int*)malloc((NA - NF + 1) * sizeof(int));
    start = omp_get_wtime();
    omp_set_num_threads(4);
    #pragma omp parallel for
    for (int i = 0; i < NA - NF + 1; i++) {
        R[i] = 0;
        for (int j = 0; j < NF; j++) {
            R[i] += A[i + j] * F[NF - 1 - j];
        }
    }
    end = omp_get_wtime();
    parallel_time = end - start;
    printf("parallel time : %f", parallel_time);
    for (int i = 0 ; i < NA - NF + 1 ; i++) {
        printf("%d\n",R[i]);
    }
    
    free(F);
    free(A);
    free(R);
    return 0;
}