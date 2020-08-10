import numpy as np
import os
import sys
import argparse 

class student:

    def __init__(self,name,age):
        self.name = name
        self.age = age

    def print_details(self):
        print("name : ",self.name)
        print("age : ",self.age)

class teacher(student):

	def __init__(self,name,age,subject):
		student.__init__(self,name,age)
		self.subject=subject

	def print_details_subject(self):
		print("subject : ",self.subject)	

def main():
	print('inside the main program')
	parser = argparse.ArgumentParser()
	parser.add_argument('-o','--output',help='output node location',default="0")
	args=parser.parse_args()

	if args.output:
		print("output node")
	a=np.array([1,2,3,4,5])
	print(a)

	file = open("text.txt","r")
	print(file.readline())

	#s1 = student("nishant","26")
	#s1.print_details()
    
	t1=teacher("nishant","26","english")
	t1.print_details_subject()
	t1.print_details()





if __name__ == "__main__":
	main()

