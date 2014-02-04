//
//  scl.c
//  mtx
//
//  Created by Pavel Morozkin on 24.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#include "api.h"
#include "types.h"
#include "setup.h"

extern scl_t scl_open()
{
    api.net.open(ip_, port_);
    api.srl.init();
    api.log.info(">> auth");
    api.srl.auth();
    api.log.info("<< key");
    scl_t s;
    return s;
}
#include <stdio.h>

extern void scl_run()
{
    api.log.info(".. new session");
    shared_rc.ssid = api.buf.rand(8);
    ui32_t q;
    api.log.info("how many pings?");
    scanf ("%d",&q);
    for (ui32_t i = 0; i < q; ++i)
    {
        printf(product);
        printf(": ping (try #%d)\n", i);
        api.srl.ping();
    }
}
extern void scl_close()
{
    net_t n = shared_rc_get_net();
    api.net.close(n);
}