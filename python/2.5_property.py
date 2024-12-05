class MyClass:
    def __init__(self, value):
        self._value = value

    @property
    def value(self):
        return self._value

    @value.setter
    def value(self, new_value):
        if new_value >= 0:
            self._value = new_value
        else:
            raise ValueError("Value must be non-negative")

obj = MyClass(10)
print(obj.value)  # Output: 10
obj.value = 20
print(obj.value)  # Output: 20
obj.value = -5  # Raises ValueError: Value must be non-negative