#arr = [1,3,4,2]
arr = [1,4,6,7,3,7,8,1]

def nearest_smallest_element_from_left(arr):
    stack = []
    ls = []
    n = len(arr)
    for i in range(n):
        while stack and stack[-1]>=arr[i]:
            stack.pop()

        if stack:
            ls.append(stack[-1])
        else:
            ls.append(-1)
        
        stack.append(arr[i])
    return ls

def nearest_smallest_element_from_right(arr):
    stack = []
    ls = []
    n = len(arr)
    for i in range(n-1,-1,-1):
        while stack and stack[-1]>=arr[i]:
            stack.pop()

        if stack:
            ls.append(stack[-1])
        else:
            ls.append(-1)
        
        stack.append(arr[i])
    return ls[::-1]


def nearest_smallest_element_from_left_index(arr):
    stack = []
    ls = []
    n = len(arr)
    for i in range(n):
        while stack and stack[-1][0]>=arr[i]:
            stack.pop()

        if stack:
            ls.append(stack[-1][1])
        else:
            ls.append(-1)
        
        stack.append([arr[i],i])
    return ls

def nearest_smallest_element_from_right_index(arr):
    stack = []
    ls = []
    n = len(arr)
    for i in range(n-1,-1,-1):
        while stack and stack[-1][0]>=arr[i]:
            stack.pop()

        if stack:
            ls.append(stack[-1][1])
        else:
            ls.append(n)
        
        stack.append([arr[i],i])
    return ls[::-1]


def nearest_greater_element_from_left(arr):
    stack = []
    ls = []
    n = len(arr)
    for i in range(n):
        while stack and stack[-1]<=arr[i]:
            stack.pop()

        if stack:
            ls.append(stack[-1])
        else:
            ls.append(-1)
        
        stack.append(arr[i])
    return ls

def nearest_greater_element_from_right(arr):
    stack = []
    ls = []
    n = len(arr)
    for i in range(n-1,-1,-1):
        while stack and stack[-1]<=arr[i]:
            stack.pop()

        if stack:
            ls.append(stack[-1])
        else:
            ls.append(-1)
        
        stack.append(arr[i])
    return ls[::-1]

def nearest_greater_element_from_right_index(arr):
    stack = []
    ls = []
    n = len(arr)
    for i in range(n-1,-1,-1):
        while stack and stack[-1][0]<=arr[i]:
            stack.pop()

        if stack:
            ls.append(stack[-1][1])
        else:
            ls.append(-1)
        
        stack.append([arr[i],i])
    return ls[::-1]

def nearest_greater_element_from_right_count(arr):
    ls = []
    nger=nearest_greater_element_from_right_index(arr)
    for i in range(len(arr)):
        ls.append(i-nger[i])
    return ls 

def nearest_smallest_element_from_count_subarray(arr):
    left = []
    right = []
    multiple = []
    pse = nearest_smallest_element_from_left_index(arr)
    nse = nearest_smallest_element_from_right_index(arr)
    
    for  i in range(len(arr)):
        left.append(i-pse[i])
        right.append(nse[i]-i)
        multiple.append((nse[i]-i)*(i-pse[i]))

    print(left)
    print(right)
    print(multiple)


print(arr)   
#print('nearest_greater_element_from_right: ',nearest_greater_element_from_right(arr))
#print('nearest_greater_element_from_right_index: ',nearest_greater_element_from_right_index(arr))
#print('nearest_greater_element_from_right_count: ',nearest_greater_element_from_right_count(arr))
#print('nearest_greater_element_from_left: ',nearest_greater_element_from_left(arr))
print('nearest_smallest_element_from_left_index: ',nearest_smallest_element_from_left_index(arr))
print('nearest_smallest_element_from_right_index: ',nearest_smallest_element_from_right_index(arr))
print('nearest_smallest_element_from_count_subarray(arr):',nearest_smallest_element_from_count_subarray(arr))
print('nearest_smallest_element_from_right: ',nearest_smallest_element_from_right(arr))