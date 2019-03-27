# include<iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
int max(bstnode *t);
int min(bstnode *t);
void  printsort(bstnode *t);
void search(bstnode *t,int k);
void tprint(bstnode *t);
void ntprint(bstnode *t);
void insert (bstnode *&l,int n);
void del(bstnode *&t,int x);
int main()
{
	int a,b,k,c;
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
cout<<"	to\nsearch  1\nmax  2\nmin  3\nprint terminal  4\nprint nonterminal  5\noutput tree  6\ndelete   7\n";
cin>>b;
switch(b)
{
case 1:cout<<"enter the element to be searched\n";
       cin>>k;
       search(t,k);
case 2: cout<<"max value is\n";
         c=max(t);
         cout<<c;
case 3:cout<<"min value\n";         
      c=min(t);
      cout<<c;
case 4: cout<<"terminal nodes are\n";
         tprint(t);
case 5: cout<<"non terminal nodes are\n";
         ntprint(t);
case 6:cout<<"sorted order is\n";
    printsort(t);
case 7:cout<<"enter the element to be deleted\n";
   cin>>k;
   del(t,k);
   printsort(t);

}}
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
void search(bstnode *t,int k)
{
	if(t==NULL)
	{
		cout<<"element not found\n";
	}
	else if(k==t->data)
	{
		cout<<"element found\n";
	}
	else if(k<t->data)
	{
		search(t->lchild,k);
	}
	else if(k>t->data)
	{
		search(t->rchild,k);
	}
}
int max(bstnode *t)
{
	if(t->rchild!=NULL)
	{
		return(max(t->rchild));
	}
	else
	{
		return(t->data);
	}
	
}
int min(bstnode *t)
{
	if(t->lchild!=NULL)
	{
		return(max(t->lchild));
	}
	else
	{
		return(t->data);
	}
	
}
void tprint(bstnode *t)
{
if(t->lchild==NULL && t->rchild==NULL)
{
	cout<<t->data;
}
else

{ 
if(t->lchild!=NULL){
tprint(t->lchild);}
else if(t->rchild!=NULL)
{
	tprint(t->rchild);}
}
	
}
void ntprint(bstnode *t)
{
	if(t->lchild!=NULL && t->rchild!=NULL)
	cout<<t->data<<"  ";
	 if(t->lchild==NULL && t->rchild!=NULL)
	cout<<t->data<<"  ";
   if(t->lchild!=NULL && t->rchild==NULL)
	cout<<t->data<<"  ";
	else
	{
		if(t->lchild!=NULL)
		ntprint(t->lchild);
		 if(t->rchild!=NULL)
		ntprint(t->rchild);
	}
}
void  printsort(bstnode *t)
{
	if(t!=NULL)
	{
		printsort(t->lchild);
		cout<<t->data;
	}
	if(t!=NULL)
	{
	printsort(t->rchild);
	}
}
void del(bstnode *&t,int x)
{
	if(t==NULL)
	return;
	else if(x<t->data)
	del(t->lchild,x);
	else if(x>t->data)
	del(t->rchild,x);
	else if(t->lchild!=NULL && t->rchild!=NULL)
	{
		t->data=(min(t->rchild));
		del(t->rchild,t->data);
	}

	else if(t->lchild==NULL && t->rchild!=NULL)
		{
		t->data=min(t->rchild);
		del(t->rchild,t->data);
	}
		else if(t->rchild==NULL && t->lchild!=NULL)
		{
		t->data=max(t->lchild);
		del(t->lchild,t->data);
	}
	else
	{
		bstnode *m;
		m=t;
		if(t->lchild!=NULL)
		t=t->lchild;
		else
		t=t->rchild;
		del(m,0);	
	}
}
