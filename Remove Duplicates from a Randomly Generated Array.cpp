#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std ;
template <typename T>
void removeDup(vector<T>& vec)
{
	for(int i=0;i<vec.size();i++)
	{
		for(int j = 1 ;j<vec.size();j++)
		{
			if(vec[i] == vec[j])
			{
				int temp = vec[vec.size()] ;
				
			}
			else
			{
				break ;
			}
		}
	}
}

int main()
{
	srand(time(0)) ;
	int n= 5 ;
	int arr[n] = {} ;
	for(int i=0;i<n;i++)
	{
		arr[i] = rand() % 10 ;
	}
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<" " ;
	}
	cout<<endl<<endl ;
	int arrSize = sizeof(arr)/sizeof(arr[0]) ;
	vector<int> vec(arr,arr+arrSize) ;
	removeDup(vec) ;
	for(int k=0;k<5;k++)
	{
		cout<<vec[k]<<" " ;
	}
	return 0 ;
}
