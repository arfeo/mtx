//
//  cmn.h
//  mtx
//
//  Created by Pavel Morozkin on 18.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#ifndef __mtx__cmn__
#define __mtx__cmn__

#include "types.h"

extern void cmn_fact(ui64_t pq, ui32_t * p, ui32_t * q);
extern buf_t cmn_pow_mod(buf_t g, buf_t e, buf_t m);

#endif /* defined(__mtx__cmn__) */
