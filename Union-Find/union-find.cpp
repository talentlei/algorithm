/**
 * 该文件用于实现并查集算法 Union-Find
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>

class UF
{
	/* data */
private:
	int *id;
	int count;
	int size;
	int *sz;
public:
	UF(int N);
	~UF();
	int getCount();
	bool connected(int p, int q);
	int find(int p);
	void uniontest(int p, int q);

	
};

UF::UF(int N)
{
	count = N;
	size = N;
	id = new int[N];
	for(int i = 0; i < N;  i++)
		id[i] = i;

	sz = new int[N];
	for (int i = 0; i < N; ++i)
		sz[i] = 1;
}
UF::~UF()
{
	delete [] id;
	delete [] sz;
}

int UF::getCount()
{
	return count;
}

bool UF::connected(int p, int q)
{
	return find(p) == find(q);
}

int UF::find(int p)
{
	while(id[p] != p)
		p = id[id[p]];   //加快查询速度
	return p;
}

void UF::uniontest(int p, int q)
{
	int qroot = find(q);
	int proot = find(p);

	if(qroot == proot)
		return;
	if(sz[qroot] > sz[proot])
	{
		id[proot] = qroot;
		sz[qroot] += sz[proot];
	}
	else 
	{
		id[qroot] = proot;
		sz[proot] += sz[qroot];
	}
	count--;
}



int main()
{
	using namespace std;
	int N = 20;
	UF uf(N);
	

	srand(time(NULL));
	for( int  i = 0; i < 10;  i++ )
	{
		int p = rand()%(20);
		int q = rand()%(20);
		uf.uniontest(p,q);
		cout << "p=" << p << "\tq="<<q<<endl;
	}

	cout << uf.getCount() << endl;
}
