class person:
    def __init__(self,name,age):
        self.name  = name
        self.age = age

    def display(self):
        print(self.name)
        print(self.age) 

class student(person):
    def __init__(self,name,age,grade):
        super().__init__(name,age)
        self.grade = grade 
    
    def display(self):
        super().display()
        print(self.grade)
        

class teacher(student):
    def __init__(self,name,age,grade,subject):
        super().__init__(name,age,grade)
        self.subject = subject
    
    def display(self):
        print(self.subject)

def main():
    student1 = student("Nishant",23, "3rd")
    student1.display()
    teacher1 = teacher("Nishant",23, "3rd","maths")
    teacher1.display()

if __name__ == "__main__":
    main()    



