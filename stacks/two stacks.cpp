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
    int b[10]={0,1,2,3,4,5,6,7,8,9},x,l=0,i,p,m,z,u;
	stack s1(10),s2(10);
	cout<<"enter no of chars in exp\n";
	cin>>x;
	cout<<"enter the postfix expression\n";
		for(i=0;i<x;i++)
	{
		cin>>a[i];
	}
		for(i=0;i<x;i++)
		{
			if(a[i]=='0')
			s1.push(b[0]);
			else if(a[i]=='1')
			s1.push(b[1]);
				else if(a[i]=='2')
			s1.push(b[2]);
				else if(a[i]=='3')
			s1.push(b[3]);
				else if(a[i]=='4')
			s1.push(b[4]);
				else if(a[i]=='5')
			s1.push(b[5]);
				else if(a[i]=='6')
			s1.push(b[6]);
			else if(a[i]=='7')
			s1.push(b[7]);
			else if(a[i]=='8')
			s1.push(b[8]);
			else if(a[i]=='9')
			s1.push(b[9]);
	
		else if ( a[i]=='*' || a[i]=='+' || a[i]=='-' || a[i]=='/')
			{
					if((a[i]=='*' || a[i]=='+' || a[i]=='-' || a[i]=='/' ) && s2.top==-1)
		{
			s2.push(a[i]);
		}
		else if(a[i]=='*' || a[i]=='/' )
		{
		s2.push(a[i]);}
		else if(a[i]=='+' || a[i]=='-')
		{
	     	while(s2.top!=-1)
	     	{
	     	k=s2.pop();
	     		p=s1.pop();
	        	m=s1.pop();
	    if(k=='*')
	    z=(m*p);
		else if(k=='+')
		z=(m+p);
		else if(k=='-')
		z=(m-p);
		else if(k=='/')
		z=(m/p);
		s1.push(z);
			}
		s2.push(a[i]);
		}
}
		
	
}
k=s2.pop();
p=s1.pop();
m=s1.pop();
	    if(k=='*')
	    z=(m*p);
		else if(k=='+')
		z=(m+p);
		else if(k=='-')
		z=(m-p);
		else if(k=='/')
		z=(m/p);
		s1.push(z);

cout<<s1.pop();}
