# include<iostream>
# include<cstring>
using namespace std;
union u
{
	char ch;
	char name[20];
	int in;
	float f;
};
struct generic
{
	u a1;
	int tag;
};
class stack
{
	public:
		generic a[100];
		int top;
		int size;
		void push(generic p);
		generic pop();

stack(int s)
{
	size =s;
	top=-1;
}
};
void stack :: push(generic p)
{
if(top<10)
a[top++]=p;
}
generic stack :: pop()
{
	if(top>-1)
	{
		return(a[--top]);
	}
}
int main()
{
	stack s(10);generic g;
	cout<<"enter 1-char,2-name,3-integer,4-float,-1-end\n";
	cin>>g.tag;
	do
	{
		if(g.tag==1)
	{
		cout<<"enter a character\n";
		cin>>g.a1.ch;
	}
	if(g.tag==2)
	{
		cout<<"enter name \n";
		cin>>g.a1.name;
	}
	if(g.tag==3)
	{
		cout<<"enter integer \n";
		cin>>g.a1.in;
	}
		if(g.tag==4)
	{
		cout<<"enter float \n";
		cin>>g.a1.f;
	}
	s.push(g);
	cout<<"enter tag \n";
	cin>>g.tag;
	}while(g.tag!=-1);
	while(s.top!=-1)
	{
		g=s.pop();
		if(g.tag==1)
		cout<<g.a1.ch<<endl;
		if(g.tag==2)
		cout<<g.a1.name<<endl;	
		if(g.tag==3)
		cout<<g.a1.in<<endl;	
		if(g.tag==4)
		cout<<g.a1.f<<endl;
	}
	return 0;
}
