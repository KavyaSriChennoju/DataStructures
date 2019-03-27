#include<iostream>
using namespace std;
struct b1tree
{
	int key[2];
	b1tree *child[3];
	b1tree*parent;
};
void create(b1tree * &b,int n);
void overflow(b1tree *&b,int n);
void compare1(b1tree *&b,int a,int k);
void compare2(b1tree *&b,int a,int k,int c);
void print(b1tree *b);
int main()
{
	int n;
	char ch;
	b1tree *b;
	b=NULL;
	do
	{
	cout<<"enter a number\n";
	cin>>n;
	create(b,n);
	cout<<"to continue y/n\n";
	cin>>ch;
    }while(ch=='y');
    print(b);
	
}
void create(b1tree *&b,int n)
{
	if(b==NULL)
	{
		b1tree *t,*s;
		t=new(b1tree);
		t->key[0]=n;
		t->key[1]=-1;
		for(int i=0;i<3;i++)
		{
			t->child[i]=NULL;
			t->parent=NULL;
 		}
		 b=t;
		 s=b;		
	}

    else if(n<b->key[0] && b->child[0]!=NULL )
   (create(b->child[0],n));
    else if(n>b->key[0] && n<b->key[1] && b->child[1]!=NULL)
   (create(b->child[1],n));
    else if(n>b->key[1] && b->child[2]!=NULL)
    create(b->child[2],n );	
    else 
	overflow(b,n);
}
	b1tree *t1,*b1,*b2;
void overflow(b1tree *&b,int n)
{
  	if(b->key[1]==-1)
	{
	b->key[1]=n;
	compare1(b,b->key[0],b->key[1]);
    }
	else
	{
		compare2(b,	b->key[0],b->key[1],n);	
	}
}
void compare1(b1tree * &b,int a,int k)
{
	if(a>k)
	{
		b->key[0]=k;
		b->key[1]=a;
				
	if(b->child[0]!=NULL)
	{
	b->child[2]=b2;	
	}
	}
	else
	{
		b->key[0]=a;
		b->key[1]=k;
		if(b->child[0]!=NULL)
		b->child[1]=b2;}	
		

    }
    
void compare2(b1tree *&b,int a,int k,int c)
{
	int d,e,f;
	if((a>k && a<c) || (a>c && a<k))
	{if(a>k){d=k;e=a;f=c;}
	else{d=c;e=a;f=k;}
	}
	if((k>a && k<c) || (k>c && k<a))
	{if(k>a){d=a;e=k;f=c;}
	else{d=c;e=k;f=a;  }
	}
	if((c>a && c<k) || (c<a && c>a))
	{if(c>a){d=a;e=c;f=k;}
	else{d=k;e=c;f=a;}	
	}
	t1=b;
	t1->key[0]=d;
	t1->key[1]=-1;
	b2=NULL;
	create(b2,f);
	if(t1->parent==NULL)
	{
		b1=NULL;
	create(b1,e);
	}
	else
	{	if(t1->parent!=NULL)
    	overflow(t1->parent,e);
	   // else if(b1->parent!=NULL)
	   // overflow(t1->parent,e);
    }
	b=b1;
	b1=t1;
	b1->parent=b;
    b2->parent=b;
/*	if((b1->parent->key[0]==-1) && (b1->parent->key[1]==-1) ) 
	b1->parent->child[1]=NULL;*/
   if(b1->parent->key[1]==-1) 
	b1->parent->child[2]=NULL;
    if(b->key[0]==e)
    {
    b->child[0]=b1;
    b->child[1]=b2;
    }
   else if(b->key[1]==e)
    {
    b->child[1]=b1;
    b->child[2]=b2;	
    }	
	}   
	void print(b1tree *b)
	{
    if(b!=NULL)
    {
	   if(b->key[0]!=-1)
		cout<<b->key[0]<<" ";
		if(b->key[1]!=-1)
		cout<<b->key[1]<<"\n ";
		print(b->child[0]);
		print(b->child[1]);
		print(b->child[2]);
	}
	}
