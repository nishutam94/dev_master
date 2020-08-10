import os
from argparse import ArgumentParser
import pandas as pd
def summary(path,file):
	f = open(path + file, "r")
	lines = f.readlines()
	sum_total=0
	no_of_sum=0
	else_wise_total=0
	no_of_else_wise=0
	concat_total=0
	no_of_concat=0
	for line in lines:
		words = line.split(',')   
		if words[0]=="mkldnn_verbose" and words[1]=="exec":
			if words[2]=="sum":
				sum_total=sum_total+float(words[8])
				no_of_sum=no_of_sum+1
			if words[2]=="eltwise":
				else_wise_total=else_wise_total+float(words[8])
				no_of_else_wise=no_of_else_wise+1	
			if words[2]=="concat":
				concat_total=concat_total+float(words[8])
				no_of_concat=no_of_concat+1	
    
	print(file)
	print("")  
	data={
	"operation" : ["sum","eltwise","concat"],
	"Total_Time" : [sum_total,else_wise_total,concat_total], 
	"No of operation" : [no_of_sum,no_of_else_wise,no_of_concat,] ,
	"Avarage":[sum_total/no_of_sum,else_wise_total/no_of_else_wise,concat_total/no_of_concat]
	}
	df = pd.DataFrame(data,columns=["operation","Total_Time","No of operation","Avarage"])
	f.close() 
	return df 

def main():
	parser = ArgumentParser()
	parser.add_argument("-p", "--path", help="Specify Path of logs",default="/root/nishant/snap/verbosemkldnn/")
	args = parser.parse_args()
	path = args.path
	filelist = os.listdir(path)
	df = pd.DataFrame()
	with pd.ExcelWriter(path+'output.xlsx') as writer:
		df.to_excel(writer)
	print("\n==================================== summary =========================================================")
	for file in filelist:
		if file.endswith('.txt'):
			df_return=summary(path,file)
			print(df_return)
			with pd.ExcelWriter(path+'output.xlsx',mode='a') as writer:  
				df_return.to_excel(writer, sheet_name=file)	

if __name__ == "__main__":
	main()