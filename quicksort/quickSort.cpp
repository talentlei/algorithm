/**
 * this is a c++ source code of quicksort.
 * developer :lei chen
 * date : 23/09/2014
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void swap(vector<double>& A, int i, int j)
{
	double tmp = A[j];
	A[j] = A[i];
	A[i] = tmp;
}

/*划分数组*/
int partition(vector<double>& A, int p, int r)
{
	double x = A[r];
	int i = p-1;
	for (int j = p; j <= r-1; ++j)
	{
		if(A[j] <= x)
		{
			i = i+1;
			swap(A,i,j);
		}
	}
	swap(A,i+1,r);
	return i+1;
}

/*递归调用quickSort*/
void quickSort(vector<double>& A, int head, int tail)
{
	if(head < tail)
	{
		int q = partition(A,head, tail);
		quickSort(A,head,q-1);
		quickSort(A,q+1,tail);
	}


}
/*test*/
int main()
{
	vector<double> vec;
	for (int i = 0; i < 100; ++i)
	{
		vec.push_back(static_cast<double>(i));
	}
	random_shuffle(vec.begin(), vec.end());

	cout << "before sort  :"<<endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] <<endl;
	}

	quickSort(vec,0,vec.size()-1);


	cout << "after sorted  :"<<endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] <<endl;
	}
}