//
//  stk.c
//  mtx
//
//  Created by Pavel Morozkin on 19.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#include "api.h"

abstract_t stk_drive(abstract_t a)
{
    buf_t s = api.sel.serialize(a);
    //api.buf.dump(s);
    buf_t s1 = api.hdl.header(s, a.type);
    //api.buf.dump(s1);
    buf_t e = api.enl.encrypt(s1, a.type);
    //api.buf.dump(e);
    buf_t t = api.trl.transport(e);
    //api.buf.dump(t);
    buf_t nr = api.net.drive(t, a.stk_mode);
    //api.buf.dump(nr);

    abstract_t ar = {};
    switch (a.stk_mode)
    {
    case SEND_RECEIVE:
        {

            buf_t tr = api.trl.detransport(nr);
            //api.buf.dump(tr);
            buf_t d = api.enl.decrypt(tr, a.type);
            //api.buf.dump(d);
            buf_t s1r = api.hdl.deheader(d, a.type);
            //api.buf.dump(s1r);
            ar = api.sel.deserialize(s1r);
        }
        break;

    case SEND:
        break;

    default:
        break;
    }
    return ar;
}