def example_function(*args, **kwargs):
    print("Positional arguments:", args)
    print("Keyword arguments:", kwargs)

example_function( 1,2,3,a=4, b=5)


def example2(*args):
    return args

print(example2(1,2,3,4,5,6))

def example3(**kargs):
    return kargs

print(example3(q=2,t=3))

