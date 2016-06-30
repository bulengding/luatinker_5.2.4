result = cpp_func(1, 2)

print(ONE)
print(type(ONE))
local lua_str = "zfz"
cpp_test_str(lua_str)
print(task_id)
--  next error info： attempt to perform arithmetic on global 'task_id' (a userdata value)
local zfz = task_id + 20 
print(zfz)

print(task_id == rand_id)
print(task_id == task_id2)

-- next error info: attempt to index global 'task_id2' (a userdata value)
print("task_id2: " .. task_id2)  

-- next error info: attempt to concatenate global 'task_id3'
--print("task_id3: " .. task_id3)   

print(task_id2 >= task_id3)
print("cpp_func(1,2) = "..result)

print(task_id)


function lua_func(arg1, arg2)
    return arg1 + arg2 
end



