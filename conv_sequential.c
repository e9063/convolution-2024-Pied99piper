#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>

int main() {
    int NA, NF;
    double start,end;
    double sequen_time;
    scanf("%d %d", &NA, &NF); 
    int* A = (int*)malloc(NA * sizeof(int));
    int* F = (int*)malloc(NF * sizeof(int));
    int* R = (int*)malloc((NA - NF + 1) * sizeof(int));

    for (int i = 0; i < NA; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < NF; i++) {
        scanf("%d", &F[i]);
    }

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
    printf("sequen time : %f", sequen_time);
    for (int i = 0 ; i < NA - NF + 1 ; i++) {
        printf("%d\n",R[i]);
    }

    free(F);
    free(A);
    free(R);
    return 0;
}