//
//  api.h
//  mtx
//
//  Created by Pavel Morozkin on 17.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#ifndef mtx_api_h
#define mtx_api_h

#include "macro.h"
#include "types.h"
#include "tml.h"

typedef struct std_api_
{
  METHOD(time, ui32_t);
} std_api_t;

typedef struct net_api_
{
  METHOD(open, net_t, string_t ip, ui32_t port);
  METHOD(close, void, const net_t);
  METHOD(drive, buf_t, buf_t, stk_mode_t);
} net_api_t;

typedef struct buf_api_
{
  METHOD(add, buf_t, ui8_t *, ui32_t);
  METHOD(cat, buf_t, buf_t, buf_t);
  METHOD(dump, void, buf_t);
  METHOD(cmp, ui8_t, buf_t, buf_t);
  METHOD(swap, buf_t, buf_t);
  METHOD(add_ui32, buf_t, ui32_t);
  METHOD(add_ui64, buf_t, ui64_t);
  METHOD(get_ui32, ui32_t, buf_t);
  METHOD(get_ui64, ui64_t, buf_t);
  METHOD(rand, buf_t, ui32_t);
  METHOD(xor, buf_t, buf_t, buf_t);
} buf_api_t;

typedef struct app_api_
{
  METHOD(open, app_t);
  METHOD(run, ui8_t, app_t);
  METHOD(close, ui8_t, app_t);
} app_api_t;

typedef struct log_api_
{
  void (*info)(string_t, ...);
  void (*error)(string_t);
  void (*debug)();
  void (*assert)();
  METHOD(hex, void, array_t, ui32_t);
} log_api_t;

typedef struct crc_api_
{
  buf_t(*crc32)(const buf_t);
} crc_api_t;

typedef struct trl_api_
{
  METHOD(init, trl_t);
  METHOD(transport, buf_t, buf_t);
  METHOD(detransport, buf_t, buf_t);
} trl_api_t;

typedef struct rfc_api_
{
  METHOD(init, rfc_t, sel_t);
} rfc_api_t;

typedef struct srl_api_
{
  METHOD(init, srl_t);
  METHOD(auth, srl_t);
  METHOD(ping, buf_t);
} srl_api_t;

typedef struct cmn_api_
{
  METHOD(fact, void, ui64_t, ui32_t *, ui32_t *);
  METHOD(pow_mod, buf_t, buf_t, buf_t, buf_t);
} cmn_api_t;

typedef struct sel_api_
{
  METHOD(init, sel_t, trl_t);
  METHOD(serialize_id, buf_t, buf_t);
  METHOD(serialize_param, buf_t, param_t);
  METHOD(deserialize_param, param_t, param_t);
  METHOD(serialize_string, buf_t, buf_t);
  METHOD(deserialize_string, buf_t, buf_t);
  METHOD(serialize, buf_t, abstract_t);
  METHOD(deserialize, abstract_t, buf_t);
  METHOD(deserialize_vector, buf_t, param_t);
} sel_api_t;

typedef struct enl_api_
{
  METHOD(encrypt, buf_t, buf_t, msg_t);
  METHOD(decrypt, buf_t, buf_t, msg_t);
} enl_api_t;

typedef struct hsh_api_
{
  METHOD(sha1, buf_t, buf_t);
} hsh_api_t;

typedef struct cry_api_
{
  METHOD(rsa_e, buf_t, buf_t);
  METHOD(aes_e, buf_t, buf_t, buf_t, buf_t);
  METHOD(aes_d, buf_t, buf_t, buf_t, buf_t);
} cry_api_t;

typedef struct stk_api_
{
  METHOD(drive, abstract_t, abstract_t);
} stk_api_t;

typedef struct sil_api_
{
  METHOD(abstract, abstract_t, tg_api_type_system_t);
  METHOD(concrete, tg_api_type_system_t, abstract_t);
} sil_api_t;

typedef struct scl_api_
{
  METHOD(open, scl_t);
  METHOD(run, void, void);
  METHOD(close, void, void);
} scl_api_t;

typedef struct hdl_api_
{
  METHOD(header, buf_t, buf_t, msg_t);
  METHOD(deheader, buf_t, buf_t, msg_t);
} hdl_api_t;

typedef struct api_
{
  std_api_t       std;
  net_api_t       net;
  buf_api_t       buf;
  app_api_t       app;
  log_api_t       log;
  crc_api_t       crc;
  trl_api_t       trl;
  rfc_api_t       rfc;
  srl_api_t       srl;
  cmn_api_t       cmn;
  sel_api_t       sel;
  enl_api_t       enl;
  tml_api_t   *   tml;
  hsh_api_t       hsh;
  cry_api_t       cry;
  stk_api_t       stk;
  sil_api_t       sil;
  scl_api_t       scl;
  hdl_api_t       hdl;
} api_t;

extern api_t api;

#endif
