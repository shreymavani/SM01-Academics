#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct item{
    
    long long item_id;
    string p_name;
    long rate;
    int quantity;
    item *next;
};

struct data{
    long long customer_id;
    string c_name;
    long long points;
    data *next;
};

class customer{
    private:
    data *start[13];
    int size1;    
    public:
    customer()
    {    size1=13;
        for(int i=0;i<size1;i++)
        {
            start[i]=NULL;
        }
    }

    data** getstart()
    {    
        return start;
    }
    
    void putstart(data *st[])
    {
        for(int i=0;i<size1;i++)
        {
            start[i]=st[i];
        }
    }

    void Add_customer(long long n,string na,long pt)
    {

            data *tmp=new data;
            data *p,*pre=NULL;
            long long x=n%size1;

            tmp->customer_id=n;
            tmp->c_name=na;
            tmp->points=pt;
            if(start[x]==NULL)
            {
                tmp->next=NULL;
                start[x]=tmp;
            }
            else
            {    p=start[x];
                
                while(p!=NULL && p->customer_id<n)
                {    pre=p;
                    p=p->next;
                }
                tmp->next=p;
                pre->next=tmp;
            }
        
    }

    void update_points(long long n,long long amountpaid)
    {
        long long x=n%size1;
        data *tmp=start[x];
        int flag=0;

        while(tmp!=NULL && tmp->customer_id<=n)
        {
            if(tmp->customer_id==n)
            {    tmp->points=tmp->points+amountpaid;
                cout<<"Name :- "<<tmp->c_name<<" ID :- "<<n<<" updated points="<<tmp->points<<endl;
                
                flag=1;
                break;
            }

            tmp=tmp->next;
        }

        if(flag==0)
        cout<<"Not Found"<<endl;
    }
    
    void showallCustomerinfo()
    {
        data *tmp;
        int i,flag=0;
        cout<<"\nCustomer ID       Customer Name       Points"<<endl;
        for(i=0;i<size1;i++)
        {    tmp=start[i];
            while(tmp!=NULL)
            {
            cout<<" "<<tmp->customer_id<<"            "<<tmp->c_name<<"               "<<tmp->points<<endl;                                       
                                
                tmp=tmp->next;
                flag=1;
            }
        }

        if(flag==0)
        cout<<"It is empty...\n\n\n";
    }

    
    data *search_customer(long long n)
    {
        
        long long x=n%size1;
        data *tmp=start[x];
        int flag=0;

        while(tmp!=NULL && tmp->customer_id<=n)
        {
            if(tmp->customer_id==n)
            {
                flag=1;
                break;
            }

            tmp=tmp->next;
        }
        
        if(flag==0)
        tmp=NULL;
        return tmp;
    }
};

class inventory{
    
    private:
    item *head[13];
    int size;
    public:
    inventory()
    {    size=13;
        for(int i=0;i<size;i++)
        {
            head[i]=NULL;
        }
    }
    
    item** gethead()
    {    
        return head;
    }
    
    void puthead(item *st[])
    {
        for(int i=0;i<size;i++)
        {
            head[i]=st[i];
        }
    }
    

    void Add_item(long long n,string na,long r,long qua)
    {

            item *tmp=new item;
            item *p,*pre=NULL;
            long long x=n%size;
            
            tmp->item_id=n;
            tmp->p_name=na;
            tmp->rate=r;
            tmp->quantity=qua;
    
            if(head[x]==NULL)
            {    
                tmp->next=NULL;
                head[x]=tmp;
            }
            else
            {    p=head[x];
            
                while(p!=NULL && p->item_id<n)
                {    pre=p;
                    p=p->next;
                }
                tmp->next=p;
                pre->next=tmp;
            }
    }
    
    
    void  update_item(long long n)
    {
        long long x=n%size;
        item *tmp=head[x];
        int flag=0;
        long com;
        while(tmp!=NULL && tmp->item_id<=n)
        {
            if(tmp->item_id==n)
            {    
                cout<<"press:-1)To change Rate\n2)To change stock"<<endl;
                cin>>com;
                if(com==1)
                {
                    cout<<"Enter new rate=";
                    cin>>com;
                    tmp->rate=com;
                }
                else if(com==2)
                {
                    cout<<"Enter new stock=";
                    cin>>com;
                    tmp->quantity=com;
                }
            }

            tmp=tmp->next;
        }
        if(flag==0)
        cout<<"Not Found"<<endl;
    }
    
