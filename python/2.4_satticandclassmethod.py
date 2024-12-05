"""
@staticmethod: Use it when the method does not require access to the instance or
            the class and is simply a utility function.
@classmethod: Use it when the method needs to access or modify the class state or 
            create alternative constructors (factory methods).
"""

class Myclass:
    var = "hello"
    def __init__(self,data):
        self.data = data
    
    @staticmethod
    def update():
        print("update")
    
    @classmethod
    def clsmtd(cls):
        cls.var = "bye"
        
def main():
    ob = Myclass(10)
    ob.update()
    print(ob.var)
    ob.clsmtd()
    print(ob.var)

main()



