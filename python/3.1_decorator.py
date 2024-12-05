import time

"""
A decorator is a function that takes another function as an argument, adds some kind of functionality, 
and returns another function. 
This is helpful to "decorate" or "wrap" another function.
"""


def decorator(function):
    def wrapper(*args,**kargs):
        time1 = time.time()
        result=function(*args,**kargs)
        time2 = time.time()
        result = time2-time1
        print(function.__name__,"Execution time is",time2-time1)
        return result 
    return wrapper


@decorator
def timing(n):
    count = 1
    for i in range(n):
        count = count+count
    return count


@decorator
def timing2(n):
    count = 1
    while n :
        count = count+count
        n = n - 1
    return count

timing(10)
timing2(10)