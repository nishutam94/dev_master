from memory_profiler import profile

@profile
def my_function():
    my_list = [i for i in range(100000)]
    return my_list
my_function()