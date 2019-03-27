# include<iostream>
# include<cstring>
using namespace std;
class stack
{
	public:
	int g[50];
	int top=-1;
	int size;
	void push(int x);
	int pop();
	stack(int s)
	{
	size=s;
	}	
};
void stack :: push(int e)
{
if(top<size)
	g[++top]=e;
}
int stack :: pop()
{if(top> -1) 
	return(g[top--]);
}
int main()
{   
    char a[10],k;
    int b[10],x,l=0,i,p,m,z,u;
	stack s(10);
	cout<<"enter no of chars in exp\n";
	cin>>x;
	cout<<"enter the postfix expression\n";
		for(i=0;i<x;i++)
	{
		cin>>a[i];
	}
		for(i=0,l=0;i<x;i++)
		{
			if ( a[i]=='0' || a[i]=='1' || a[i]=='2'  || a[i]=='3'|| a[i]=='4'|| a[i]=='5'|| a[i]=='6'|| a[i]=='7'|| a[i]=='8'|| a[i]=='9')
			{
			if(a[i]=='0')
			b[l]=0;
			else if(a[i]=='1')
			(b[l])=1;
				else if(a[i]=='2')
			(b[l])=2;
				else if(a[i]=='3')
			(b[l])=3;
				else if(a[i]=='4')
			(b[l])=4;
				else if(a[i]=='5')
			(b[l])=4;
				else if(a[i]=='6')
			(b[l])=6;
			else if(a[i]=='7')
			(b[l])=7;
			else if(a[i]=='8')
			(b[l])=8;
			else if(a[i]=='9')
			(b[l])=9;
			l++;
		}
				else if ( a[i]=='*' || a[i]=='+' || a[i]=='-' || a[i]=='/')
			{
					if((a[i]=='*' || a[i]=='+' || a[i]=='-' || a[i]=='/' ) &&s.top==-1)
		{
			s.push(a[i]);
		}
		else if(a[i]=='*' || a[i]=='/' )
		{
		s.push(a[i]);}
		else if(a[i]=='+' || a[i]=='-')
		{
	     	while(s.top!=-1)
	     	{
	     	k=s.pop();
	     		p=b[l-1];
	        	m=b[l-2];
	    if(k=='*')
	    z=(m*p);
		else if(k=='+')
		z=(m+p);
		else if(k=='-')
		z=(m-p);
		else if(k=='/')
		z=(m/p);
	l--;
	b[l-1]=z;
			}
		s.push(a[i]);
		}
}}
			k=s.pop();
	     		p=b[l-1];
	        	m=b[l-2];
	    if(k=='*')
	    z=(m*p);
		else if(k=='+')
		z=(m+p);
		else if(k=='-')
		z=(m-p);
		else if(k=='/')
		z=(m/p);
    	l--;
	b[l-1]=z;
	cout<<b[0]+1;
	
}

