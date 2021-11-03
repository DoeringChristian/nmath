/* MIT License
 * 
 * Copyright (c) 2021 DoeringChristian
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef GAMATH_H
#define GAMATH_H

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

#ifndef NM_INT
#define NM_INT int
#endif //NM_INT

#ifndef NM_MALLOC
#include <stdlib.h>
#define NM_MALLOC(_size) malloc(_size)
#endif //NM_MALLOC

#ifndef NM_FREE
#include <stdlib.h>
#define NM_FREE(_p) free(_p)
#endif //NM_FREE

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

// vecga3: {1, e1, e2, e3, e12, e13, e23, e123}

static NM_INLINE NM_FLOAT *vecga3_gprod(NM_FLOAT *dst, const NM_FLOAT *src2, const NM_FLOAT *src1){
    dst[0] =  src1[0] * src2[0] 
            + src1[1] * src2[1] 
            + src1[2] * src2[2] 
            + src1[3] * src2[3] 
            - src1[4] * src2[4]
            - src1[5] * src2[5]
            - src1[6] * src2[6]
            - src1[7] * src2[7];
    dst[1] =  src1[0] * src2[1]
            + src1[1] * src2[0]
            - src1[4] * src2[2]
            + src1[2] * src2[4]
            - src1[5] * src2[3]
            + src1[3] * src2[5]
            - src1[7] * src2[6]
            + src1[6] * src2[7];
    dst[2] =  src1[2] * src2[0]
            + src1[0] * src2[2]
            + src1[4] * src2[1]
            - src1[1] * src2[4]
            - src1[6] * src2[3]
            + src1[3] * src2[6]
            + src1[7] * src2[5]
            - src1[5] * src2[7];
    dst[3] =  src1[3] * src2[0]
            + src1[0] * src2[3]
            + src1[5] * src2[1]
            - src1[1] * src2[5]
            + src1[6] * src2[2]
            - src1[2] * src2[6]
            - src1[7] * src2[4]
            + src1[4] * src2[7];
    dst[4] =  src1[4] * src2[0]
            + src1[0] * src2[4]
            + src1[2] * src2[1]
            - src1[1] * src2[2]
            + src1[7] * src2[3]
            - src1[3] * src2[7]
            - src1[6] * src2[5]
            + src1[5] * src2[6];
    dst[5] =  src1[5] * src2[0]
            + src1[0] * src2[5]
            + src1[3] * src2[1]
            - src1[1] * src2[3]
            - src1[7] * src2[2]
            + src1[2] * src2[7]
            + src1[6] * src2[4]
            - src1[4] * src2[6];
    dst[6] =  src1[6] * src2[0]
            + src1[0] * src2[6]
            + src1[7] * src2[1]
            - src1[1] * src2[7]
            + src1[3] * src2[2]
            - src1[2] * src2[3]
            - src1[5] * src2[4]
            + src1[4] * src2[5];
    dst[7] =  src1[7] * src2[0]
            + src1[0] * src2[7]
            + src1[6] * src2[1]
            - src1[1] * src2[6]
            - src1[5] * src2[2]
            + src1[2] * src2[5]
            + src1[3] * src2[4]
            - src1[4] * src2[3];

    return dst;
}

#endif //GAMATH_H
