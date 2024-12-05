from functools import reduce
list1 = [i for i in range(10)]

square=lambda i : i * i
for i in list1:
    print(square(i))


add =  lambda x,y : x+y
for i in list1:
    print(add(i,i+1))



lonlist1 =  lambda list1  : [i*i for i in list1]
print(lonlist1)



ans = map(lambda x:x*x,list1)

print(list(ans))

numbers = [1, 2, 3, 4]
squared = map(lambda x: x ** 2, numbers)
print(list(squared))  # Output: [1, 4, 9, 16]


ans = filter(lambda x: x%2==0 ,list1)
print(list(ans))


people = [("Alice", 30), ("Bob", 25), ("Charlie", 35), ("Diana", 28)]
ans = sorted(people,key=lambda x:x[1])
print(ans)


number = [i for i in range(97,119)]
def function(i):
    return [i,chr(i)]
ans=map(function,number)
print(list(ans))


# Filter even numbers
even_numbers = filter(lambda x: x % 2 == 0, numbers) # works with functions return true or false
print(list(even_numbers))  # Output: [2, 4, 6]

# Square each number
squared_numbers = map(lambda x: x * x, numbers) #works with functions 
print(list(squared_numbers))  # Output: [1, 4, 9, 16, 25, 36]

# Sum of all numbers
sum_of_numbers = reduce(lambda x, y: x + y, numbers)   #works on clumulative
print(sum_of_numbers)  # Output: 21