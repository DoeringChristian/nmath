#ifndef NMATH_H
#define NMATH_H

#ifndef NM_FLOAT
#define NM_FLOAT float
#endif //NM_FLOAT

#ifndef NM_INLINE
#define NM_INLINE inline
#endif //NM_INLINE

#ifndef NM_SIZE
#include <stddef.h>
#define NM_SIZE size_t
#endif //NM_SIZE

#ifndef NM_SQRT
#include <math.h>
#define NM_SQRT(_x) sqrtf(_x)
#endif //NM_SQRT

#ifndef NM_CEIL
#include <math.h>
#define NM_CEIL(_x) ceilf(_x)
#endif //NM_CEIL

#ifndef NM_FLOOR
#include <math.h>
#define NM_FLOOR(_x) ceilf(_x)
#endif //NM_FLOOR

#ifndef NM_MIN
#include <math.h>
#define NM_MIN(_x, _y) fminf(_x, _y)
#endif //NM_MIN

#ifndef NM_MAX
#include <math.h>
#define NM_MAX(_x, _y) fmaxf(_x, _y)
#endif //NM_MAX




/*
 * vecn: float array of length n represents vector of length n.
 * matn: float array of length n * n represents nxn matrix.
 * matnm: float array of length n * m represents nxm matrix. n: width, m: height.
 *
 * row major order.
 *
 * | 0       | 1   | ... | n-1    |
 * | n       | n+1 |     |        |
 * | ...     |     |     |        |
 * | n*(m-1) | ... |     | n*m -1 |
 *
 *
 * m[i + j*n]
 *
 */


static NM_INLINE NM_FLOAT *vecn_zero(NM_FLOAT *dst, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n;i++)
        dst[i] = 0.0;
    return dst;
}

static NM_INLINE NM_FLOAT *vecn_one(NM_FLOAT *dst, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n;i++)
        dst[i] = 1.0;
    return dst;
}

static NM_INLINE NM_FLOAT *vecn_add(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n;i++)
        dst[i] = src1[i] + src2[i];
    return dst;
}

static NM_INLINE NM_FLOAT *vecn_sub(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n;i++)
        dst[i] = src1[i] - src2[i];
    return dst;
}

static NM_INLINE NM_FLOAT vecn_dot(const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n){
    NM_SIZE i;
    NM_FLOAT dst = 0.0;
    for(i = 0;i < n;i++)
        dst += src1[i] * src2[i];
    return dst;
}

static NM_INLINE NM_FLOAT *vecn_scale(NM_FLOAT *dst, const NM_FLOAT *src, const NM_FLOAT s, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n;i++)
        dst[i] = src[i] * s;
    return dst;
}

static NM_INLINE NM_FLOAT *vecn_neg(NM_FLOAT *dst, const NM_FLOAT *src, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n;i++)
        dst[i] = -src[i];
    return dst;
}

static NM_INLINE NM_FLOAT vecn_len(const NM_FLOAT *src, NM_SIZE n){
    NM_SIZE i;
    NM_FLOAT dst;
    for(i = 0;i < n;i++)
        dst += src[i] * src[i];
    return NM_SQRT(dst);
}

static NM_INLINE NM_FLOAT *vecn_normalize(NM_FLOAT *dst, const NM_FLOAT *src, NM_SIZE n){
    NM_SIZE i;
    NM_FLOAT len;
    len = vecn_len(src, n);
    for(i = 0;i < n;i++)
        dst[i] = src[i] / len;
    return dst;
}

static NM_INLINE NM_FLOAT *vecn_min(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n;i++)
        dst[i] = NM_MIN(src1[i], src2[i]);
    return dst;
}

static NM_INLINE NM_FLOAT *vecn_max(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n;i++)
        dst[i] = NM_MAX(src1[i], src2[i]);
    return dst;
}

static NM_INLINE NM_FLOAT *vecn_ceil(NM_FLOAT *dst, const NM_FLOAT *src, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n;i++)
        dst[i] = NM_CEIL(src[i]);
    return dst;
}

static NM_INLINE NM_FLOAT *vecn_floor(NM_FLOAT *dst, const NM_FLOAT *src, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n;i++)
        dst[i] = NM_FLOOR(src[i]);
    return dst;
}



/*
 * ====================
 * Matrix N x M :
 * ====================
 */

