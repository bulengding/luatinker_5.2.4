#include "lua_tinker.h"
#include <stdint.h>

#pragma comment(lib, "lua_lib.lib")

int main()
{
    lua_State* L = luaL_newstate();

    luaL_openlibs(L);

    // ����table haha
    lua_tinker::table haha(L, "haha");

    // ������ֵ
    haha.set("value", 1);

    // ����table
    haha.set("inside", lua_tinker::table(L));

    // ��ȡinside
    lua_tinker::table inside = haha.get<lua_tinker::table>("inside");

    // ������ֵ
    inside.set("value", (uint64_t)2);

    // ���нű�
    lua_tinker::dofile(L, "sample4.lua");

    // ��lua��ȡ����
    const char* test = haha.get<const char*>("test");
    printf("haha.test = %s\n", test);

    lua_tinker::table from_lua_table(L, "lua_table");
    printf("lua_table[2] = %d\n", from_lua_table.get<int>(4));

    // ����lua����
    lua_tinker::call<void>(L, "print_table", from_lua_table);

    // �½�һ�����
    lua_tinker::table temp(L);

    // ����ֵ
    temp.set("name", "local table !!");

    // ����lua����
    lua_tinker::call<void>(L, "print_table", temp);

    // ����lua����
    lua_tinker::table ret = lua_tinker::call<lua_tinker::table>(L, "return_table", "give me a table !!");
    printf("ret.name =\t%s\n", ret.get<const char*>("name"));

    lua_close(L);

    return 0;
}

