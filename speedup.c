#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    int NA, NF;
    double start, end, parallel_time, sequen_time;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }

    int* FF = (int*)malloc(NF * sizeof(int));
    for (int j = 0 ; j < NF ; ++j) {
        FF[j] = F[NF - 1 - j];
    }

    // pararllel 
    int* R = (int*)malloc((NA - NF + 1) * sizeof(int));
    start = omp_get_wtime();
    omp_set_num_threads(4);
    #pragma omp parallel for schedule(static)
    for (int i = 0 ; i < NA - NF + 1 ; i++) {
        int t = 0;
        for (int j = 0 ; j < NF ; j++) {
            t += (A[i + j] * FF[j]);
        }
        R[i] = t;
    }
    end = omp_get_wtime();
    parallel_time = end - start;

    // sequential
    start = omp_get_wtime();
    for (int i = 0 ; i < NA - NF + 1 ; i++) {
        int t = 0;
        for (int j = 0 ; j < NF ; j++) {
            t += (A[i + j] * FF[j]);
        }
        R[i] = t;
    }
    end = omp_get_wtime();
    sequen_time = end - start;

    // printf("parallel time : %f\n", parallel_time);
    for (int i = 0 ; i < NA - NF + 1 ; i++) {
        printf("%d\n",R[i]);
    }
    
    printf("sequential time : %f\n", sequen_time);
    printf("parallel time : %f\n", parallel_time);
    printf("speed up : %f\n", sequen_time / parallel_time);

    free(F);
    free(A);
    free(R);
    return 0;
}