static NM_INLINE NM_FLOAT *matnm_zero(NM_FLOAT *dst, NM_SIZE n, NM_SIZE m){
    NM_SIZE i;
    for(i = 0;i < n*m;i++){
        dst[i] = 0.0;
    }
    return dst;
}

static NM_INLINE NM_FLOAT *matnm_one(NM_FLOAT *dst, NM_SIZE n, NM_SIZE m){
    NM_SIZE i, j;
    for(j = 0;j < m;j++){
        for(i = 0;i < n;i++){
            if(i == j)
                dst[i + j * n] = 1.0;
            else
                dst[i + j * n] = 0.0;
        }
    }
    return dst;
}

static NM_INLINE NM_FLOAT *matnm_at(NM_FLOAT *src, NM_SIZE col, NM_SIZE row, NM_SIZE n){
    return &src[col + row * n];
}

static NM_INLINE NM_FLOAT *matnm_att(NM_FLOAT *src, NM_SIZE col, NM_SIZE row, NM_SIZE m){
    return &src[row + col * m];
}

const static NM_INLINE NM_FLOAT *matnm_atc(const NM_FLOAT *src, NM_SIZE col, NM_SIZE row, NM_SIZE n){
    return &src[col + row * n];
}

const static NM_INLINE NM_FLOAT *matnm_attc(const NM_FLOAT *src, NM_SIZE col, NM_SIZE row, NM_SIZE m){
    return &src[row + col * m];
}

static NM_INLINE NM_FLOAT matnm_get(const NM_FLOAT *src, NM_SIZE col, NM_SIZE row, NM_SIZE n){
    return src[col + row * n];
}

static NM_INLINE NM_FLOAT matnm_gett(const NM_FLOAT *src, NM_SIZE col, NM_SIZE row, NM_SIZE m){
    return src[row + col * m];
}

static NM_INLINE NM_FLOAT *matnm_t(NM_FLOAT *dst, const NM_FLOAT *src, NM_SIZE n, NM_SIZE m){
    NM_SIZE i, j;
    for(j = 0;j < m;j++){
        for(i = 0;i < n;i++){
            *matnm_att(dst, i, j, m) = matnm_get(src, i, j, n);
        }
    }
    return dst;
}

static NM_INLINE NM_FLOAT *matnm_add(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n, NM_SIZE m){
    NM_SIZE i;
    for(i = 0;i < n * m;i++)
        dst[i] = src1[i] + src2[i];
    return dst;
}

// n, m from non transposed matrix
static NM_INLINE NM_FLOAT *matnm_addt(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n1, NM_SIZE m1){
    NM_SIZE i, j;
    for(i = 0;i < n1;i++)
        for(j = 0;j < m1;j++)
            *matnm_at(dst, i, j, n1) = matnm_get(src1, i, j, n1) + matnm_gett(src2, i, j, n1);
    return dst;
}

static NM_INLINE NM_FLOAT *matnm_sub(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n, NM_SIZE m){
    NM_SIZE i;
    for(i = 0;i < n * m;i++)
        dst[i] = src1[i] - src2[i];
    return dst;
}

static NM_INLINE NM_FLOAT *matnm_subt(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n1, NM_SIZE m1){
    NM_SIZE i, j;
    for(i = 0;i < n1;i++)
        for(j = 0;j < m1;j++)
            *matnm_at(dst, i, j, n1) = matnm_get(src1, i, j, n1) - matnm_gett(src2, i, j, n1);
    return dst;
}

static NM_INLINE NM_FLOAT *matnm_scale(NM_FLOAT *dst, const NM_FLOAT *src, NM_FLOAT s, NM_FLOAT n, NM_FLOAT m){
    NM_SIZE i;
    for(i = 0;i < n * m;i++)
        dst[i] = src[i] * s;
    return dst;
}

static NM_INLINE NM_FLOAT *matnm_mult(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n1, NM_SIZE m1, NM_SIZE n2){
    NM_SIZE i, j, k;
    for(i = 0;i < n2;i++){
        for(j = 0;j < m1;j++){
            *matnm_at(dst, i, j, n2) = 0.0;
            for(k = 0;k < n1;k++)
                *matnm_at(dst, i, j, n2) += matnm_get(src1, k, j, n1) * matnm_get(src2, i, k, n2);
        }
    }
    return dst;
}

