#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
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
    

    // ---- free memory ----
    free(F);
    free(A);
    free(R);
    // ---- end free ----
    return 0;
}

