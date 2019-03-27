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
	char ch='y';
	l=new(node);
			s=l;
	cout<<"start entering numbers \n";
	cin>>d;
	l->data=d;
	l->next=NULL;
	cin>>d;
		t=new(node);
		t->data=d;
		t->next=NULL;
		l->next=t;
		l=t;
		l=s;
do
	{
		cout<<"enter no\n";
		cin>>d;
		l=s;
	    insert(l,d);
	    cout<<"to continue y/n";
	    cin>>ch;
	}while(ch=='y');
	l=s;
	while(l!=NULL)
	{
		cout<<l->data<<" ";
		l=l->next;
	}
}
void insert (node *&l,int n)
{static int k=0;
        if(n<l->data && k==0)
        {
        k=1;
        node *t;
		t=new(node);
		t->data=n;
		t->next=l;
		l=t;
        }
		if(n>l->data && n<l->next->data)
		{
		node *t;
		t=new(node);
		t->data=n;
		t->next=l->next;
		l->next=t;
		}
		else if(n>l->data && l->next==NULL)
		{
		node *t;t=new(node);
		t->data=n;
		t->next=NULL;
		l->next=t;
		}
		else
		insert(l->next,n);	
}
