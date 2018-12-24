import re 
file = open("testing.txt","r+") 
temp = file.read()
print(temp)
print("-----------------compile--------------------------")
text=re.compile('[a-e]')
print(text.findall(temp))
text=re.compile('\d+')
print(text.findall(temp))
