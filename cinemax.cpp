#include <bits/stdc++.h>
using namespace std;
class node
{   public:
    node* next;
    node* prev;
    int seat;
    string id;
    bool status;
};
class cinemax
{
    public:
    node* head,* tail ,* temp;
    cinemax()
    {
        head=NULL;
    }
    void create_list();
    void display();
    void book();
    void cancel();
    void avail();

};
void cinemax::create_list()
{
    int i=1;
    temp=new node;
    temp->seat=1;
    temp->status=false;
    temp->id="null";
    tail=head=temp;
    for(int i=2;i<=70;i++)
    {
       node *p;
       p= new node;
       p->seat=i;
       p->status=false;
       p->id="null";
       tail->next=p;
       p->prev=tail;
       tail=p;
       tail->next=head;
       head->prev=tail;


    }
}
void cinemax::display()
{
    {   int r=1;
        node* temp;
        temp=head;
        int count=0;
        cout<<"\n------------------------------------------------------------------------------------\n";
        cout<<"                                Screen this way                                	     \n";
        cout<<"------------------------------------------------------------------------------------\n";
        while(temp->next!=head)
        {
            if(temp->seat/10==0)
            cout<<"S0"<<temp->seat<<" :";
            else
            cout<<"S"<<temp->seat<<" :";
            if(temp->status==false)
            cout<<"|___| ";
            else
            cout<<"|_B_| ";
            count++;
            if(count%7==0)
            {
            cout<<endl;
            r++;

            }

            temp=temp->next;
        }
            cout<<"S"<<temp->seat<<" :";
            if(temp->status==false)
            cout<<"|___| ";
            else
            cout<<"|_B_| ";

    }
}
void cinemax::book()
{   int x;
    string y;
    label:

    cout<<"\n\n\nEnter seat number to be booked\n";
    cin>>x;
    cout<<"Enter your id number\n";
	cin>>y;
    if(x<1||x>70)
    {
        cout<<"Enter correct seat number to book (1-70)\n";
        goto label;
    }
    node *temp;
    temp=new node;
    temp=head;
    while(temp->seat!=x)
    {
        temp=temp->next;
    }
    if(temp->status==true)
    cout<<"seat already booked!\n";
    else{
    temp->status=true;
    temp->id=y;
    cout<<"seat "<<x<<" booked!\n";
    }


}
void cinemax::cancel()
{
    int x;
	string y;
    label1:
    cout<<"enter seat number to cancel booking\n";
    cin>>x;
    cout<<"enter you id\n";
	cin>>y;
    if(x<1||x>70)
    {
        cout<<"Enter correct seat number to cancel (1-70)\n";
        goto label1;
    }
    node *temp;
    temp=new node;
    temp=head;
    while(temp->seat!=x)
    {
        temp=temp->next;
    }
    if(temp->status==false)
    {
        cout<<"seat not booked yet!!\n";
    }
    else
    {
	if(temp->id==y)
	{
    temp->status=false;
    cout<<"seat cancelled!\n";

	}
	else
	cout<<"wrong user id ,seat cannot be cancelled\n";
    }

}
void cinemax::avail()
{
     int r=1;
        node* temp;
        temp=head;
        int count=0;
        cout<<"\n\n\n\n";
        cout<<"---------------------------------------------------------------------------------------------\n";
        cout<<"                                   		Screen this way                                	\n";
        cout<<"---------------------------------------------------------------------------------------------\n";
        while(temp->next!=head)
			{
					{
					if(temp->seat/10==0)
            		cout<<"S0"<<temp->seat<<" :";
            		else
           			 cout<<"S"<<temp->seat<<" :";
			            if(temp->status==false)
			            cout<<"|___| ";
				    else if(temp->status==true)
			            cout<<"      ";
			            count++;
			            if(count%7==0)
			            {
			            cout<<endl;

			            }


			        }
			         temp=temp->next;
			}
			           if(temp->status==false)
					{
					    cout<<"S"<<temp->seat<<" :";
			            if(temp->status==false)
			            cout<<"|___| ";
					}



}
int main()
{   cinemax obj;
    obj.create_list();
    int ch;
    char c='y';
    while(c=='y')
    {	obj.display();
		cout<<"\n	*********************************************\n";
		cout<<"			  CINEMAX MOVIE THEATRE		  \n";
		cout<<"		*********************************************\n";
	    cout<<"\nEnter choice\n1.Current seat status\n2.Book seat \n3.Available seat\n4.Cancel seat\n";
	    cin>>ch;
	    switch(ch)
	    {
	        case 1:obj.display();
	                break;
	        case 2:	obj.book();
	                break;
	        case 3:obj.avail();
	                break;
	        case 4:	obj.cancel();
	                break;
	        default: cout<<"Wrong choice input\n";
	    }
	    cout<<"\nWant operation again (y/n)\n";
	    cin>>c;
		system("clear");
    }

	return 0;
}
