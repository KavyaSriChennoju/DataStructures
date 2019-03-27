#include<iostream>
using namespace std;
struct bdtree
{
	int count;
   	int key[4];
	bdtree *child[5];                                                                                                                                                                                                                                          
	bdtree *parent;
};	
bdtree *root,*b,*b1,*b2,*bt;
int i,j;
void print(bdtree *b);
void overflow(bdtree *&b,int a);
void create(bdtree *&b,int a);
void create4(bdtree *&b,int a);
void insert(bdtree *b,int a);
void sort(bdtree *b,int a1[],int j);
int main()
{
	int a;
	b=NULL;
	cout<<"enter starting number\n";
	cin>>a;
	while(a!=-1)
	{
	create(b,a);
	cout<<"enter next number to stop -1\n";
	cin>>a;
    }
    print(b);
}
void create4(bdtree * &b,int a)
{
    
		if(b->count<5)
		{
		insert(b,a);}
		else
		{overflow(b,a);}
}
void create(bdtree * &b,int a)
{
	static int k=0;
	bdtree *p,*t;
	if(b!=NULL && k!=0)
	{int m;
		 for(int i=0;i<5;i++)
		 {  
			if(b->child[i]==NULL)
			 m=0;
			else
			{
			 m=1;
			break;}}
			
	if(m==0)		
   {
	if(b->count<5)
		insert(b,a);
		else
		{
		overflow(b,a);}}
		else if(m==1)
			{
		for(int i1=0;i1<4;i1++)
		{
			if(a<b->key[i1] && b->child[i1]!=0)
			create(b->child[i1],a);
		}
		if(a>b->key[b->count-1])
		{
		create(b->child[b->count],a);}}
	}
	if(b==NULL && k==0)
	{
	b=new(bdtree);
	b->key[0]=a;
	for(int i=1;i<4;i++)
	b->key[i]=-1;
	for(int i=0;i<5;i++)
	b->child[i]=NULL;
	b->count=1;	
	b->parent=NULL;
	k=1;
	root=b;
	}
	int g=0;
	if(b==NULL && k!=0)
	{
	b=new(bdtree);
	b->key[0]=a;
	for(int i=1;i<4;i++)
	b->key[i]=-1;
	for(int i=0;i<5;i++)
	b->child[i]=NULL;
	b->count=1;	
	}	
}
void insert(bdtree *b,int a)
{     
 int a1[10];
    	for(i=0;i<4;i++)
			{
				if(b->key[i]==-1)
				break;
				else
				continue;
			}
			for(j=0;j<i;j++)
			{
				a1[j]=b->key[j];
				b->count++;
			}
			b->key[j]=a;
			a1[j]=a;
		   sort(b,a1,j);
}
void sort(bdtree *b,int a1[],int j)
{int d,m;
/*	for(int i=0;i<5;i++)
		 { 
			if(b->child[i]==NULL)
			m=0;
			else
			{	m=1;
			  break;
			}
		}

	if(m==0)*/
	for(int m=0;m<=j;m++)
     	{
		for(int k=m+1;k<=j;k++)
		{	if(a1[m]>a1[k])
		{
			d=a1[m];
			a1[m]=a1[k];
			a1[k]=d;
		}
	}}
	for(int i=0;i<=j;i++)
	{
		b->key[i]=a1[i];
	}
/*	else
	{ 
	int d;
	int s=b->key[j];
	for(int m=0;m<=j;m++)
     	{
		for(int k=m+1;k<=j;k++)
		{	if(a1[m]>a1[k])
		{
			d=a1[m];
			a1[m]=a1[k];
			a1[k]=d;
		}
	}}
	for(int i=0;i<j+1;i++)
	{
		if(b->key[i]=s)
		{s=i;
		break;}
		else
		continue;
	}

	bdtree *p1,*p2;
	p1=b->child[s+1];
	b->child[s+1]=b2;
	for(int i=s+1;i<j+1;i++)
	{
		p2=b->child[i+1];
		b->child[i+1]=p1;
		p1=p2;
	}}/*/}
void overflow(bdtree *&b,int a)
{   bdtree *p1,*p2;
 	int m,d,ar[10];	
	 for(int i=0;i<5;i++)
		 {  
			if(b->child[i]==NULL)
			m=0;
			else
			{
			m=1;
			break;}}
	if(m==0)
	{
		for(int i=0;i<4;i++)
		{
			ar[i]=b->key[i];
		}
		ar[4]=a;
	for(int m=0;m<5;m++)
	{
		for(int k=m+1;k<5;k++)
		{	if(ar[m]>ar[k])
		{
			d=ar[m];
			ar[m]=ar[k];
			ar[k]=d;
		}
	}}
	b1=NULL;
	for(int i1=0;i1<2;i1++)
	{
     create(b1,ar[i1]);
	}
	for(int i1=2;i1<4;i1++)
	{
	b1->key[i1]=-1;}
	b2=NULL;
	for(int i1=3;i1<5;i1++)
	{create(b2,ar[i1]);}
	b1->count=2;
	b2->count=2;
	if(b1->parent==NULL)
	{
	create(b1->parent,ar[2]);
	b=b1->parent;
	b1->parent=b;
	b2->parent=b;
	b->child[0]=b1;
	b->child[1]=b2;
	b->count=1;}
   else
   {
   	b=b->parent;
   	b1->parent=b;b2->parent=b;
    create4(b,ar[2]);
	for(int i=0;b->key[i]!=ar[2];i++)
	{continue;}
	int c4=i;
	if(b->child[c4+1]!=NULL)
	{
	b->child[c4]=b1;
	p1=	b->child[c4+1];
	b->child[c4+1]=b2;
	for(int i=c4+1;i<4;i++)
	{
		p2=b->child[i+1];
		b->child[i+1]=p1;
		p1=p2;
	}}
	else
	{
		b->child[c4]=b1;
    	b->child[c4+1]=b2;}

}}

	else
	{
	 	int ar[5];
		for(int i=0;i<4;i++)
		{
			ar[i]=b->key[i];
		}
		ar[4]=a;
	for(int m=0;m<5;m++)
	{
		for(int k=m+1;k<5;k++)
		{	if(ar[m]>ar[k])
		{
			d=ar[m];
			ar[m]=ar[k];
			ar[k]=d;
		}
	}}
    //if(a<ar[2]])
    {int c;
    for(int i=0;i<4;i++)
   {if(b->key[i]=ar[2])
   	{ c=i;
	break;}}
	for(int i=0;i<2;i++)
{	create(b1,ar[1]);
	b1->child[i]=b->child[i];}
	for(int i=3,i1=1;i<5;i++,i1++)
	{
	create(b2,ar[i]);
	b2->child[i1]=b->child[i];}
	create(bt,ar[2]);
	b1->child[c]=b->child[c];
	b2->child[0]=b->child[c+1];
	bt->child[0]=b1;
	bt->child[1]=b2;
	b=bt;
	root=b;	
    }
 
}}
	   	 
void print(bdtree *b)
	{
   if(b!=NULL)
    {  for(int i=0;i<4;i++) 
	{
	   if(b->key[i]!=-1)
		cout<<b->key[i]<<" ";}
		cout<<"\n";
		for(int j=0;j<5;j++)
       {
		print(b->child[j]);}}
		cout<<b->child[2]->key[1];
	
}

