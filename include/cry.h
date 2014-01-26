//
//  cry.h
//  mtx
//
//  Created by Pavel Morozkin on 19.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#ifndef __mtx__cry__
#define __mtx__cry__

#include "types.h"

extern buf_t cry_rsa_e(buf_t b);
extern buf_t cry_aes_e(buf_t b, buf_t key, buf_t iv);
extern buf_t cry_aes_d(buf_t b, buf_t key, buf_t iv);

#endif /* defined(__mtx__cry__) */
