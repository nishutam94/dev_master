import copy

original_list = [[1, 2, 3]]
#original_list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
shallow_copied_list = copy.copy(original_list)
shallow_copied_list[0][0] = 'A'
print("Original list:", original_list)
print("Shallow copied list:", shallow_copied_list)


original_list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
deep_copied_list = copy.deepcopy(original_list)
deep_copied_list[0][0] = 'A'
print("Original list:", original_list)
print("Deep copied list:", deep_copied_list)

