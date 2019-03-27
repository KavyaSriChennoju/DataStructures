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
    char a[10];
    int b[10]={0,1,2,3,4,5,6,7,8,9},x,l=0,i,p,m,k,z,u;
	stack s(10);
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
			s.push(b[0]);
			else if(a[i]=='1')
			s.push(b[1]);
				else if(a[i]=='2')
			s.push(b[2]);
				else if(a[i]=='3')
			s.push(b[3]);
				else if(a[i]=='4')
			s.push(b[4]);
				else if(a[i]=='5')
			s.push(b[5]);
				else if(a[i]=='6')
			s.push(b[6]);
			else if(a[i]=='7')
			s.push(b[7]);
			else if(a[i]=='8')
			s.push(b[8]);
			else if(a[i]=='9')
			s.push(b[9]);
		else if ( a[i]=='*' || a[i]=='+' || a[i]=='-' || a[i]=='/')
			{
				p=s.pop();
	        	m=s.pop();
		
		if(a[i]=='*')
	    {k=(m*p);}
		else if(a[i]=='+')
		{k=(m+p);}
		else if(a[i]=='-')
		{
		k=(m-p);}
		else if(a[i]=='/')
		{
		k=(m/p);}
		s.push(k);
			}
				
		}
	
		cout<<s.pop();
	
}
