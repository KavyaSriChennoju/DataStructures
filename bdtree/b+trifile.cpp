#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct btnode;int d4=1;
void create(btnode *&t,int c,int d);
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
	data key[3];
	btnode *child[4];btnode *side;
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
		int *a;a=new int[2*d4+1];
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
	l->side=NULL;
	for(int i=0;i<2*d4+1;i++)
	{
		l->child[i]=NULL;
		l->key[i].roll=-1;l->key[i].index=-1;
	}
	l->child[2*d4+2]=NULL;
	l->parent=NULL;l->count=0;
	return l;
}
void nodesplit(btnode *&m);
void nodesplit(btnode *&m)
{
	 btnode *p,*n;
	 p=m;
     n=node();
     if(isleaf(m))
     {
     	for(int i=0;i<d4+1;i++)
      {
       n->key[i]=p->key[d4+i];
       n->child[i+1]=p->child[d4+1+i];
      }
       n->child[0]=p->child[d4];
       n->count=d4+1;
       for(int i=0;i<d4+1;i++)
       {
     	if(n->child[i]!=NULL)
		 n->child[i]->parent=n;
       } 
       m->side=n;
     }
     else
     {
      for(int i=0;i<d4;i++)
      {
       n->key[i]=p->key[d4+1+i];
       n->child[i+1]=p->child[d4+2+i];
      }
      n->child[0]=p->child[d4+1];
      n->count=d4;
      for(int i=0;i<d4+1;i++)
      {
     	if(n->child[i]!=NULL)
		 n->child[i]->parent=n;
      }
	 }
      m=p;
      m->count=d4;
    for(int i=0;i<d4+1;i++)
    m->child[d4+1+i]=NULL;
     if(p->parent==NULL)
     {
     	btnode *d1=node();
     	d1->key[0]=p->key[d4];
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
	 	if(m->parent->key[i].roll>p->key[d4].roll)
	 	break;a1++;
	    }
	    for(int j=m->parent->count;j>a1;j--)
		{
		m->parent->key[j]=m->parent->key[j-1];
		m->parent->child[j+1]=m->parent->child[j];
	    }
	    m->parent->child[a1+1]=n;
		m->parent->key[a1]=p->key[d4];
		(m->parent->count)++;
		if(m->parent->count>2*d4)
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
		t->key[0]=c;
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
		if(m->count>2*d4)
		nodesplit(m);
	}
}
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
 if(t->side!=NULL)
 cout<<t->side->key[0].index<<endl;
 else
 cout<<q2<<endl;
 for(int i=t->count;i<2*d4;i++)
 cout<<q2<<" "<<q2<<" "<<q2<<" "<<q2<<endl;}
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
	ofstream out;
	out.open("b+data");
	btnode *l=NULL;int a;
	int b=0,c=0;data a1;student s1;
	cout<<"enter the starting no\n";
	cin>>a1.roll;a1.index=c;
	out<<c++<<" "<<a1.roll<<" ";
	while(a1.roll!=-1)
	{
		b=0;
		create(l,a1,b);l=root;
		cout<<"enter the name\n";
		cin>>s1.name;
		out<<s1.name<<endl;
		cout<<"enter the next no\n";
		cin>>a1.roll;a1.index=c;
		if(a1.roll!=-1)
		out<<c++<<" "<<a1.roll<<" ";
	}
	out.close();
	cout<<endl;
	order(root);
	return 0;
}
