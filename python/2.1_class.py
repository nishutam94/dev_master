class baseclass:
    def __init__(self,name):
        self.name = name
    def display(self):
        print(self.name)

def main():
    base = baseclass("Nishant")
    base.display()

if __name__ == "__main__":
    main()