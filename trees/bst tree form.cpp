#include<iostream>
using namespace std;
struct bstnode
{
	char data;
	int tag1,tag2;
	bstnode *lchild;
	bstnode *rchild;
};
void create(bstnode *&m,char c);
void sort(bstnode *m,int p);
void print(bstnode *m);
int main()
{
	char c;int d,e;
	bstnode *l,*s,*t;
	l=new(bstnode);
	l->lchild=NULL;
	l->rchild=NULL;
	cout<<"enter the root and tag1 and tag2 \n";
	cin>>c>>d>>e;
	l->tag1=d;
	l->tag2=e;
	l->data=c;s=l;t=l;
	create(l,c);
	print(l);
	return 0;
		
}
void create(bstnode *&m,char c)
{
	char ch;int h,s;
	if(m->lchild==NULL)
	{
		cout<<"enter left child  \n";
		cin>>ch;
		if(ch!='.')
		{
			cout<<"enter tag1\n";
			cin>>h;
			cout<<"enter tag2 \n";
			cin>>s;
			bstnode *t;
			t=new(bstnode);
			t->tag1=h;
			t->tag2=s;
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;m->lchild=t;
			create(m->lchild,ch);
		}
	}
	if(m->rchild==NULL)
	{
		cout<<"enter right child  \n";
		cin>>ch;
		if(ch!='.')
		{
			cout<<"enter tag1 \n";
			cin>>h;
			cout<<"enter tag2 \n";
			cin>>s;
			bstnode *t;
			t=new(bstnode);
			t->data=ch;
			t->tag1=h;
			t->tag2=s;
			t->lchild=NULL;
			t->rchild=NULL;m->rchild=t;
			create(m->rchild,ch);
		}
	}
}

void sort(bstnode *m,int p)
{
	if(m->lchild!=NULL)
	sort(m->lchild,p);
	if(m->tag1==p)
	{
		for(int i=0;i<m->tag2;i++)
		cout<<" ";
	cout<<m->data;}
	if(m->rchild!=NULL)
	sort(m->rchild,p);
}

void print(bstnode *m)
{
	int k=1;bstnode *t1;t1=m;
	sort(m,k);
	cout<<endl;
	while(k<4)
	{
		k++;
		sort(m,k);
		cout<<endl;
	}
}

