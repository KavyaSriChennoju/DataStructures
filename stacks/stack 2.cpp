# include<iostream>
# include<cstring>
using namespace std;
class stack
{
	public:
	int g[50];
	int top = -1;
	int size;
	void push(int x);
	int pop();
	stack(int s)
	{
	int	size=s;
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
    char a[10];
    int b[10],c[10],x,l=0,i,p,m,k,z,u;
	stack s(10);
	cout<<"enter no of ahrs in exp\n";
	cin>>x;
	cout<<"enter the postfix expression\n";
	for(i=0,l=0;i<x;i++)
	{
		cin>>a[i];
			if( a[i]!='*' && a[i]!='+' && a[i]!='-' && a[i]!='/')
			{
		b[i]=a[i];
		c[l++]=b[i]-48;
	}
	}
	
	for(i=0,u=0;i<x;i++)
   {
	if( a[i]=='1' || a[i]=='2' ||a[i]=='3' ||a[i]=='4' ||a[i]=='5' ||a[i]=='6' ||a[i]=='7' ||a[i]=='8' ||a[i]=='9')
	{
		s.push(c[u]);
		u++;
		
    }
	else if ( a[i]=='*' || a[i]=='+' || a[i]=='-' || a[i]=='/')
	{
		p=s.pop();
		m=s.pop();
		if(a[i]=='*')
	{k=m*p;}
		else if(a[i]=='+')
		{k=m+p;}
		else if(a[i]=='-')
		{
		k=m-p;}
		else if(a[i]=='/'){
		k=m/p;}
		s.push(k);
	}
}
	cout<<s.pop();
	
}
