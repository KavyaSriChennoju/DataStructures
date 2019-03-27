#include<iostream>
using namespace std;
const int d=3;
struct dnode
{
	int data;
	int count;
	dnode *parent;
	dnode *child[d];
};
dnode* create()
{
	dnode *l=new(dnode);
	l->parent=NULL;l->count=0;
	for(int i=0;i<d;i++)
	l->child[i]=NULL;
	return l;
}
class queue
{
	public:
		dnode *a[50];int size;
		int front ,rear;
		void enq(dnode *b);
		dnode* dq();
		queue()
		{
			size=0;
			front =-1;
			rear=-1;
		}
};
void queue::enq(dnode *b)
{   size++;
		rear=(rear+1)%50;
		a[rear]=b;
		if(front==-1)
		front++;
}
dnode* queue::dq()
{
	   size--;
		int temp=front;
		if(front!=rear)
		{
			front=(front+1)%50;
		}
	    else
	    {
	    	rear=-1;
	    	front=-1;
	    }
	    return a[temp];
}
int height(dnode *root)
{
	if(root->count==0)
	return 1;
	else
	return(1+height(root->child[0]));
}
void swap(int &a,int &b)
{
	int c=a;a=b;b=c;
}
void print(dnode *root,int a)
{
	if(root!=NULL)
	{
		if(a==0)
		cout<<root->data<<" ";
		else
		{
		for(int i=0;i<root->count;i++)
		print(root->child[i],a-1);
		}
	}
}
int main()
{
	dnode *root;int a;
	root=create();
	cout<<"enter the first no\n";
	cin>>root->data;
	dnode *s=root;
	cout<<"enter the next no\n";
	cin>>a;
	queue s1;
	dnode *l=root;
	do
	{
	  if(l->count<d)
	  {
	  	l->child[l->count]=create();
	  	l->child[l->count]->data=a;
	  	l->child[l->count]->parent=l;
	  	dnode *p=l->child[l->count];
	  	while(p->parent!=NULL)
	  	{
	  	  if(p->data<p->parent->data)
		  swap(p->data,p->parent->data);
		  p=p->parent;	
	  	}
	  	s1.enq(l->child[l->count]);
	  	l->count++;
	  }
	  else
	  l=s1.dq();
	  cout<<"enter the next no\n";
	  cin>>a;
	}while(a!=-1);int h=height(s);
	for(int i=0;i<h;i++)
	{
		print(s,i);cout<<endl;
	}
	return 0;
}
