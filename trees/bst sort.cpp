#include<iostream> 
using namespace std;
struct bstnode
{
	char data;
	int tag;
	bstnode *lchild;
	bstnode *rchild;
};
void create(bstnode *&m,char c);
void sort(bstnode *m,int p);
void print(bstnode *m);
int main()
{
	char c;
	int d;
	bstnode *l,*s,*t;
	l=new(bstnode);
	l->lchild=NULL;
	l->rchild=NULL;
	cout<<"enter the root and tag \n";
	cin>>c>>d;
	l->tag=d;
	l->data=c;
	s=l;t=l;
	create(l,c);
	print(l);
	return 0;		
}
void create(bstnode *&m,char c)
{
	char ch;int h;
	if(m->lchild==NULL)
	{
		cout<<"enter left child of   "<<c<<"\n";
		cin>>ch;
		if(ch!='.')
		{
			cout<<"enter tag\n";
			cin>>h;
			bstnode *t;
			t=new(bstnode);
			t->tag=h;
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;
			m->lchild=t;
			create(m->lchild,ch);
		}
	}
	if(m->rchild==NULL)
	{
		cout<<"enter right child  "<<c<<"\n";
		cin>>ch;
		if(ch!='.')
		{
			cout<<"enter tag \n";
			cin>>h;
			bstnode *t;
			t=new(bstnode);
			t->data=ch;
			t->tag=h;
			t->lchild=NULL;
			t->rchild=NULL;
			m->rchild=t;
			create(m->rchild,ch);
		}
	}
}

void sort(bstnode *m,int p)
{
	if(m->lchild!=NULL)
	sort(m->lchild,p);
	if(m->tag==p)
	cout<<m->data<<" ";
	if(m->rchild!=NULL)
	sort(m->rchild,p);
}

void print(bstnode *m)
{
	int k=1;bstnode *t;
	t=m;
	sort(m,k);
	cout<<endl;
	while(k<4)
	{
		k++;
		sort(m,k);
		cout<<endl;
	}
}

