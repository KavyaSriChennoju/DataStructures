#include<iostream> 
#include<cmath>
using namespace std;
struct btnode
{
	int key;
	btnode *lchild;
	btnode *rchild;
};
int height(btnode* b1);
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
int	h=log2(n);
create(b,h,a);
print(b);	
}
void create(btnode *&b,int h,int a[])
{
    static int i=0;
    btnode *t;
	if(b==NULL )
	{
		b=t;
		if(h>0)
		{
		b->key=-1;
		b->lchild=NULL;
		b->rchild=NULL;
        }
	else if(h==0)
	{
		b->key=a[i];i++;
		b->lchild=NULL;
		b->rchild=NULL;
	}}
	if(h>=0)
	{
	create(b->lchild,h--,0);
	create(b->rchild,height(b),0);
    }
}
int height(btnode* b1)
{
	int b,c;
	if(b1==NULL)
		return -1;
	else
	{
		b=height(b1->lchild);
		 c=height(b1->rchild);
		if(b>c)
			return 1+b;
		else
			return 1+c;			
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



































