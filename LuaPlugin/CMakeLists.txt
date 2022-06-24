set(LuaCore
	"src/lapi.c"
	"src/lcode.c"
	"src/lctype.c"
	"src/ldebug.c"
	"src/ldo.c"
	"src/ldump.c"
	"src/lfunc.c"
	"src/lgc.c"
	"src/llex.c"
	"src/lmem.c"
	"src/lobject.c"
	"src/lopcodes.c"
	"src/lparser.c"
	"src/lstate.c"
	"src/lstring.c"
	"src/ltable.c"
	"src/ltm.c"
	"src/lundump.c"
	"src/lvm.c"
	"src/lzio.c"

	"src/lapi.h"
	"src/lcode.h"
	"src/lctype.h"
	"src/ldebug.h"
	"src/ldo.h"
	"src/lfunc.h"
	"src/lgc.h"
	"src/ljumptab.h"
	"src/llex.h"
	"src/llimits.h"
	"src/lmem.h"
	"src/lobject.h"
	"src/lopcodes.h"
	"src/lopnames.h"
	"src/lparser.h"
	"src/lprefix.h"
	"src/lstate.h"
	"src/lstring.h"
	"src/ltable.h"
	"src/ltm.h"
	"src/lundump.h"
	"src/lvm.h"
	"src/lzio.h"
)

set(LuaLibraries
	"src/lauxlib.c"
	"src/lbaselib.c"
	"src/lcorolib.c"
	"src/ldblib.c"
	"src/liolib.c"
	"src/lmathlib.c"
	"src/loadlib.c"
	"src/loslib.c"
	"src/lstrlib.c"
	"src/ltablib.c"
	"src/lutf8lib.c"
	"src/linit.c"
)

set(LuaInterpreter
	"src/lua.c"
)

set(LuaCompiler
	"src/luac.c"
)

add_library(LibLua STATIC ${LuaCore} ${LuaLibraries} )
target_include_directories(LibLua PUBLIC "include")