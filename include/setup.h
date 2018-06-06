//
//  setup.h
//  mtx
//
//  Created by Pavel Morozkin on 17.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#ifndef mtx_setup_h
#define mtx_setup_h

#define product             "mtx"
#define version_            "0.1"

#define ip_                 "149.154.167.40"
#define port_               443

#define api_id_             0
#define api_hash_           ""
#define lang_code_          "ru"

#define public_key          "pub.pkcs"

enum settings_atomic_operations
{
  max_buf_size              = 800,
};

enum settings_tgt
{
  max_param_size            = 12,
  max_abstract_params       = 12,
  max_container_size        = 8,
};

enum settings_id_codes
{
  id_resPQ                  = 0x05162463,
  id_Vector                 = 0x1cb5c415,
  id_Server_DH_Params_ok    = 0xd0e8075c,
  id_server_DH_inner_data   = 0xb5890dba,
  id_dh_gen_ok              = 0x3bcbf734,
  id_msg_container          = 0x73f1f8dc,
  id_new_session_created    = 0x9ec20908,
  id_pong                   = 0x347773c5,
  id_bad_msg_notification   = 0xa7eff811,
};

#endif
