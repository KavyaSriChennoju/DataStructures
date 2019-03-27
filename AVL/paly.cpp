#include<iostream>
using namespace std;
struct node
{
	char data;
	node *left;
	node *right;
};
int paly(node *l,node *d);

int main()
{
	node *l,*s,*t,*d;char c,ch;int k;
	l=new(node);
	cout<<"enter character \n";
	cin>>c;
	l->data=c;
	l->left=NULL;
	l->right=NULL;
	s=l;
	do
	{
		cout<<"enter the next character \n";
		cin>>c;
		t=new(node);
		t->data=c;
		t->left=l;
		t->right=NULL;
		l->right=t;
		l=t;
		cout<<"do you want to continue y or n\n";
		cin>>ch;
	}while(ch=='y');
	d=l;
	l=s;
	k=paly(l,d);
	if(k==1)
	cout<<"palindrome \n";
	else
	cout<<"not a palindrome \n";
	return 0;
}
int paly(node *l,node *d)
{

		if(l->right!=NULL)
		{
	if(l->data==d->data)
	return (paly(l->right,d->left));
	if(l->data!=d->data)
	return 0;}
	if(l->right==NULL)
	return 1;
}
