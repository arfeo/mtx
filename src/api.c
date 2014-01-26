//
//  api.c
//  mtx
//
//  Created by Pavel Morozkin on 17.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#include "api.h"
#include "net.h"
#include "std.h"
#include "buf.h"
#include "app.h"
#include "log.h"
#include "crc.h"
#include "trl.h"
#include "rfc.h"
#include "srl.h"
#include "cmn.h"
#include "sel.h"
#include "enl.h"
#include "tml.h"
#include "hsh.h"
#include "cry.h"
#include "stk.h"
#include "sil.h"
#include "scl.h"
#include "hdl.h"

#ifdef __GNUC__
const api_t api =
{
    .std =
    {
        .time =      std_time
    },
    .net =
    {
        .open =      net_open,
        .close =     net_close,
        .drive =     net_drive
    },
    .buf =
    {
        .add =       buf_add,
        .cat =       buf_cat,
        .dump =      buf_dump,
        .cmp =       buf_cmp,
        .swap =      buf_swap,
        .add_ui32 =  buf_add_ui32,
        .add_ui64 =  buf_add_ui64,
        .get_ui32 =  buf_get_ui32,
        .get_ui64 =  buf_get_ui64,
        .rand =      buf_rand,
        .xor =       buf_xor
    },
    .app =
    {
        .open =      app_open,
        .run =       app_run,
        .close =     app_close
    },
    .log =
    {
        .info =      log_info,
        .error =     log_error,
        .debug =     log_debug,
        .assert =    log_assert,
        .hex =       log_hex
    },
    .crc =
    {
        .crc32 =     crc_crc32
    },
    .trl =
    {
        .init =       trl_init,
        .transport =  trl_transport,
        .detransport = trl_detransport
    },
    .rfc =
    {
        .init =                 rfc_init
    },
    .srl =
    {
        .init =       srl_init,
        .auth =       srl_auth,
        .ping =       srl_ping
    },
    .cmn =
    {
        .fact =         cmn_fact,
        .pow_mod =      cmn_pow_mod
    },
    .sel =
    {
        .init =        sel_init,
        .serialize_id = sel_serialize_id,
        .serialize_param = sel_serialize_param,
        .deserialize_param = sel_deserialize_param,
        .serialize_string = sel_serialize_string,
        .deserialize_string = sel_deserialize_string,
        .serialize =   sel_serialize,
        .deserialize = sel_deserialize,
        .deserialize_vector = sel_deserialize_vector
    },
    .enl =
    {
        .encrypt =   enl_encrypt,
        .decrypt =   enl_decrypt
    },
    .tml = &tml_api,
    .hsh =
    {
        .sha1 =     hsh_sha1
    },
    .cry =
    {
        .rsa_e =     cry_rsa_e,
        .aes_e =     cry_aes_e,
        .aes_d =     cry_aes_d
    },
    .stk =
    {
        .drive =     stk_drive
    },
    .sil =
    {
        .abstract =     sil_abstract,
        .concrete =     sil_concrete
    },
    .scl =
    {
        .open =     scl_open,
        .run =      scl_run,
        .close =    scl_close
    },
    .hdl =
    {

        .header =   hdl_header,
        .deheader = hdl_deheader
    }
};
#elif defined _MSC_VER
api_t api =
{
    {},

    {
        net_open,
        net_close,
        net_drive
    },

    {
        buf_add,
        buf_cat,
        buf_dump,
        buf_cmp,
        buf_swap,
        buf_add_ui32,
        buf_add_ui64,
        buf_get_ui32,
        buf_get_ui64
    },

    {
        app_init,
        app_run
    },

    {
        log_info,
        log_error,
        log_debug,
        log_assert,
        log_hex
    },

    {
        crc_crc32
    },

    {
        trl_init,
        trl_transport,
        trl_detransport
    },

    {
        rfc_init
    },

    {
        srl_init,
        srl_auth,
        srl_ping
    },

    {
        cmn_rand_array,
        cmn_fact,
        cmn_pow_mod
    },

    {
        sel_init,
        sel_serialize,
        sel_deserialize,
        sel_serialize_id,
        sel_serialize_param,
        sel_deserialize_param,
        sel_serialize_string,
        sel_deserialize_string,
        sel_serialize_,
        sel_deserialize_,
        sel_deserialize_vector
    },

    {
        enl_encrypt,
        enl_decrypt
    },
    &tml_api,

    {
        hsh_sha1
    },

    {
        cry_rsa_e,
        cry_aes_e,
        cry_aes_d
    },

    {
        stk_drive
    },

    {
        sil_abstract,
        sil_concrete
    }
};
#else
#error Do not now how to initialize api
#endif
