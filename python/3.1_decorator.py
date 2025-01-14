import time

"""
A decorator is a function that takes another function as an argument, adds some kind of functionality, 
and returns another function. 
This is helpful to "decorate" or "wrap" another function.
"""


def decorator(function):
    def wrapper():
        time1 = time.time()
        result=function()
        time2 = time.time()
        result = time2-time1
        print(function.__name__,"Execution time is",time2-time1)
        
    return wrapper


@decorator
def timing():
    count = 1
    for i in range(10):
        count = count+count
    return count


@decorator
def timing2():
    count = 1
    n=10
    while n :
        count = count+count
        n = n - 1
    return count

timing()
timing2()