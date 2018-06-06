//
//  buf.c
//  mtx
//
//  Created by Pavel Morozkin on 17.01.14.
//  Copyright (c) 2014 Pavel Morozkin. All rights reserved.
//

#include <stdlib.h>
#include <time.h>
#include "types.h"
#include "api.h"

buf_t buf_add(ui8_t data[], ui32_t size)
{
  if (size > max_buf_size) {
    api.log.error("can't add to buffer");
  }

  buf_t b = {};

  for (ui32_t i = 0; i < size; ++i) {
    b.data[i] = data[i];
  }

  b.size = size;

  return b;
}

buf_t buf_cat(buf_t dest, buf_t src)
{
  ui32_t s = dest.size + src.size;

  if (s > max_buf_size) {
    api.log.error("can't cat to buffer");
  }

  int offset = dest.size;

  for (ui32_t i = 0; i < src.size; ++i) {
    dest.data[i + offset] = src.data[i];
  }

  dest.size = s;

  return dest;
}

void buf_dump(buf_t b)
{
  if (b.size > max_buf_size) {
    api.log.error("Error: buf_dump: max size reached");
  } else if (!b.size) {
    api.log.error("Error: buf_dump: buffer is empty");
  }

  api.log.hex(b.data, b.size);
}

ui8_t buf_cmp(buf_t a, buf_t b)
{
  if (a.size != b.size) {
    api.log.error("Error: buf_cmp: different sizes");
  }

  for (ui32_t i = 0; i < a.size; ++i) {
    if (a.data[i] != b.data[i]) {
      return 0;
    }
  }

  return 1;
}

buf_t buf_swap(buf_t b)
{
  unsigned char * lo = (unsigned char *)b.data;
  unsigned char * hi = (unsigned char *)b.data + b.size - 1;
  unsigned char swap;

  while (lo < hi) {
    swap = *lo;
    *lo++ = *hi;
    *hi-- = swap;
  }

  return b;
}

buf_t buf_add_ui32(ui32_t v)
{
  return api.buf.add((ui8_t *)&v, 4);
}

buf_t buf_add_ui64(ui64_t v)
{
  return api.buf.add((ui8_t *)&v, 8);
}

ui32_t buf_get_ui32(buf_t b)
{
  return *(ui32_t *)b.data;
}

ui64_t buf_get_ui64(buf_t b)
{
  return *(ui64_t *)b.data;
}

buf_t buf_rand(ui32_t s)
{
  buf_t b = {};

  srand((unsigned int)time(NULL));

  for (ui32_t i = 0; i < s; i++) {
    b.data[i] = rand() % 256;
  }

  b.size = s;

  return b;
}

buf_t buf_xor(buf_t a, buf_t b)
{
  if (a.size != b.size) {
    api.log.error("Error: buf_cmp: different sizes");
  }

  buf_t r;

  for (ui32_t i = 0; i < a.size; ++i) {
    r.data[i] = a.data[i] ^ b.data[i];
  }

  r.size = a.size;
  
  return r;
}
