//
//  net.h
//  mtx
//
//  Created by Pavel Morozkin on 07.12.13.
//  Copyright (c) 2013 Pavel Morozkin. All rights reserved.
//

#ifndef __mtx__net__
#define __mtx__net__

#include "types.h"

extern net_t net_open(string_t ip, ui32_t port);
extern void net_close(net_t);
extern void net_send(const buf_t buf);
extern buf_t net_receive();
extern buf_t net_drive(const buf_t buf, stk_mode_t);

#endif /* defined(__mtx__net__) */