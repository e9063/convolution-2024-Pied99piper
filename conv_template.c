#include<stdio.h>
#include<stdlib.h>
#include <omp.h>
#include <unistd.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    double start,end;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }
    
    // ---- end input and malloc----
    int* R = (int*)malloc((NA - NF + 1) * sizeof(int));
    start = omp_get_wtime();
    for (int i = 0 ; i < NA - NF + 1 ; i++) {
        int t = 0;
        for (int j = 0 ; j < NF ; j++) {
            t += A[i + j] * F[NF - 1 - j];
        }
        R[i] = t;
    }
    end = omp_get_wtime();
    sequen_time = end - start;

    // ---- free memory ----
    free(F);
    free(A);
    free(R);
    // ---- end free ----
    return 0;
}

