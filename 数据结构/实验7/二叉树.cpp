#include<iostream>
using namespace std;
class Bigtree
{
	private:
		int data;
		Bigtree *lchild;
		Bigtree *rchild;
	public:
		int Initiate();
		Bigtree Create(int x,Bigtree lbt,Bigtree Rbt);
};
	int Bigtree::Initiate()
	{
		if(!this)
			return 0;
		this->lchild = NULL;
		this->rchild = NULL;
		return 1;
	}
	Bigtree Create(int x,Bigtree lbt,Bigtree Rbt)
	{

	}
int main()
{
	Bigtree First;
	First.Initiate();
	
	return 0;
}