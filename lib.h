struct DS {
    void (*init)(void);
    void (*got_data)(char *name);
};

_Bool register_DS(struct DS *ctx);

void lib_main_loop ();
