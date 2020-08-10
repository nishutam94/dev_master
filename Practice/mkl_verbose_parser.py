import os
import re
from argparse import ArgumentParser
import pandas as pd
def summary(path,file):
	f = open(path + file, "r")
	lines = f.readlines()
	count=0
	for line in lines:
		words = line.split(' ')   
		word_list=[]

		if words[0]=="MKL_VERBOSE" and words[3]=="CNR:OFF":

			if words[2][-2:]=="ms":
				temp=str(words[2][:-2])
				time=float(temp)
				time=time*1000
			if words[2][-2:]=="us":
				temp=str(words[2][:-2])
				time=float(temp)
				#print(time)	

			word=words[1].split(',')
			word.append(time)
			#print(word)
			word_list.append(word[2])
			word_list.append(word[3])
			word_list.append(word[4])
			word_list.append(time)
			if count%12==0:
				print(word_list)
		count=count+1
	print(count)
def main():
	parser = ArgumentParser()
	parser.add_argument("-p", "--path", help="Specify Path of logs",default="/root/nishant/snap/versbosemkl/")
	args = parser.parse_args()
	path = args.path
	filelist = os.listdir(path)
	df = pd.DataFrame()
	with pd.ExcelWriter(path+'output.xlsx') as writer:
		df.to_excel(writer)
	print("\n==================================== summary =========================================================")
	for file in filelist:
		if file.endswith('.txt'):
			summary(path,file)
			"""
			print(df_return)
			with pd.ExcelWriter(path+'output.xlsx',mode='a') as writer:  
				df_return.to_excel(writer, sheet_name=file)	
			"""
if __name__ == "__main__":
	main()


"""
['256', '2000', '845', 2620.0]
['128', '2000', '256', 485.41]
['64', '2000', '128', 146.08]
['1', '2000', '64', 14.36]
['1', '64', '2000', 26.51]
['64', '2000', '1', 48.2]
['64', '128', '2000', 192.07]
['128', '2000', '64', 143.01]
['128', '256', '2000', 561.04]
['256', '2000', '128', 523.33]
['845', '2000', '256', 3090.0]
['256', '845', '2000', 3110.0]
1"""