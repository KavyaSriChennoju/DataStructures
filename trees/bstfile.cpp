#include<iostream>
#include<fstream>
using namespace std;
struct st
{
	int serial;
	float cgpa;
	char name[10];
	int rollno;
};
struct bst 
{
	int l,r,in;
	float c;
};
int main()
{
	st s[100];bst s1[100];
	int k,p=0,m,d;
	cout<<"enter no of students\n";
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cout<<"enter the name of student  "<<i+1<<endl;
		cin>>s[i].name;
		cout<<"enter cgpa\n";
		cin>>s[i].cgpa;
		cout<<"enter rollno\n";
		cin>>s[i].rollno;
		s[i].serial=i+1;
	}
	s1[0].l=-1;
	s1[0].r=-1;
	s1[0].in=1;
	s1[0].c=s[0].cgpa;
	for(int i=1;i<k;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(s[i].cgpa<s[j].cgpa)
			{
				m=0;
				while(s1[m].c!=s[j].cgpa)
				m++;
				l1:
					{
						if(s1[m].l==-1)
						{
							s1[m].l=s[i].serial;p++;
							s1[p].l=-1;
							s1[p].r=-1;s1[p].in=s[i].serial;
							s1[p].c=s[i].cgpa;break;
						}
						else
						{
							d=0;
							while(s1[d].in!=s1[m].l)
							d++;
							m=d;
						    if(s1[d].c>s[i].cgpa)
						    goto l1;
						    else
						    goto l2;
						}
					}
			}
			if(s[i].cgpa>s[j].cgpa)
			{
				m=0;
				while(s1[m].c!=s[j].cgpa)
				m++;
				l2:
					{
						if(s1[m].r==-1)
						{
							s1[m].r=s[i].serial;p++;
							s1[p].l=-1;
							s1[p].r=-1;s1[p].in=s[i].serial;
							s1[p].c=s[i].cgpa;break;
						}
						else
						{
							d=0;
							while(s1[d].in!=s1[m].r)
							d++;
							m=d;
						    if(s1[d].c>s[i].cgpa)
						    goto l1;
						    else
						    goto l2;
						}
					}
			}
		}
	}
	for(int i=0;i<p+1;i++)
	{
		cout<<s1[i].l<<" "<<s1[i].c<<" "<<s1[i].in<<"  "<<s1[i].r<<endl;
	}
	return 0; 
}

