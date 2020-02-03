def test():
    """Stupid test function"""
    L = []
    for i in range(10):
        print(i)
        #L.append(i)

if __name__ == '__main__':
    from timeit import Timer
    t = Timer("test()", "from __main__ import test")
    print (t.timeit())
