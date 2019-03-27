#include<iostream>
using namespace std;
class stack
{public:
	int a[10];
	int topa,topb;
	int popa();int popb();
	void pusha(int c);
	void pushb(int d);
	stack(int e)
	{
		topa=e;
		topb=e+11;
	}
	
};
int stack::popa()
{
	if(topa>-1)
	return a[topa--];
}
int stack::popb()
{
	if(topb<10)
	return a[topb++];
}
void stack::pusha(int c)
{
	if(topa!=topb-1)
	a[++topa]=c;
}
void stack::pushb(int d)
{
	if(topa!=topb-1)
	a[--topb]=d;
}
int main()
{
	stack f(-1);int h,i,j;
	char g;
	cout<<"u want to enter no in a or b part of stack \n";
	cin>>g;
	if(g=='a')
	{
		cout<<"enter \n";
		cin>>h;
		f.pusha(h);
	}
	if(g=='b')
	{
		cout<<"enter \n";
		cin>>h;
		f.pushb(h);
	}
	cout<<"u want to get no then enter 1(a) or 2(b) \n";
	cin>>j;
	if(j==1)
	{
		if(f.topa!=-1)
		{
		i=f.popa();
		cout<<i<<endl;
		}
	}
	if(j==2)
	{
		if(f.topb!=10)
		{
		i=f.popb();
		cout<<i<<endl;	
		}
	}return 0;
}
