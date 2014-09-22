#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void max_heapify(vector<double> & A, int i, int heap_size)
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
		max_heapify(A,max_pos,heap_size);
		
	}
	
}


/*know why build from heap_lenth/2 to 0*/
void build_max_heap(vector<double> & A)
{
	int heap_lenth = A.size();
	for (int i = heap_lenth/2-1; i >= 0; --i)
	{
		max_heapify(A,i,heap_lenth);
	}

}



/**/
void heap_sort(vector<double>& A)
{
	build_max_heap(A);
	for (int i = A.size()-1; i > 0;  --i)
	{
		//swap 
		{
			double temp = A[i] ;
			A[i] = A[0];
			A[0] = temp;
		}
		max_heapify(A,0,i);
	}
}

//test
int main()
{
	vector<double> vec;
	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(static_cast<double>(i));
	}
	random_shuffle(vec.begin(), vec.end());

	cout << "before sort  :"<<endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] <<endl;
	}

	heap_sort(vec);


	cout << "after sorted  :"<<endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] <<endl;
	}
}