static NM_INLINE NM_FLOAT *matnm_multt(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n1, NM_SIZE m1, NM_SIZE m2){
    NM_SIZE i, j, k;
    for(i = 0;i < m2;i++){
        for(j = 0;j < m1;j++){
            *matnm_at(dst, i, j, m2) = 0.0;
            for(k = 0;k < n1;k++)
                *matnm_at(dst, i, j, m2) += matnm_get(src1, k, j, n1) * matnm_get(src2, i, k, m2);
        }
    }
    return dst;
}


/*
 * ====================
 * Matrix N x N :
 * ====================
 */

static NM_INLINE NM_FLOAT *matn_one(NM_FLOAT *dst, NM_SIZE n){
    NM_SIZE i, j;
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            if(j == i)
                dst[i + j*n] = 1.0;
            else
                dst[i + j*n] = 0.0;
        }
    }
    return dst;
}

static NM_INLINE NM_FLOAT *matn_zero(NM_FLOAT *dst, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n * n;i++)
        dst[i] = 0.0;
    return dst;
}

static NM_INLINE NM_FLOAT *matn_at(NM_FLOAT *src, NM_SIZE row, NM_SIZE col, NM_SIZE n){
    return &src[col + row * n];
}

static NM_INLINE NM_FLOAT *matn_att(NM_FLOAT *src, NM_SIZE row, NM_SIZE col, NM_SIZE n){
    return &src[row + col * n];
}

const static NM_INLINE NM_FLOAT *matn_atc(const NM_FLOAT *src, NM_SIZE row, NM_SIZE col, NM_SIZE n){
    return &src[col + row * n];
}

const static NM_INLINE NM_FLOAT *matn_attc(const NM_FLOAT *src, NM_SIZE row, NM_SIZE col, NM_SIZE n){
    return &src[row + col * n];
}


static NM_INLINE NM_FLOAT matn_get(const NM_FLOAT *src, NM_SIZE row, NM_SIZE col, NM_SIZE n){
    return src[col + row * n];
}

static NM_INLINE NM_FLOAT matn_gett(const NM_FLOAT *src, NM_SIZE row, NM_SIZE col, NM_SIZE n){
    return src[row + col * n];
}

static NM_INLINE NM_FLOAT *matn_t(NM_FLOAT *dst, const NM_FLOAT *src, NM_SIZE n){
    NM_SIZE i, j;
    for(j = 0;j < n;j++){
        for(i = 0;i < n;i++){
            *matn_at(dst, i, j, n) = matn_get(src, j, i, n);
        }
    }
    return dst;
}

static NM_INLINE NM_FLOAT *matn_add(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n * n;i++)
        dst[i] = src1[i] + src2[i];
    return dst;
}

static NM_INLINE NM_FLOAT *matn_sub(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n){
    NM_SIZE i;
    for(i = 0;i < n * n;i++)
        dst[i] = src1[i] - src2[i];
    return dst;
}

static NM_INLINE NM_FLOAT *matn_scale(NM_FLOAT *dst, const NM_FLOAT *src, NM_FLOAT s, NM_FLOAT n){
    NM_SIZE i;
    for(i = 0;i < n * n;i++)
        dst[i] = src[i] * s;
    return dst;
}

static NM_INLINE NM_FLOAT *matn_mult(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2, NM_SIZE n){
    NM_SIZE j, i, k;
    for(j = 0;j < n;j++){
        for(i = 0;i < n;i++){
            *matn_at(dst, i, j, n) = 0.0;
            for(k = 0;k < n;k++)
                *matn_at(dst, i, j, n) += matn_get(src1, j, k, n) * matn_get(src2, k, i, n);
        }
    }
    return dst;
}

static NM_INLINE NM_FLOAT *matn_multt(NM_FLOAT *dst, const NM_FLOAT *src1, const NM_FLOAT *src2_t, NM_SIZE n){
    NM_SIZE j, i, k;
    for(j = 0;j < n;j++){
        for(i = 0;i < n;i++){
            *matn_at(dst, i, j, n) = 0.0;
            for(k = 0;k < n;k++)
                *matn_at(dst, i, j, n) += matn_get(src1, j, k, n) * matn_gett(src2_t, k, i, n);
        }
    }
    return dst;
}

static NM_INLINE NM_FLOAT *matn_mult_vecn(NM_FLOAT *dst_v, const NM_FLOAT *src1_m, const NM_FLOAT *src2_v, NM_SIZE n){
    NM_SIZE i, j;
    for(i = 0;i < n;i++){
        dst_v[i] = vecn_dot(matn_atc(src1_m, i, 0, n), src2_v, n);
    }
    return dst_v;
}

#endif //NMATH_H
