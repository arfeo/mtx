//
//  srl.h
//  mtx
//
//  Created by Pavel Morozkin on 17.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#ifndef __mtx__srl__
#define __mtx__srl__

#include "types.h"

extern srl_t srl_init();
extern srl_t srl_auth();
extern buf_t srl_ping();

#endif /* defined(__mtx__srl__) */