# include<iostream>
# include<cstring>
using namespace std;
class stack
{
	public:
	char a[50];
	int top =-1;
	int size;
	void push(char x);
	char pop();
	stack(int s)
	{
	int	size=s;
	}	
	
};
void stack :: push(char e)
{
if(top<size)
	a[++top]=e;
}
char stack :: pop()
{
    if(top > -1) 
	return(a[top--]);
}
  int main()

{ 
    int n,i,m,o;
	char b[5],p;
	stack s1(5);
	cout<<"enter the expression\n";
	for(i=0;i<5;i++)
	{
		cin>>b[i];
	}

	for(i=0;i<5;i++)
	{
		if(b[i]=='(' || b[i]== '{' || b[i]== '[' )
		{
			s1.push(b[i]);
			 m=0;
			m++;
		}
    else if(b[i]=='}' || b[i]==']'||b[i]==')')
		{
		     o=0;
			p=s1.pop();
			if((p=='{' && b[i]!='}') || (p=='[' && b[i]!=']') ||(p=='(' && b[i]!=')'))
			cout<<"expression is not balanced\n";
			o++;
		}
	}
	
	if(s1.top==-1 &&  m==n )
	{
		cout<<"expression is balanced\n";
	}
	else 
	cout<<"expression is not balanced\n";
}
