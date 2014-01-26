//
//  enl.h
//  mtx
//
//  Created by Pavel Morozkin on 18.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#ifndef __mtx__enl__
#define __mtx__enl__

#include "types.h"

extern buf_t enl_encrypt(buf_t, msg_t);
extern buf_t enl_decrypt(buf_t, msg_t);

typedef enum get_params_mode_
{
    MODE_C2S,
    MODE_S2C
} get_params_mode_t;

typedef struct aes_params_
{
    buf_t aes_key;
    buf_t aes_iv;
} aes_params_t;

extern aes_params_t enl_get_params(buf_t, buf_t, get_params_mode_t);

#endif /* defined(__mtx__enl__) */
