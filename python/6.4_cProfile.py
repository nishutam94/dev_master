import cProfile
def my_function():
    for i in range(1000000000000000000000000000000000000000000000000000000000000000000000000000000):
        print(i)
    return 
cProfile.run('my_function')