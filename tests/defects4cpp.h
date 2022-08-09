#include <lua5.3/lualib.h>
#include <lua5.3/lauxlib.h>

static int defects4cpp_test_index() {
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  luaL_dofile(L, "tests/defects4cpp.lua");
  int ret = lua_tonumber(L, -1);
  lua_close(L);
  return ret;
}
