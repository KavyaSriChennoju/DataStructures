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
	int n1;
	cout<<"enter the no of numbers\n";
	cin>>n;
	n1=n;
	cout<<"enter the no's\n";
	for(int i=0;i<n1;i++)
	{
		cin>>a1;
		a[i]=a1;
	}
	for(int i=n1;i<10;i++)
	a[i]=-1;
int	h;
if(n1%2==0)	
h=log2(n);
else
h=log2(n)+1;
create(b,h,a);
print(b);	
}
int h1=0,h2=0;
void create(btnode *&b,int h,int a[])
{
static int i=0;
	if(b==NULL)
	{
			if(h1!=h && h2!=h )
		{
		b->key=-1;
		b->lchild=NULL;
		b->rchild=NULL;
        }
	else if(h1==h || h2==h)
	{
		b->key=a[i];i++;
		b->lchild=NULL;
		b->rchild=NULL;
	}
	}
	if(h1!=h)
	{	h1++;
		create(b->lchild,h,a);}
	if(h2!=h)
	{
		h2++;
		create(b->rchild,h,a);
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



































