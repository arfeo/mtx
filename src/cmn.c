//
//  cmn.c
//  mtx
//
//  Created by Pavel Morozkin on 18.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#include "fact.h"
#include "api.h"
#include "rsa.h"

void cmn_fact(ui64_t pq, ui32_t* p, ui32_t* q)
{
    factor(pq, p, q);
}
buf_t cmn_pow_mod(buf_t g, buf_t e, buf_t m)
{
    if (e.size != m.size || e.size != 256 || e.size != 256)
        api.log.error("can't pow_mod");

    buf_t r;
    int l = pow_mod(r.data, g.data, g.size, e.data, e.size, m.data, m.size);

    if (!l)
        api.log.error("pow_mod failed");

    r.size = l;
    return r;
}