#include<iostream>
using namespace std;
union u1;union u2;struct mid;struct stud;struct sub;
union u1
{
mid *l;
sub *m;
};
union u2
{
mid *l;
stud *s;
};
struct mid
{
u1 p;
int tag1;
u2 p2;
int tag2;
};	
struct stud
{
int roll;
mid *l;
stud *s;
};
struct sub
{
int cno;
mid *l;
sub *m;
};
int main()
{
	int a=0,b=0,c,d,e;stud *l1,*s1,*t1;sub *l2,*s2,*t2,*p2;mid *l3,*s3,*t3,*p3;char r;
	do
	{
		cout<<"enter the rollno of student\n";
		cin>>c;
		if(a==0)
		{
			a++;
			l1=new(stud);
			l1->roll=c;
			l1->l=NULL;l1->s=NULL;
			s1=l1;
		}
		else
		{
			t1=new(stud);
			t1->roll=c;
			t1->l=NULL;
			t1->s=NULL;
			l1=t1;
		}
		cout<<"enter the no of subjects registered \n";
		cin>>d;
		for(int i=0;i<d;i++)
		{
			cout<<"enter the course no \n";cin>>e;
			if(b==0)
			{
			    l2=new(sub);
				l2->cno=e;
				l2->m=NULL;l2->l=NULL;s2=l2;l3=new(mid);
				l3->tag1=1;l3->tag2=1;
				l3->p.l=NULL;l3->p2.l=NULL;
				b++;
				t1=l1;l2->l=l3;
				if(t1->l==NULL)
				t1->l=l3;
				else
				{
					t3=t1->l;
					while(t3->p2.l!=NULL)
					t3=t3->p2.l;
					t3->p2.l=l3;
				}
			}
			else
			{
				t2=s2;
				while(t2->m!=NULL)
				{
					if(t2->cno==e)
					break;
					else
					t2=t2->m;
				}
				if(t2->m==NULL)
				{
				     if(t2->cno!=e)
					 {
					 	 l2=new(sub);
				         l2->cno=e;
				         l2->m=NULL;l2->l=NULL;
				         t2->m=l2;l3=new(mid);
				         l3->tag1=1;l3->tag2=1;
				         l3->p.l=NULL;l3->p2.l=NULL;
				         t1=l1;l2->l=l3;
				         if(t1->l==NULL)
				         t1->l=l3;
				         else
				         {
					       t3=t1->l;
				           while(t3->p2.l!=NULL)
					       t3=t3->p2.l;
					       t3->p2.l=l3;
				         }
					 }	
				}
				else
				{
					p2=t2;
					p3=p2->l;
					while(p3->p.l!=NULL)
					p3=p3->p.l;l3=new(mid);
					l3->tag1=1;l3->tag2=1;
				    l3->p.l=NULL;l3->p2.l=NULL;p3->p.l=l3;
				     t1=l1;
				         if(t1->l==NULL)
				         t1->l=l3;
				         else
				         {
					       t3=t1->l;
				           while(t3->p2.l!=NULL)
					       t3=t3->p2.l;
					       t3->p2.l=l3;
				         }
				}
				
			}
		}
		if(l1->l!=NULL)
		{
			t3=l1->l;
			while(t3->p2.l!=NULL)
			t3=t3->p2.l;
			t3->tag2=2;
			t3->p2.s=l1;
		}
		cout<<"continue y or n\n";
		cin>>r;
	}while(r=='y');
	l2=s2;
	while(l2!=NULL)
	{
		if(l2->l!=NULL)
		{
			t3=l2->l;
			while(t3->p.l!=NULL)
			t3=t3->p.l;
			t3->tag1=2;
			t3->p.m=l2;
		}
		l2=l2->m;
	}
	l2=s2;cout<<endl;
	while(l2!=NULL)
	{
		cout<<"the students who registered course no "<<l2->cno<<" are\n";
		t3=l2->l;
		while(t3->tag1!=2)
		{
			p3=t3;
			while(p3->tag2!=2)
			p3=p3->p2.l;
			cout<<p3->p2.s->roll<<endl;
			t3=t3->p.l;
		}
		while(t3->tag2!=2)
			t3=t3->p2.l;
			cout<<t3->p2.s->roll<<endl;
			l2=l2->m;
		
	}
	return 0;
}
