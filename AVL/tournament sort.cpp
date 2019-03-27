#include<iostream> 
#include<cmath>
using namespace std;
struct btnode
{
	int key;
	btnode *lchild;
	btnode *rchild;
};
void create(btnode *&b, int h,int a[]);
void print(btnode *b);
int main()
{
	int a[10],a1;
	btnode *b;
	b=NULL;
	double n;
	cout<<"enter the no of numbers\n";
	cin>>n;
	cout<<"enter the no's\n";
	for(int i=0;i<n;i++)
	{
		cin>>a1;
		a[i]=a1;
	}
int	h;
if(n%2==0)	
h=log2(n);
else
h=log2(n)+1;
create(b,h,a);
print(b);	
}
void create(btnode *&b,int h,int a[])
{static int i=0;
const int c=h; 
if(h!=-1 && h!=c+1)
{
	if(b==NULL )
	{
		if(h>0)
		b->key=-1;
		else if(h==0)
	{
		b->key=a[i];
		i++;
	}
		b->lchild=NULL;
		b->rchild=NULL;}

	if(h>0 && b->key!=a[i-1])
	{
		create(b->lchild, h--,0);
}
else if(h>0)
		create(b->rchild, h--,0);
}
}
void print(btnode *b)
{
	if(b!=NULL)
	{
		print(b->lchild);
		cout<<b->key;
		print(b->rchild);	
	}
}



































