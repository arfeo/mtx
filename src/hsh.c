//
//  hsh.cpp
//  mtx
//
//  Created by Pavel Morozkin on 19.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#include "types.h"
#include "sha1.h"

buf_t hsh_sha1(buf_t b)
{
    buf_t h;
    sha1(b.data, b.size, h.data);
    h.size = 20;
    return h;
}