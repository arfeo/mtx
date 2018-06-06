//
//  macro.h
//  mtx
//
//  Created by Pavel Morozkin on 18.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#ifndef mtx_macro_h
#define mtx_macro_h

#define METHOD(N,R,...) R(*N)(__VA_ARGS__);
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

#endif
