//
//  buf.h
//  mtx
//
//  Created by Pavel Morozkin on 17.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#ifndef mtx_buf_h
#define mtx_buf_h

#include "types.h"

extern buf_t buf_add(ui8_t data[], ui32_t size);
extern buf_t buf_cat(buf_t dest, buf_t src);
extern void buf_dump(buf_t);
extern ui8_t buf_cmp(buf_t, buf_t);
extern buf_t buf_swap(buf_t);
extern buf_t buf_add_ui32(ui32_t);
extern buf_t buf_add_ui64(ui64_t);
extern ui32_t buf_get_ui32(buf_t);
extern ui64_t buf_get_ui64(buf_t);
extern buf_t buf_rand(ui32_t s);
extern buf_t buf_xor(buf_t, buf_t);

#endif
