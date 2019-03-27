#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
void insert(node *&l,int n);
int main()
{
	int d,c,k,x,y,n;
	node *l;
	node *t;
	node *s;
	l=new(node);
	s=l;
	cout<<"start entering numbers to end enter -1\n";
	cin>>d;
	l->data=d;
	l->next=NULL;
	cin>>d;
	while(d!=-1)
	{
		t=new(node);
		t->data=d;
		t->next=NULL;
		l->next=t;
		l=t;
		cin>>d;
	}
	l=s;
	cout<<"enter the no to be inserted\n";
	cin>>n;
	insert(l,n);
		while(l!=NULL)
	{
		cout<<l->data<<" ";
		l=l->next;
	}
}
void insert (node *&l,int n)
{

		if(n>l->data && n<l->next->data)
		{
		  	node *t;t=new(node);
		t->data=n;
		t->next=l->next;
		l->next=t;
		}
		else
			insert(l->next,n);
		node *t;
	
}
