/**
* Copyright 2014   
* Developer : lei chen (chenlei0630@gmail.com)
* Date : 09/22/2014
*
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int heap_size = 0;
/*返回最大元素*/
double heap_MaxNum(vector<double>& A)
{
	return A[0];
}

/*维持最大堆特性*/
void max_heapify(vector<double> & A, int i)
{
	int max_pos = i;
	double max = A[i];
	if (2*i+1 <heap_size && A[2*i+1] > max)
	{
		max_pos = 2*i+1;
		max = A[2*i+1];
	}
	if(2*i+2 < heap_size && A[2*i+2] > max)
	{
		max_pos = 2*i+2;
		max = A[2*i+2];
	}

	if(max_pos != i)
	{
		double temp = A[i];
		A[i] = A[max_pos];
		A[max_pos] = temp;
		max_heapify(A,max_pos);
		
	}
	
}

/*去掉并返回最大元素*/
double heap_extract_max(vector<double>& A)
{
	if (heap_size < 1)
	{
		cout << "error: underflow!" << endl;
	}

	double max = 0.0;
	max = A[0];
	A[0] = A[heap_size-1];
	heap_size = heap_size - 1;
	max_heapify(A,0);
	return max;
}
/*将位置i的元素值增至key*/
void heap_increase_key(vector<double>& A, int i, double key)
{
	if (A[i] > key)
	{
		cout << "error: key should larger than A[i]" << endl;
		return;
	}
	A[i] = key;

	int ppos = (i-1)/2;
	while(i>0 && A[i] > A[ppos])
	{
		double tmp = A[i];
		A[i] = A[ppos];
		A[ppos] = tmp;

		i = ppos;
		ppos = (i-1)/2;
	}
}

/*插入值为key的元素*/
void max_heap_insert(vector<double>& A, double key)
{
	if(heap_size == A.size())
		A.push_back(0.0);

	A[heap_size] = key-1;
	heap_size = heap_size +1;
	heap_increase_key(A,heap_size-1,key);
}

//test
int main()
{
	vector<double> A;
	max_heap_insert(A,2);
	max_heap_insert(A,3);
	max_heap_insert(A,10);
	max_heap_insert(A,5);
	max_heap_insert(A,19);
	// max_heap_insert(A,16);

	cout << "maxnum:" << heap_MaxNum(A) << endl;
	cout << "extract_max:" << heap_extract_max(A) <<endl;
	cout << "maxnum after extracted:" << heap_MaxNum(A) << endl;

	heap_increase_key(A,0,21);
	cout << "maxnum after increaseed:" << heap_MaxNum(A) << endl;

	max_heap_insert(A,23);
	cout << "maxnum after inserted:" << heap_MaxNum(A) << endl;	

}