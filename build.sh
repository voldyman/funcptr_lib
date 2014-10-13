gcc --shared -fPIC lib.c --std=c99 -o lib.so 

gcc main.c --std=c99 lib.so -o program 

LD_LIBRARY_PATH=. ./program
