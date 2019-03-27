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
stack s(20);
char a[20];
int n,i;
char l,m,k;
cout<<"enter size\n";
	cin>>n;
cout<<"enter the infix expression\n";
for(i=0;i<n;i++)
{
	cin>>a[i];
}
for(i=0;i<n;i++)
{
	if((a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5' || a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')&& a[i]!='(')
	cout<<a[i];
	else 
	{
		if((a[i]=='*' || a[i]=='+' || a[i]=='-' || a[i]=='/' || a[i]=='(' || a[i]==')') && s.top==-1)
		{
			s.push(a[i]);
		}
		else if(a[i]=='*' || a[i]=='/' || a[i]=='(' )
		{
		s.push(a[i]);}
		else if(a[i]=='+' || a[i]=='-')
		{
	     m=s.pop();
	     if(m== '(')
	     {
	     	s.push(m);
	     	s.push(a[i]);
	     }
	     else
	     {s.push(m);
	     	while(s.top!=-1)
	     	{
	     	k=s.pop();
	     	if(k!='('){

	     	cout<<k;}
	     	}
	     	s.push(a[i]);
	     }
		}
		else if(a[i]==')')
		{
			
			
		l=s.pop();
		if(l!='(')
		{
		cout<<l;}
			while(s.top!=-1)
			{if(l!='(' ){
			
				l=s.pop();}
				else{
		
				l=s.pop();
				cout<<l;}
			}
		    l=	s.pop();
		    	if(l!='(')
		{
		cout<<l;}
		    	
		}
 	
	}

}


while(s.top!=-1)
{
	l=s.pop();
	if(l!='(')
	cout<<l;
}

}

