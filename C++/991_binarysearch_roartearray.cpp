#include<iostream>
using namespace std;
int binary_search(int arr[], int l, int r, int target) 
{
    while (l <= r) 
    {
        int mid = l + (r - l) / 2;  

        if (arr[mid] == target) 
        {
            return mid;
        }

       
        if (arr[l] <= arr[mid]) {
            if (arr[l] <= target && target < arr[mid]) {
                r = mid - 1;  
            } else {
                l = mid + 1; 
            }
        }
      
        else {
            if (arr[mid] < target && target <= arr[r]) {
                l = mid + 1;  
            } else {
                r = mid - 1; 
        }
    }

    return -1;  
    }
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, -1, -2, -3};  // Example rotated sorted array
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 6;
    int result = binary_search(arr, 0, size - 1, target);  // Pass size - 1 as upper bound

    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}

