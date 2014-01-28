//
//  main.c
//  mtx
//
//  Created by Pavel Morozkin on 17.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//
#include "api.h"

// srl -- service layer
// trl -- transport layer
// sel -- serialization layer
// enl -- encrypt layer
// tml -- tg methods layer
// tgt -- tg types
// stk -- stack
// sil -- simple interm. layer
// scl -- stel client layer
// hdl -- header def. layer

int main()
{
    api.log.info("hi dear");
    app_t app;
    app = api.app.open();
    api.app.run(app);
    api.log.info("bye bye");
    return api.app.close(app);
}