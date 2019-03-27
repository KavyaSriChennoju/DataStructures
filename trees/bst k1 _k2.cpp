# include<iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
  void insert (bstnode *&l,int n);
void  printsort(bstnode *t,int k1,int k2);
int main()
{
	int a,b,k1,k2,c;
	char ch;
	bstnode *t;
	t=NULL;
	cout<<"enter the root of the tree\n";
	cin>>a;
	insert(t,a);
	do
	{
		cout<<"enter the next number\n";
		cin >>a;
		insert(t,a);
		cout<<"to continue y/n\n";
		cin>>ch;
	}while(ch=='y');
	cout<<"enter the no's k1 and k2\n";
	cin>>k1;
	cin>>k2;
	printsort(t,k1,k2);
}
	  

	  
	  
	  void insert (bstnode *&l,int n)
{
	if(l==NULL)
	{
		l=new(bstnode);
		l->data=n;
		l->rchild=NULL;
		l->lchild=NULL;
	}
	else
	{
		if(n<l->data)
		{
			insert(l->lchild,n);
		}
		else if(n>l->data)
		{
		insert(l->rchild,n);}
	}
}

void  printsort(bstnode *t,int k1,int k2)
{  
	if(t!=NULL)
	{
		printsort(t->lchild,k1,k2);
		if((k1<t->data &&t->data <k2)||(k2<t->data&& t->data<k1))
		cout<<t->data;;
		
	}
	if(t!=NULL)
	{
	printsort(t->rchild,k1,k2);
	}
}
