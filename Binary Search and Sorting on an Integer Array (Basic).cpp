#include <iostream>
#include <vector>
using namespace std ;

template<typename T>
int binarySearch(vector<T>& vec,int first,int last,const T& index)
{
	if(last>=first)
	{
		int mid = first + (last-first)/2 ;
		if(vec[mid]==index)
		{
			return mid ;
		}
		if(vec[mid]>index)
		{
			return binarySearch(vec,1,mid-1,index) ;
		}
		if(vec[mid]<index)
		{
			return binarySearch(vec,mid+1,last,index) ;
		}
	}
	return -1 ;
}
template<typename T>
void sort(vector<T>& vec,vector<T>&vec1,int size)
{
	for(int k=0;k<vec.size();k++)
	{
		vec1[k] = vec[k] ;
	}
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<vec1.size();j++)
		{
			if(vec1[j]<vec1[i])
			{
				int temp = vec1[i] ;
				vec1[i] = vec1[j] ;
				vec1[j] = temp ;
			}
		}
	}
}

int main()
{
	int arr[] = {54,84,6,785,94,845,154,874,518,95} ;
	int arrSize= sizeof(arr)/sizeof(int) ;
	vector<int> vec(arr,arr+arrSize) ;
	const int target = 94 ;
	vector<int> vec1 ;
  	int result = binarySearch(vec1,0,vec1.size(),target) ;
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" " ;
	}
	if(result == -1)
	{
		cout<<endl<<"Aradýgýn eleman yok"<<endl ;
	}
	else
	{
		cout<<endl<<"Your target in : "<<result <<". index" ;
	}
	return 0 ;
}
