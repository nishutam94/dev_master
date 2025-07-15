#include<bits/stdc++.h>
#include<unordered_map>
#include<iostream>
using namespace std;

void print_array(int a[],int size);

int count_occurance_more_then_k(int a[],int size,int k)
{
	unordered_map<int,int> map2;
	int cnt=0;
	for(int i=0;i<size;i++)
	{
		map2[a[i]]++;
	}

	for(auto a = map2.begin();a!=map2.end();a++)
	{
		if(a->second>=k)
			cnt++;

	}
	return cnt++;
}

void merge_two_sorted_array_without_extra_space(int a[],int b[],int as,int bs)
{   
	print_array(a,5);
	print_array(b,5);

	int i=as-1;
	int j=0;
	while(i>0 and j<bs)
	{	
		if(a[i]>b[j])
			swap(a[i],b[j]);
		i--;
		j++;

	}

	sort(a,a+as);
	sort(b,b+bs);

	print_array(a,5);
	print_array(b,5);
}

unordered_map<int,int> intersection_of_arrays(int a[],int b[],int sa,int sb)
{
	unordered_map<int,int> map1;
	for(int i=0;i<sa;i++)
	{
		if(map1.find(a[i])==map1.end()) 
			map1[a[i]]++;
	}
	for(int i=0;i<sb;i++)
	{
		if(map1.find(b[i])==map1.end())  
			map1[b[i]]++;
		
	}
	return map1;
}

void print_map(unordered_map<int,int> map)
{
	cout<<"map -> ";
	for(auto a=map.begin(); a!=map.end(); a++)
	{
		cout<<a->first<<" ";
	}
	cout<<"\n";
}

void print_array(int a[],int size)
{	
	cout<<"array -> ";
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void reverse_integer_array(int a[],int size)
{
	int l = 0;
	int r = size-1;
	int temp = 0;
	while(l<r)
	{
		//function -> swap(a[l],a[r])
		temp = a[l];
		a[l] = a[r];
		a[r] = temp;
		l++;
		r--;
	}
}

void cyclindical_rotation(int a[],int size)
{
	int tmp = a[size-1];
	for(int i=size;i>0;i--)
	{
		a[i] = a[i-1];
	}
	a[0]=tmp;
}

int main()
{
	int arr1[] = {10,20,30,40,50};
	int arr2[] = {10,20,25,29,50};
	int arr3[] = {15,25,35,60,70};
	int arr4[] = {15,25,25,60,70,15,25,35,70,70};
	int size =  5;
	

	print_array(arr1,size);
	reverse_integer_array(arr1,size);
	print_array(arr1,size);
	cyclindical_rotation(arr1,size);
	print_array(arr1,size);
	print_map(intersection_of_arrays(arr1,arr2,5,5));
	merge_two_sorted_array_without_extra_space(arr3,arr2,5,5);
	cout<<count_occurance_more_then_k(arr4,10,3)<<"\n";


	return 0;
}
