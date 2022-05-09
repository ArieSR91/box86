#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "wrapper.h"
#include "bridge.h"
#include "librarian/library_private.h"
#include "x86emu.h"

const char* libxpmName = "libXpm.so.4";
#define LIBNAME libxpm

#define CUSTOM_INIT \
    setNeededLibs(lib, 2, "libX11.so.6", "libXext.so.6");

#include "wrappedlib_init.h"