#include<iostream>
using namespace std;

struct node{

	long long Id;
	string name;
	node *next;
};

class hashing{
	private:
	int size;
	node *head[1000];
	
	public:
	
	hashing()
	{	cout<<"Enter size of table=";
		cin>>size;
		for(int i=0;i<size;i++)
		{
		    head[i]=NULL;
		}
	}

	void insert(long long n,string na)
	{

			node *tmp=new node;
			node *p,*pre;
			long long x=n%size;

			if(head[x]==NULL)
			{
				tmp->Id=n;
				tmp->name=na;
				tmp->next=NULL;
				head[x]=tmp;
			}
			else
			{	p=head[x];
				tmp->Id=n;
				tmp->name=na;
				while(p!=NULL && p->Id<n)
				{	pre=p;
					p=p->next;
				}
				tmp->next=p;
				pre->next=tmp;
			}
		
	}

	void search(long long n)
	{
		long long x=n%size;
		node *tmp=head[x];
		int flag=0;

		while(tmp!=NULL && tmp->Id<=n)
		{
			if(tmp->Id==n)
			{	
				cout<<"Name is "<<tmp->name<<" ID is "<<n<<endl;
				flag=1;
				break;
			}

			tmp=tmp->next;
		}

		if(flag==0)
		cout<<"Not Found"<<endl;

	}
	
	void del(long long id)
	{
		long long x=id%size;
		node *tmp=head[x],*pre;
		int flag=0;
		
		if(tmp->Id==id)
		{
			head[x]=tmp->next;
			delete tmp;
		}
		else
		while(tmp!=NULL && tmp->Id<=id)
		{	
			if(tmp->Id==id)
			{	
				pre->next=tmp->next;
				flag=1;
				delete tmp;
				break;
			}
			pre=tmp;
			tmp=tmp->next;
		}

		if(flag==0)
		cout<<"Not Found"<<endl;
	}

	void showall()
	{
		node *tmp;
		int i,flag=0;
		for(i=0;i<size;i++)
		{	tmp=head[i];
			while(tmp!=NULL)
			{
				cout<<"Name is "<<tmp->name<<" ID is "<<tmp->Id<<endl;
				tmp=tmp->next;
				flag=1;
			}
		}

		if(flag==0)
		cout<<"It is empty...\n\n\n";
	}

	
};
int main()
{
	hashing h;
	string s;
	long long ID,x=1,ope;
	while(x)
	{
		cout<<"Press:-\n1.Insert\n2.Search\n3.Show all \n4.Delete \n5.exit\n";	
		cin>>ope;
		switch(ope)
		{
			case 1:
			cout<<"Enter ID:-";
			cin>>ID;
			cout<<"Enter Name-";
			cin>>s;
			h.insert(ID,s);
			break;
			
			case 2:
			cout<<"Enter ID:-";
			cin>>ID;
			h.search(ID);
			break;

			case 3:
			cout<<"ALL ELEMENTS ARE:-\n";
			h.showall();
			break;

			case 4:
			cout<<"Enter ID:-";
			cin>>ID;
			h.del(ID);
			break;

			case 5:
			x=0;
		}	
	}
	return 0;
}
