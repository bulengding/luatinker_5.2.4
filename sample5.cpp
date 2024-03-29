#include "lua_tinker.h"

#pragma comment(lib, "lua_lib.lib")

void show_error(const char* error)
{
    printf("_ALERT -> %s\n", error);
}

int main()
{
    lua_State* L = luaL_newstate();

    luaopen_base(L);

    printf("%s\n","-------------------------- current stack");
    lua_tinker::enum_stack(L);

    lua_pushnumber(L, 1);

    printf("%s\n","-------------------------- stack after push '1'");
    lua_tinker::enum_stack(L);

    lua_tinker::dofile(L, "sample5.lua");

    printf("%s\n","-------------------------- calling test_error()");
    lua_tinker::call<void>(L, "test_error");

    printf("%s\n","-------------------------- calling test_error_3()");
    lua_tinker::call<void>(L, "test_error_3");

    lua_tinker::def(L, "_ALERT", show_error);

    lua_tinker::call<void>(L, "_ALERT", "test !!!");

    printf("%s\n","-------------------------- calling test_error()");
    lua_tinker::call<void>(L, "test_error");


    lua_close(L);

    return 0;
}

