class Car:
    def __init__(self, make, model):
        self.make = make
        self.model = model

    def __str__(self):
        return f"'{self.make}', '{self.model}"

    def __repr__(self):
        return f"Car('{self.make}', '{self.model}')"

car = Car("Toyota", "Corolla")
#print(repr(car))  
print(car)# Output: Car('Toyota', 'Corolla')
print(repr(car))# Output: Car('Toyota', 'Corolla')

""" this case, str() will call __str__() and provide a user-friendly output, while repr() 
will provide a more detailed representation for debugging or development."""