    void delete_item(long long id)
    {
        long long x=id%size;
        item *tmp=head[x],*pre=NULL;
        int flag=0;
        
        if(tmp->item_id==id)
        {
            head[x]=tmp->next;
            delete tmp;
        }
        else
        while(tmp!=NULL && tmp->item_id<=id)
        {    
            if(tmp->item_id==id)
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

    void showallProductinfo()
    {
        item *tmp;
        int i,flag=0,x=0;
        cout<<"                            ITEM LIST                     \n\n";
            cout<<"\nProduct ID       Product Name      Quantity        Rate"<<endl;
            for(i=0;i<size;i++)
        {    tmp=head[i];
            x=x+1;
            while(tmp!=NULL)
            {
                
                    cout<<" "<<tmp->item_id<<"       "<<tmp->p_name<<"               "<<tmp->quantity<<"            "<<tmp->rate<<endl;                              tmp=tmp->next;
                flag=1;
            }
        }

        if(flag==0)
        cout<<"It is empty...\n\n\n";
    }
    
    void update_stock(long long n,long stock,long command)
    {
        long long x=n%size;
        item *tmp=head[x];
        int flag=0;

        while(tmp!=NULL && tmp->item_id<=n)
        {
            if(tmp->item_id==n)
            {    
        
                flag=1;
                if(command==1)
                {
                    tmp->quantity=tmp->quantity+stock;
                }
                else
                {
                    tmp->quantity=tmp->quantity-stock;
                }                
                break;
            }


            tmp=tmp->next;
        }

        if(flag==0)
        cout<<"Not Found"<<endl;
    }
        
    void Get_Product_info(long long n)
    {
        long long x=n%size;
        item *tmp=head[x];
        int flag=0;
 
        while(tmp!=NULL && tmp->item_id<=n)
        {
            if(tmp->item_id==n)
            {
            cout<<"                            ITEM LIST                     \n";
            cout<<"\nProduct ID       Product Name      Quantity        Rate"<<endl;
            cout<<" "<<tmp->item_id<<"       "<<tmp->p_name<<"               "<<tmp->quantity<<"            "<<tmp->rate<<endl<<endl;                                       
                flag=1;
                break;
            }

            tmp=tmp->next;
        }

        if(flag==0)
        cout<<"--------Empty Not Found--------";
        
    }
    item* Search_Product_info(long long n)
    {
        long long x=n%size;
        item *tmp=head[x];
        int flag=0;
 
        while(tmp!=NULL && tmp->item_id<=n)
        {
            if(tmp->item_id==n)
            {            
                flag=1;
                break;
            }

            tmp=tmp->next;
        }

        if(flag==0)
        tmp=NULL;

    return tmp;
        
    }
    
};

class billing:public inventory,public customer{
    
    private:
    friend class manager;
    static long long c_id;
    public:
    
    void Add_item(long long n,string na,long r,long qua)=delete;
    void  update_item(long long n)=delete;
    void delete_item(long long id)=delete;
    

    void buy_item(data *cusid)
    {    
        vector<item *> prod;
        vector<long long> p_q;
        char rem,req;
        item *info;
        long long x=1,in_id,q;
        while(x)
        {
            cout<<"Enter id of product=";
            cin>>in_id;
            cout<<"Enter quantity of item=";
            cin>>q;
            info=Search_Product_info(in_id);            
            prod.push_back(info);
            p_q.push_back(q);
            cout<<"want to add other item,press 1 else 0:-";
            cin>>x;
        }
        
         display_itemlist(prod,p_q);

        cout<<"\n\nWant to remove any product?y/n:-";
        cin>>rem;
        cout<<"Want to reduce quantity of any product?y/n:-";        
        cin>>req;
        while(rem=='y' || rem=='Y' || req=='y'||rem=='Y')        
        {    cout<<"Enter Id of product=";
            cin>>in_id;
            if(rem=='y' || rem=='Y')
            for(long unsigned int i=0;i<prod.size();i++)
            {    if(prod[i]->item_id==in_id)
                {    
                prod.erase(prod.begin()+i);
                p_q.erase(p_q.begin()+i);    
                break;
                }
            }
            
            if(req=='y' || req=='Y')
            for(long unsigned int i=0;i<prod.size();i++)
            {    if(prod[i]->item_id==in_id)
                {
                cout<<"Enter number of quantity:-";    
                cin>>q;
                p_q[i]=q;    
                break;
                }
                
            }
            cout<<"Want to remove any other product?y/n";
            cin>>rem;    
            cout<<"Want to reduce quantity of any other product?y/n:-";        
            cin>>req;
        }    
        makebill(cusid,prod,p_q);
        
    }
    
    void display_itemlist(vector<item*>p_id,vector<long long>p_q)
    {    long long Total=0;
        cout<<"\n---------------------------------------------------------------------------------------\n";
        cout<<"                            ITEM LIST                     \n\n";
        cout<<"\nProduct ID       Quantity       Rate          Amount"<<endl;
        if(p_id.size()!=0){
        for(long unsigned int i=0;i<p_id.size();i++)
        {
            cout<<p_id[i]->item_id<<"         "<<p_q[i]<<"          "<<p_id[i]->rate<<"            "<<p_q[i]*(p_id[i]->rate)<<endl;
            Total=Total+p_q[i]*(p_id[i]->rate);
        }
        cout<<"\n\n\n                              Total Amount="<<Total<<endl;
        }
        else
        cout<<"No Item selected\n";
            
        cout<<"-----------------------------------------------------------------------------------------\n";        
    }
    void assign_customer_id()
    {    
        static long long c_id=2019010001;
        string na;
        cout<<"Enter new customer name=";
        cin>>na;
        Add_customer(c_id,na,0);
        c_id=c_id+1;
    }
    void makebill(data *cusid,vector<item*>p_id,vector<long long>p_q)
    {    long long Total=0;
        cout<<"-----------------------------------------------------------------------------------------\n";
        cout<<"                              BILL                                 \n"<<endl;        
        cout<<"Customer Name-"<<cusid->c_name<<"               "<<"Customer ID-"<<cusid->customer_id<<endl;
        cout<<"\nProduct ID       Quantity       Rate          Amount"<<endl;
        if(p_id.size()!=0)        
        {
        for(long unsigned int i=0;i<p_id.size();i++)
        {
            cout<<p_id[i]->item_id<<"         "<<p_q[i]<<"          "<<p_id[i]->rate<<"            "<<p_q[i]*(p_id[i]->rate)<<endl;
            Total=Total+p_q[i]*(p_id[i]->rate);
            update_stock(p_id[i]->item_id,p_q[i],2);
        }
        cusid->points=cusid->points+Total;
        cout<<"\n\n\nTotal points="<<cusid->points<<"           Total Amount="<<Total;
        }
        else
        cout<<"No Item selected\n";

        cout<<"\n                     THANKS YOU "<<endl;
        cout<<"-----------------------------------------------------------------------------------------\n";    
            
    }

    
 
};

class manager:public inventory,public customer{
    
    private:
    long long ID;
    string password;    
    
    public:
    manager()
    {    ID=202301224;
        password="Shrey@01234";
    }
    
    int check_id_pass(long long id,string pass)
    {    int flag=0;
        if(id!=ID)
        cout<<"\n-------Entered ID don't exist........."<<endl;
        else if(pass!=password)
        cout<<"\n-------Entered password is wrong........."<<endl;
        else
        {
            cout<<"Access granted....."<<endl;
            flag=1;                    
        }
        return flag;
    }    
    
};

int main()
{
    billing b;
    manager m;
    data *cus;
    char re;
    long long Mid,i,loo=1,swi_ma,cusid,com=1,check,item_id,item_rate,item_qua;
    string Mpass,item_name;
    long INVENTORY_DATASET[100][4] = {
{111100000001,1,100,20},{111100000002,2,110,20},{111100000003,3,120,20},{111100000004,4,130,20},{111100000005,5,140,20},{111100000006,6,150,20},{111100000007,7,160,20},{111100000008,8,170,20},{111100000009,9,180,20},{111100000010,10,190,20},
{111100000011,11,200,20},{111100000012,12,210,20},{111100000013,13,220,20},{111100000014,14,230,20},{111100000015,15,240,20},{111100000016,16,250,20},{111100000017,17,260,20},{111100000018,18,270,20},{111100000019,19,280,20},{111100000020,20,290,20},
{111100000021,21,300,20},{111100000022,22,310,20},{111100000023,23,320,20},{111100000024,24,330,20},{111100000025,25,340,20},{111100000026,26,350,20},{111100000027,27,360,20},{111100000028,28,370,20},{111100000029,29,380,20},{111100000030,30,390,20},
{111100000031,31,400,20},{111100000032,32,410,20},{111100000033,33,420,20},{111100000034,34,430,20},{111100000035,35,440,20},{111100000036,36,450,20},{111100000037,37,460,20},{111100000038,38,470,20},{111100000039,39,480,20},{111100000040,40,490,20},
{111100000041,41,500,20},{111100000042,42,510,20},{111100000043,43,520,20},{111100000044,44,530,20},{111100000045,45,540,20},{111100000046,46,550,20},{111100000047,47,560,20},{111100000048,48,570,20},{111100000049,49,580,20},{222200001111,50,590,20},
{222200001114,51,600,20},{222200001117,52,610,20},{222200001120,53,620,20},{222200001123,54,630,20},{222200001126,55,640,20},{222200001129,56,650,20},{222200001132,57,660,20},{222200001135,58,670,20},{222200001138,59,680,20},{222200001141,60,690,20},
{222200001144,61,700,20},{222200001147,62,710,20},{222200001150,63,720,20},{222200001153,64,730,20},{222200001156,65,740,20},{222200001159,66,750,20},{222200001162,67,760,20},{222200001165,68,770,20},{222200001168,69,780,20},{222200001171,70,790,20},
{222200001174,71,800,20},{222200001177,72,810,20},{222200001180,73,820,20},{222200001183,74,830,20},{222200001186,75,840,20},{222200001189,76,850,20},{222200001192,77,860,20},{222200001195,78,870,20},{222200001198,79,880,20},{222200001201,80,890,20},
{222200001204,81,900,20},{222200001207,82,910,20},{222200001210,83,920,20},{222200001213,84,930,20},{222200001216,85,940,20},{222200001219,86,950,20},{222200001222,87,960,20},{222200001225,88,970,20},{222200001228,89,980,20},{222200001231,90,990,20},
{222200001234,91,1000,20},{222200001237,92,1010,20},{222200001240,93,1020,20},{222200001243,94,1030,20},{222200001246,95,1040,20},{222200001249,96,1050,20},{222200001252,97,1060,20},{222200001255,98,1070,20},{222200001258,99,1080,20},{222200001261,100,1090,20},
};
    
    long CUSTOMER_DATASET[100][3] = {
{9400000001,1,0},{9400000002,2,0},{9400000003,3,0},{9400000004,4,0},{9400000005,5,0},{9400000006,6,0},{9400000007,7,0},{9400000008,8,0},{9400000009,9,0},{9400000010,10,0},
{9400000011,11,0},{9400000012,12,0},{9400000013,13,0},{9400000014,14,0},{9400000015,15,0},{9400000016,16,0},{9400000017,17,0},{9400000018,18,0},{9400000019,19,0},{9400000020,20,0},
{9400000021,21,0},{9400000022,22,0},{9400000023,23,0},{9400000024,24,0},{9400000025,25,0},{9400000026,26,0},{9400000027,27,0},{9400000028,28,0},{9400000029,29,0},{9400000030,30,0},
{9400000031,31,0},{9400000032,32,0},{9400000033,33,0},{9400000034,34,0},{9400000035,35,0},{9400000036,36,0},{9400000037,37,0},{9400000038,38,0},{9400000039,39,0},{9400000040,40,0},
{9400000041,41,0},{9400000042,42,0},{9400000043,43,0},{9400000044,44,0},{9400000045,45,0},{9400000046,46,0},{9400000047,47,0},{9400000048,48,0},{9400000049,49,0},{9400000050,50,0},
{9400000051,51,0},{9400000052,52,0},{9400000053,53,0},{9400000054,54,0},{9400000055,55,0},{9400000056,56,0},{9400000057,57,0},{9400000058,58,0},{9400000059,59,0},{9400000060,60,0},
{9400000061,61,0},{9400000062,62,0},{9400000063,63,0},{9400000064,64,0},{9400000065,65,0},{9400000066,66,0},{9400000067,67,0},{9400000068,68,0},{9400000069,69,0},{9400000070,70,0},
{9400000071,71,0},{9400000072,72,0},{9400000073,73,0},{9400000074,74,0},{9400000075,75,0},{9400000076,76,0},{9400000077,77,0},{9400000078,78,0},{9400000079,79,0},{9400000080,80,0},
{9400000081,81,0},{9400000082,82,0},{9400000083,83,0},{9400000084,84,0},{9400000085,85,0},{9400000086,86,0},{9400000087,87,0},{9400000088,88,0},{9400000089,89,0},{9400000090,90,0},
{9400000091,91,0},{9400000092,92,0},{9400000093,93,0},{9400000094,94,0},{9400000095,95,0},{9400000096,96,0},{9400000097,97,0},{9400000098,98,0},{9400000099,99,0},{9400000100,100,0},
};

    for(i=0;i<100;i++)
    m.Add_item(INVENTORY_DATASET[i][0],to_string(INVENTORY_DATASET[i][1]),INVENTORY_DATASET[i][2],INVENTORY_DATASET[i][3]);

    for(i=0;i<100;i++)
    m.Add_customer(CUSTOMER_DATASET[i][0],to_string(CUSTOMER_DATASET[i][1]),CUSTOMER_DATASET[i][2]);
    
    b.putstart(m.getstart());      //linking of item database 
    b.puthead(m.gethead());        //linking of customer database
    
    
    //Copy paste this input in (HACKERRANK) for given output:-1 9400000011 111100000011 3 1 222200001114 1 1 222200001234 2 0 n n 2 202301224 Shrey@01234 5 111100000011 5 222200001114 5 222200001234 8 3
    

{                        //GENERALIZED CODE FOR SHOPPING WITH MANAGER ID AND PASSWORD
Home_bar:
    cout<<"Press:-1)Customer 2)Manager  3)exit program:-";
    cin>>com;    
    
    if(com==2)
    {
    id_pass:
        cout<<"Enter yr manager id=";
        cin>>Mid;
        cout<<"Enter password=";
        cin>>Mpass;
        check=m.check_id_pass(Mid,Mpass);
        if(check==0)
        {
            cout<<"\n\n....Want to enter again or go back to home bar?\nPress:-a to enter again else any-other key to go to home bar:-"<<endl;
            cin>>re;            
            if(re=='a')
            goto id_pass;
            else
            goto Home_bar;
        }
        while(loo)        
        {
        cout<<"Press:1)Add item\n      2)delete item\n      3)Update item\n      4)Update stock\n      5)One Product info\n      6)All Product info\n      7)All Customer info\n      8)Back to Home bar"<<endl;
        cin>>swi_ma;
        switch(swi_ma)
        {
            case 1:
            cout<<"Enter item name=";
            cin>>item_name;
            cout<<"Enter item id=";
            cin>>item_id;
            cout<<"Enter quantity=";
            cin>>item_qua;
            cout<<"Enter item rate=";
            cin>>item_rate;        
            m.Add_item(item_id,item_name,item_rate,item_qua);
            break;

            case 2:
            cout<<"Enter item id=";
            cin>>item_id;
            m.delete_item(item_id);
            break;
        
            case 3:
            cout<<"Enter item id=";
            cin>>item_id;
            m.update_item(item_id);
            break;
            
            case 4:
            cout<<"Enter item id=";
            cin>>item_id;
            cout<<"To Add stock press(1) and To remove press(2):-"<<endl;
            cin>>item_rate;
            cout<<"Enter quantity=";
            cin>>item_qua;
            m.update_stock(item_id,item_qua,item_rate);    
            break;
            
            case 5:
            cout<<"Enter item id=";
            cin>>item_id;
            m.Get_Product_info(item_id);
            break;                
                    
            case 6:
            b.showallProductinfo();
            break;
            
            case 7:
            b.showallCustomerinfo();
            break;
                                        
            case 8:
            goto Home_bar;
        }
        }    
    }        
    else if(com==1)
    {
    cout<<"Enter Customer ID=";
    cin>>cusid;    
    cus=b.search_customer(cusid);
    b.buy_item(cus);
    goto Home_bar;
    }
    
    }    
    return 0;
}
//Copy paste this input in (HACKERRANK) for given input of this assignment:-1 9400000011 111100000011 3 1 222200001114 1 1 222200001234 2 0 n n 2 202301224 Shrey@01234 5 111100000011 5 222200001114 5 222200001234 8 3
