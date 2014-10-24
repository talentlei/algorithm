
/**
* Copyright 2014   
* Developer : lei chen (chenlei0630@gmail.com)
* Date : 10/08/2014
*
*/
#include <vector>
#include <iostream>
#include <algorithm>
int random_partation(std::vector<double>& A, int l , int r);

/**
 * this method is able to find the 1th  smaller num in O(n) time . 
 */
int Randomized_Select(std::vector<double>& A, int l, int r, int i)
{
	while(true){
		if(l  == r)
			return A[l];
		int  q = random_partation(A,l,r);

		int k = q-l+1;
		if(k == i)
			return A[q];
		else if (i < k)
			{
				r = q-1;
				continue;
				//return Randomized_Select(A,l,q-1,i);
			}
		else 
			{
				l = q+1;
				i = i-k;
				continue;
				// return Randomized_Select(A,q+1,r,i-k);
			}
	}
}


void swap(std::vector<double>& A, int i, int j)
{
	double tmp = A[j];
	A[j] = A[i];
	A[i] = tmp;
}


/*划分数组*/
int partition(std::vector<double>& A, int p, int r)
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

/**
 * partation the array randomly;
 * @param  A [description]
 * @param  l [description]
 * @param  r [description]
 * @return   [description]
 */
int random_partation(std::vector<double>& A, int l , int r)
{
	srand( (unsigned)time(NULL));
	int off = rand()%(r-l+1);
	if(l+off != r)
	{
		swap(A,l+off,r);
	}
	int ith =  partition(A,l,r);
	return ith;
}


int main()
{
	int ith = 7;
	std::vector<double> vec;
	for(int i = 31; i< 55; i++)
	{
		vec.push_back(i);
	}
	random_shuffle(vec.begin(),vec.end());
	for(int i =0; i< vec.size(); i++)
		std::cout << vec[i] << std::endl;

	int result = Randomized_Select(vec, 0, vec.size()-1, ith);
	std::cout << "第" << ith <<"小元素是：";
	std::cout << result << std::endl;
}