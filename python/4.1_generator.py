"""
How Generators Work
===================
A generator function contains one or more yield statements.
When called, it returns a generator object but does not execute the function.
The function executes only when the generator's __next__() method is called (or using a for loop).
Generators are often used for tasks involving large datasets where loading everything into memory isn't feasible.

this can be called using the next() or in loop.


A generator in Python is a special type of function that produces a sequence of values, 
one at a time, using the yield statement. Unlike regular functions, generators do not return 
all the values at once but instead generate them on demand, which makes them memory-efficient.
"""

def infinite_generator():
    i = 0
    while True:
        yield i
        i=i+1

gen =  infinite_generator()

print(next(gen))
print(next(gen))
print(next(gen))
print(next(gen))

def even(numbers):
    for num in numbers:
        if num % 2 == 0:
            yield num

numbers = [i for i in range(10)]
#for _ in even(numbers):
#    print(_)
gen =  even(numbers)

print(next(gen))
print(next(gen))
print(next(gen))
print(next(gen))
print(next(gen))

