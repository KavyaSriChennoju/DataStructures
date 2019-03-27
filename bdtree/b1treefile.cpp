#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct data
{
	int index,roll;
};
struct student
{
	int rollno;
	char name[10];
};
struct btnode
{
	btnode *parent;
	data key[5];
	btnode *child[6];
	int count;
};
bool isleaf(btnode *t);
bool isleaf(btnode *t)
{
		int d=0;
	for(int i=0;i<t->count+1;i++)
	{
		if(t->child[i]==NULL)
		d++;
		else
		break;
	}
	if(d==t->count+1)
	return true;
	else
	return false;
}
int max(int a[],int b);
int max (int a[],int b)
{
	for(int i=0;i<b-1;i++)
	for(int j=i+1;j<b;j++)
	if(a[j]>a[i])
	{
		int y=a[j];a[j]=a[i];a[i]=y;
	}
	return a[0];
}
int  height(btnode *a4);
int height(btnode *a4)
{
	if(!isleaf(a4))
	{
		int a[5];
		for(int i=0;i<a4->count+1;i++)
		a[i]=height(a4->child[i]) ;
		return (1+(max(a,a4->count+1)));	
	}
	else
	return (-1);
}
btnode *root;
btnode* leaf(btnode *t,data c);
btnode* leaf(btnode *t,data c)
{
	int d=0,r=0;
	for(int i=0;i<t->count+1;i++)
	{
		if(t->child[i]==NULL)
		d++;
		else
		break;
	}
	if(d==t->count+1)
	return (t);
	else
	{
		if(c.roll>t->key[t->count-1].roll)
		return leaf(t->child[t->count],c);
	    for(int i=0;i<t->count;i++)
	    {
	    	if(c.roll<t->key[i].roll)
	    	break;
	    	r++;
	    }
	    return leaf(t->child[r],c);
   }
}
btnode* node();
btnode* node()
{
	btnode *l;
	l=new(btnode);
	for(int i=0;i<5;i++)
	{
		l->child[i]=NULL;
		l->key[i].roll=-1;l->key[0].index=-1;
	}
	l->child[6]=NULL;
	l->parent=NULL;l->count=0;
	return l;
}
void nodesplit(btnode *&m);
void nodesplit(btnode *&m)
{
	 btnode *p,*n;
	 p=m;
     n=node();
     for(int i=0;i<2;i++)
     {
     n->key[i]=p->key[3+i];
     n->child[i+1]=p->child[4+i];
     }
     n->child[0]=p->child[3];
     n->count=2;
     for(int i=0;i<3;i++)
     {
     	if(n->child[i]!=NULL)
		 n->child[i]->parent=n;
     }
    m=p;
    m->count=2;
    for(int i=0;i<3;i++)
    m->child[3+i]=NULL;
     if(p->parent==NULL)
     {
     	btnode *d1=node();
     	d1->key[0]=p->key[2];
     	d1->child[0]=m;
     	d1->child[1]=n;
     	n->parent=d1;
     	m->parent=d1;
     	d1->count=1;
     	root=d1;
     }
     else
     {
        n->parent=m->parent;
	    int a1=0;
	    for(int i=0;i<m->parent->count;i++)
	    {
	 	if(m->parent->key[i].roll>p->key[2].roll)
	 	break;a1++;
	    }
	    for(int j=m->parent->count;j>a1;j--)
		{
		m->parent->key[j]=m->parent->key[j-1];
		m->parent->child[j+1]=m->parent->child[j];
	    }
	    m->parent->child[a1+1]=n;
		m->parent->key[a1]=p->key[2];
		(m->parent->count)++;
		if(m->parent->count>4)
		nodesplit(m->parent);	
     }
}
void create(btnode *&t,data c,int d);
void create(btnode *&t,data c,int d)
{
	static int k=0;
	btnode *l,*m,*n;
	if(k==0)
	{
		t=node();
		t->key[0].roll=c.roll;t->key[0].index=c.index;
		k++;t->count=1;root=t;
	}
	else
	{
		if(d==0)
		{
			d++;
			m=leaf(root,c);
		}
		else
		m=t;int k1=0;
		for(int i=0;i<m->count;i++)
		{
			if(c.roll<m->key[i].roll)
			break;
			k1++;
		}
		for(int j=m->count;j>k1;j--)
		{
		m->key[j]=m->key[j-1];
		m->child[j+1]=m->child[j];
	    }
	    m->child[k1+1]=NULL;
		m->key[k1]=c;
		(m->count)++;
		if(m->count>4)
		nodesplit(m);
	}
}
//ofstream fout.open("btree",ios::app);
void level(btnode *t,int a);
void level(btnode *t,int a)
{
	static int q=0;int q2=-1;
 if(t!=NULL)
 {
 if(a==0)
 {
 for(int i=0;i<t->count;i++)
 cout<<q++<<" "<<t->key[i].roll<<" "<<t->key[i].index<<" ";
 for(int i=t->count;i<4;i++)
 cout<<q2<<" "<<q2<<" "<<q2<<" ";cout<<endl;
 }
 else if(a>0)
 {
 	for(int i=0;i<t->count;i++)
 	{
 		level(t->child[i],a-1);
 	}
  level(t->child[t->count],a-1);
 }}
}
void order(btnode *t);
void order(btnode *t)
{
 int a=height(t)+2;
 for(int i=0;i<a;i++)
 {
  level(t,i);
 }
} 
int main()
{
	btnode *l=NULL;int a;ofstream out;
	out.open("data");
	int b=0,c=0;data a1;student s1;
	cout<<"enter the starting no\n";
	cin>>a1.roll;a1.index=c;
    out<<c++<<a1.roll;
	while(a1.roll!=-1)
	{
		b=0;
		create(l,a1,b);l=root;
		cout<<"enter the name\n";
		cin>>s1.name;
		out<<s1.name;out<<endl;
		cout<<"enter the next no\n";
		cin>>a1.roll;a1.index=c;
		if(a1.roll!=-1)
		out<<c++<<a1.roll;
	}
	out.close();
	cout<<endl;
	order(root);
	return 0;
}
