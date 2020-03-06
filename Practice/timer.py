import time

def test():
    """Stupid test function"""
    L=[]
    for i in range(1000000):
        print(i)
        L.append(i)

def main():
    start_time = time.time()
    test()
    print("--- %s seconds ---" % (time.time() - start_time))

if __name__ == '__main__':
    main()

