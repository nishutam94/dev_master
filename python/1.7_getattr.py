class MyClass:
    def __init__(self):
        self.existing_attr = "I exist"

    def __getattribute__(self, name):
        print(f"Accessing attribute: {name}")
        return super().__getattribute__(name)

    def __getattr__(self, name):
        return f"{name} attribute not found"

obj = MyClass()
print(obj.existing_attr)                   
print(obj.non_existing_attr)  
                             