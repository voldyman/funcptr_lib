#include <stdlib.h>
#include <stdio.h>

#include "lib.h"

void init_func()
{
  printf("Init called\n");
}

void got_data(char *name)
{
  printf("Got name: %s\n", name);
}

int main(int argc, char *argv)
{
  struct DS *ctx = (struct DS*)malloc(sizeof(struct DS));
  ctx->init = init_func;
  ctx->got_data = got_data;

  if (!register_DS(ctx)) {
    printf("could not register ctx\n");
    return 1;
  }

  lib_main_loop ();
  return 0;
}
