# include<iostream>
using namespace std;
struct tnode
{
	int data[2];
	tnode *t[3];
};
void insert (tnode *&l,int n);
void search(tnode *t,int k);
void  printsort(tnode *t1);
int main()
{
	int a,b,k,c,m;
	char ch;
	tnode *t,*s;
	t=NULL;
	cout<<"enter the first  of the tree\n";
	cin>>a;
	insert(t,a);
	s=t;
	cout<<"enter the second root of the tree\n";
	cin>>m;
	insert(t,m);
	do
	{
		cout<<"enter the next number\n";
		cin >>a;
		insert(t,a);
		cout<<"to continue y/n\n";
		cin>>ch;
	}while(ch=='y');
	t=s;
	printsort(t);
    cout<<"enter the element to be searched\n";
       cin>>k;
       search(t,k);
}
void  printsort(tnode *t1)
{
	if(t1!=NULL)
	{
		printsort(t1->t[0]);
		cout<<t1->data[0];
		cout<<t1->data[1];
    	printsort(t1->t[1]);
    	printsort(t1->t[2]);
	}
}
void insert (tnode *&l,int n)
{
	if(l==NULL)
	{
		l=new(tnode);
		l->data[0]=n;
        for(int i=0;i<3;i++)
        {
        	l->t[i]=NULL;	
        }
	}
	if(l->data[1]==NULL)
	{
		if(l->data[0]>n)
		{
			int a;
			a=l->data[0];
			l->data[0]=n;
			l->data[0]=a;
		}
		else
		{
		l->data[1]=n;
		}
	}
	else
	{
		if(n<l->data[0])
		{
			insert(l->t[0],n);
		}
		else if(n>l->data[1])
		{
		insert(l->t[2],n);}
		else
		{
			insert(l->t[1],n);
		}
	}
}


void search(tnode *l,int k)
{
	if(l==NULL)
	{
		cout<<"element not found\n";
	}
	else if(k==l->data[0] || k==l->data[1])
	{
		cout<<"element found\n";
	}
	else if(k<l->data[0])
	{
		search(l->t[0],k);
	}
else if(k>l->data[1])
	{
		search(l->t[2],k);
	}
	else if(k>l->data[0] && k<l->data[1])
	{
		search(l->t[1],k);
	}
}

