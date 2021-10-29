#include <stdint.h>
#include <stddef.h>
#include "nmath.h"
#include <stdio.h>

static inline int matn_print(const float *src, size_t n){
    for(size_t i = 0;i < n;i++){
        printf("|");
        for(size_t j = 0;j < n-1;j++)
            printf("%f, ", matn_get(src, j, i, n));
        printf("%f", matn_get(src, n-1, i, n));
        printf("|\n");
    }
    return 1;
}

static inline int matnm_print(const float *src, size_t n, size_t m){
    for(size_t i = 0;i < m;i++){
        printf("|");
        for(size_t j = 0;j < n-1;j++)
            printf("%f, ", matnm_get(src, j, i, n));
        printf("%f", matnm_get(src, n-1, i, n));
        printf("|\n");
    }
    return 1;
}

static inline int vecn_print(const float *src, size_t n){
    printf("(");
    for(size_t i = 0;i < n-1;i++)
        printf("%f, ", src[i]);
    printf("%f)\n", src[n-1]);
    return 1;
}

int main(){
    printf("Test1:\n");

    float *mat1 = (float[]){
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    matn_print(mat1, 3);

    printf("*\n");

    float vec1[3];
    vecn_one(vec1, 3);
    vecn_print(vec1, 3);
    float vec2[3];

    printf("=\n");

    matn_mult_vecn(vec2, mat1, vec1, 3);

    vecn_print(vec2, 3);

    float *mat2 = (float []){
        1, 2, 3,
        4, 5, 6, 
        7, 8, 9
    };

    matn_print(mat1, 3);
    printf("*\n");
    matn_print(mat2, 3);

    float mat3[3 * 3];

    printf("=\n");
    matn_mult(mat3, mat1, mat2, 3);
    matn_print(mat3, 3);

    printf("\n\n");

    mat1 = (float []){
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12
    };

    mat2 = (float []){
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        10, 11, 12
    };

    matnm_print(mat1, 4, 3);

    printf("*\n");

    matnm_print(mat2, 3, 4);

    printf("=\n");

    matnm_mult(mat3, mat1, mat2, 4, 3, 3);

    matnm_print(mat3, 3, 3);

    printf("\n\n");

    float mat4[3 * 4];
    float mat5[4 * 4];

    matnm_t(mat4, mat1, 4, 3);

    matnm_print(mat4, 3, 4);
    printf("*\n");
    matnm_print(mat1, 4, 3);
    printf("=\n");

    matnm_mult(mat5, mat4, mat1, 3, 4, 4);

    matnm_print(mat5, 4, 4);

    printf("\n\n");

    float mat6[3 * 4];
    matnm_t(mat6, mat1, 4, 3);

    matnm_print(mat4, 3, 4);
    printf("*\nt(\n");
    matnm_print(mat6, 3, 4);
    printf(") = \n");

    matnm_multt(mat5, mat4, mat6, 3, 4, 4);
    matnm_print(mat5, 4, 4);


    float *vec3 = (float []){1, 2, 3};
    float vec4[4];

    // vectors can be column matrices (1 x n) or row matrices (n x 1) the indices in the mult function determine their use.

    printf("\n\n");
    matnm_print(mat2, 3, 4);
    printf("*\n");
    vecn_print(vec3, 3);

    // vector as column vector
    matnm_mult(vec4, mat2, vec3, 3, 4, 1);
    printf("=\n");
    vecn_print(vec4, 4);
    // vector as row vector
    matnm_multt(vec4, mat2, vec3, 3, 4, 1);
    printf("=\n");
    vecn_print(vec4, 4);


    




    return 0;
}

