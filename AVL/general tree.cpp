#include <iostream>
using namespace std;
struct bhnode
{
int data;
bhnode **p;
};
int main()
{
int n,m;
bhnode *l;
l=(new(bhnode));
cout<<"enter int\n";
cin>>n;
l->data=n;
cout<<"enter no \n";
cin>>m;
l->p=new bhnode *[m];
for(int i=0;i<m;i++)
{
	l->p[i]=new(bhnode);
}
for(int i=0;i<m;i++)
{
	cout<<"enter int\n";
	cin>>l->p[i]->data;
}
cout<<l->data;
for(int i=0;i<m;i++)
{
	cout<<l->p[i]->data;
}
}
