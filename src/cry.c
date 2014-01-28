//
//  cry.c
//  mtx
//
//  Created by Pavel Morozkin on 19.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#include "api.h"
#include "rsa.h"
#include "aes.h"

buf_t cry_rsa_e(buf_t b)
{
    buf_t r = {};
    r.size = 256;
    rsa(b.data, b.size, r.data, r.size);
    return r;
}
buf_t cry_aes_e(buf_t b, buf_t key, buf_t iv)
{
    buf_t r = {};
    int l = aes_e(b.data, r.data, b.size, key.data, iv.data);

    if (!l)
        api.log.error("error during aes encryption");

    r.size = l;
    return r;
}
buf_t cry_aes_d(buf_t b, buf_t key, buf_t iv)
{
    buf_t r = {};
    int l = aes_d(b.data, r.data, b.size, key.data, iv.data);

    if (!l)
        api.log.error("error during aes decryption");

    r.size = l;
    return r;
}
