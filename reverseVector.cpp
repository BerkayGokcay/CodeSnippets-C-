#include <iostream>
#include <vector>
using namespace std ;
template<typename T>
void reverseVector(vector<T>& v,vector<T>& rev)
{
	int size = v.size() ;
	int back ;
	for(int i=0;i<size;i++)
	{
		back = v.back() ;
		v.pop_back() ;	
		rev.push_back(back) ;
	}
}

int main()
{
	int arr[] = {4,6,2,9,3,8,7,1} ;
	int arrSize = sizeof(arr)/sizeof(int) ;
	vector<int> v(arr,arr+arrSize) ;
	vector<int> revVec ;
	v.resize(5) ;
	reverseVector(v,revVec) ;
	for(int i=0;i<revVec.size();i++)
	{
		cout<<revVec[i]<<" " ;
	}
	return 0 ;
}
