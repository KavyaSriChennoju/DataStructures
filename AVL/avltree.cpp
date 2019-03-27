#include <iostream>
using namespace std;
struct avlnode
{
	avlnode *left;
	avlnode *right;
	int data;
};
int height(avlnode* a4)
{
	int b,c;
	if(a4==NULL)
		return -1;
	else
	{
		b=height(a4->left);
		 c=height(a4->right);
		if(b>c)
			return 1+b;
		else
			return 1+c;			
	}
}
	avlnode *a2;
void rotateleft(avlnode* &a1)
{

	a2=a1->right;
	a1->right=a2->left;
	a2->left=a1;
}
void rotateright(avlnode* &a1)
{
	avlnode *a2;
	a2=a1->left;
	a1->left=a2->right;
	a2->right=a1;
}
void dbrotateleft(avlnode* &a3)
{
	rotateleft(a3->left);
	a3->left=a2;
	rotateright(a3);
}
void dbrotateright(avlnode* &a3)
{
	rotateright(a3->right);
	a3->right=a2;
	rotateleft(a3);
}
void insert(avlnode* &a,int d)
{
	if(a==NULL)
	{
		a=new(avlnode);
		a->data=d;
		a->left=NULL;
		a->right=NULL;
	}
	else if(d<a->data)
	{
		insert(a->left,d);
		if((height(a->left)-height(a->right))==2)
		{
			if(d<a->left->data)
				rotateright(a);
			else
				dbrotateleft(a);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		
			if(a->data==a2->right->data)
				a=a2;
			else
				a->left=a2;
		
		}
	}
	else if(d>a->data)
	{
		insert(a->right,d);
		if((height(a->left)-height(a->right))==-2)
		{
			if(d>a->right->data)
				rotateleft(a);
			else
				dbrotateright(a);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		
			if(a->data==a2->left->data)
				a=a2;
			else
				a->right=a2;
		
		}
	}
}
void printsort(avlnode* &t)
{
	if(t->left!=NULL)
	{
		printsort(t->left);
	}
	cout<<t->data;
	if(t->right!=NULL)
		printsort(t->right);	
}
int main()
{
	int n;
	avlnode *a;
	a=new(avlnode);
	a=NULL;
	cout<<"enter root:";
	cin>>n;
	while(n!=-1)
	{
		insert(a,n);
		cout<<"enter child:";
		cin>>n;
	}
	printsort(a);
	return 0;
}
