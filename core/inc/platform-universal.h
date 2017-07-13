#pragma once

#if defined(_WIN32) || defined(WIN32)
#include "platform-win.h"
using OSPlatform = platform_win;
#else
# include "platform-linux.h"
using OSPlatform = platform_linux;
#endif