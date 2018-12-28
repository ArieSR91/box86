#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "debug.h"
#include "wrapper.h"
#include "bridge.h"
#include "library_private.h"
#include "x86emu_private.h"

int my_snd_async_add_handler(x86emu_t *emu, void *handler, int fd, void* callback, void *private_data);
int my_snd_async_add_pcm_handler(x86emu_t *emu, void *handler, void *pcm,  void* callback, void *private_data);
void* my_snd_async_handler_get_callback_private(x86emu_t *emu, void *handler);
int my_snd_lib_error_set_handler(x86emu_t *emu, void* handler);

int wrappedlibasound_init(library_t* lib)
{
    lib->priv.w.lib = dlopen("libasound.so.2", RTLD_NOW);
    if(!lib->priv.w.lib) {
        return -1;
    }
    lib->priv.w.bridge = NewBridge();
    return 0;
}
void wrappedlibasound_fini(library_t* lib)
{
    if(lib->priv.w.lib)
        dlclose(lib->priv.w.lib);
    lib->priv.w.lib = NULL;
    FreeBridge(&lib->priv.w.bridge);
}
int wrappedlibasound_get(library_t* lib, const char* name, uintptr_t *offs, uint32_t *sz)
{
    uintptr_t addr = 0;
    uint32_t size = 0;
    void* symbol = NULL;

#include "wrappedlib_defines.h"
#include "wrappedlibasound_private.h"
#include "wrappedlib_undefs.h"

    if(!addr)
        return 0;
    *offs = addr;
    *sz = size;
    return 1;
}


// Implementation
//typedef void(* 	snd_async_callback_t )(snd_async_handler_t *handler)
/*
typedef void (* snd_lib_error_handler_t)(
    const char *file,
    int line,
    const char *function,
    int err,
    const char *fmt,
    ...
    )
*/
// error handler is a function pointer with a ... !
int my_snd_async_add_handler(x86emu_t *emu, void *handler, int fd, void* callback, void *private_data)
{
    //snd_async_add_handler(snd_async_handler_t **handler, int fd, snd_async_callback_t callback, void *private_data);
    printf_log(LOG_NONE, "Error: snd_async_add_handler not implemented\n");
    emu->quit = 1;
    return -1;
}

int my_snd_async_add_pcm_handler(x86emu_t *emu, void *handler, void* pcm,  void* callback, void *private_data)
{
    //snd_async_add_pcm_handler(snd_async_handler_t **handler, snd_pcm_t *pcm,  snd_async_callback_t callback, void *private_data)
    printf_log(LOG_NONE, "Error: snd_async_add_pcm_handler not implemented\n");
    emu->quit = 1;
    return -1;

}

void* my_snd_async_handler_get_callback_private(x86emu_t* emu, void* handler)
{
    //snd_async_handler_get_callback_private(snd_async_handler_t *handler)
    printf_log(LOG_NONE, "Error: snd_async_handler_get_callback_private not implemented\n");
    emu->quit = 1;
    return NULL;
}

int my_snd_lib_error_set_handler(x86emu_t* emu, void* handler)
{
    //snd_lib_error_set_handler(snd_lib_error_handler_t handler)
    printf_log(LOG_NONE, "Error: snd_lib_error_set_handler not implemented\n");
    emu->quit = 1;
    return -1;
}
