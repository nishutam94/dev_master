class Myclass:
    """
    __new__ is a static method that is responsible for creating a new instance of a class.
    It is called before __init__ and is responsible for returning a new instance of the class.
    __new__ takes the class itself as its first argument, followed by any additional arguments that are passed to the class constructor.
    It is typically used when you need to control the creation of a new instance, such as when implementing singleton patterns or immutable objects.
    """


    #initialization of the object
    def __new__(cls,*args,**kargs):
        print("Object has been created")
        return super(Myclass,cls).__new__(cls)
    
    def __init__(self,data):
        print("Object has been initialize")
        self.data =  data
    

    

def main():
    ob = Myclass(1)


if __name__ ==  "__main__":
    main()
