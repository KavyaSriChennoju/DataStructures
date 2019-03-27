#include<iostream>
#include<string>
using namespace std;
struct sub
{
	string s;
};
struct mid
{
	sub *l1;
	mid *l2;
	mid *u1;
};
struct st
{
	int roll;
	mid *l;
};
int main()
{
	int a,b,c,d=0,e,f=1;
	st t[20];string s2;
	mid *m1,*m2,*m3,*m4,*m5;
	cout<<"enter the no of subjects \n";
	cin>>a;
	cout<<"enter the no of students \n";
	cin>>b;
	for(int i=0;i<b;i++)
	{
		cout<<"enter the rollno of student "<<i+1<<"\n";
		cin>>t[i].roll;
		t[i].l=NULL;
	}
	for(int i=0;i<b;i++)
	{
		cout<<"enter the no of subjects registered by the student "<<i+1<<endl;
		cin>>c;
		for(int g=0;g<c;g++)
		{
		    cout<<"enter the subject "<<g+1<<endl;
			cin>>s2;
			d=0;
			if(t[i].l==NULL)
			{
				for(int j=i-1;j>=0;j--)
				{
					 m1=t[j].l;
					while(m1!=NULL)
					{
						if(m1->u1!=NULL)
						{
								m2=m1->u1;
								while(m2->u1!=NULL)
								m2=m2->u1;
								if(m2->l1->s==s2)
								{
									d++;
									e=j;f=1;break;
								}
						}
						if(m1->l1!=NULL)
						{
								if(m1->l1->s==s2)
							{	d++;
								e=j;
								f=0;break;}
						}
						if(d!=0)
						break;else
						m1=m1->l2;
							
					}
					if(d!=0)
					break;
				}
				if(d==0)
				{
				   m4=new(mid);
				   m4->l1=new(sub);
				   m4->l1->s=s2;
				   m4->l2=NULL;
				   m4->u1=NULL;
				  t[i].l=m4;	
				}
				else
				{
					if(f==1)
					{
						m1=t[e].l;
						while(m1!=NULL)
						{
						   if(m1->u1!=NULL)
						{
								m2=m1->u1;
								while(m2->u1!=NULL)
								m2=m2->u1;
								if(m2->l1->s==s2)
								{
								m4=new(mid);
								m4->u1=m1;
								m4->l1=NULL;
								m4->l2=NULL;
								t[i].l=m4;break;	
								}
						}
						m1=m1->l2;	
						}
					}
					if(f==0)
					{
						m1=t[e].l;
						while(m1!=NULL)
						{
						  	if(m1->l1->s==s2)
							{
								m4=new(mid);
								m4->u1=m1;
								m4->l2=NULL;
								m4->l1=NULL;
								t[i].l=m4;
						        break;	
							}
							m1=m1->l2;
						}
					}
				}
			}
		else
			{
				m5=t[i].l;
				while(m5->l2!=NULL)
				m5=m5->l2;
				for(int j=i-1;j>=0;j--)
				{
					 m1=t[j].l;
					while(m1!=NULL)
					{
						if(m1->u1!=NULL)
						{
								m2=m1->u1;
								while(m2->u1!=NULL)
								m2=m2->u1;
								if(m2->l1->s==s2)
								{
									d++;
									e=j;f=1;break;
								}
						}
						if(m1->l1!=NULL)
						{
								if(m1->l1->s==s2)
							{	d++;
								e=j;
								f=0;break;}
						}
						if(d!=0)
						break;else
						m1=m1->l2;
							
					}
					if(d!=0)
					break;
				}
				if(d==0)
				{
				   m4=new(mid);
				   m4->l1=new(sub);
				   m4->l1->s=s2;
				   m4->l2=NULL;
				   m4->u1=NULL;
				   m5->l2=m4;	
				}
				else
				{
					if(f==1)
					{
						m1=t[e].l;
						while(m1!=NULL)
						{
						   if(m1->u1!=NULL)
						{
								m2=m1->u1;
								while(m2->u1!=NULL)
								m2=m2->u1;
								if(m2->l1->s==s2)
								{
								m4=new(mid);
								m4->u1=m1;
								m4->l1=NULL;
								m4->l2=NULL;
								m5->l2=m4;break;	
								}
						}
						m1=m1->l2;	
						}
					}
					if(f==0)
					{
						m1=t[e].l;
						while(m1!=NULL)
						{
							if(m1->l1->s==s2)
							{
								m4=new(mid);
								m4->u1=m1;
								m4->l2=NULL;
								m4->l1=NULL;
								m5->l2=m4;
						        break;	
							}
							m1=m1->l2;
						}
					}
				}
			}
			}	
		}
	for(int i=0;i<b;i++)
	{
		m1=t[i].l;
		cout<<"student"<<i+1<<"registered\n";
		if(m1==NULL)
		cout<<"no subjects\n";
		while(m1!=NULL)
		{
			m2=m1->u1;
			if(m2!=NULL)
			{
			   while(m2->u1!=NULL)
			   m2=m2->u1;
			   if(m2->l1!=NULL)
			   cout<<m2->l1->s<<endl;	
			}
			if(m1->l1!=NULL)
			cout<<m1->l1->s<<endl;
			m1=m1->l2;
		}
	}
	return 0;	
	}

