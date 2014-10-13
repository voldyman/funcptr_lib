#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "lib.h"

static struct DS *current_ctx;

bool register_DS(struct DS *ctx)
{
  if (ctx->init == NULL || ctx->got_data == NULL) {
    return false;
  }
  current_ctx = ctx;
  return true;
}

void lib_main_loop ()
{
  if (current_ctx == NULL) {
    return;
  } else {
    current_ctx->init();
    while(1)
    {
      printf("lib_main: new iteration\n");
      current_ctx->got_data("abc");
      sleep(1);
    }
  }
}
