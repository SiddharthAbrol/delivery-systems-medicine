/*
 * queue.h
 *
 *  Created on: May 1, 2019
 *      Author: Neena Abrol
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include<iostream>
#include<fstream>

	#include<string>
#include<cstring>
#include "Tree.h"

	using namespace std;
class node
{
friend class queue;
	string med[20],location;
	int rate;
	int quantity[20];
	char name[30];
	node *next;
};
node *front;
	node *rear;
class queue {
public:
Tree t;
hashing h;
keyval k;
int no,j=0,*lo;
string locs[20];
queue()
{
}
void a()
{
	t.create();
}

	void ins(string data,keyval k)
	{
		node *temp=new node;
		int order,money,u,final,payment=0;
		char y;
		cout<<"Enter the number of medicines:";
		cin>>no;
		for(int i=0;i<no;i++)
		{
			;
			cout<<"Enter the product which customer  wants"<<endl;
					cin>>data;
					 order=t.search(data);
					money=t.search2(data);
					if(order!=0)
					{

						cout<<order <<" Units of medicine are present"<<endl;
						cout<<"Enter the number of units you want"<<endl;
						cin>>u;
						if(u<=order)
						{
						final=u*money;
						cout<<"The cost is "<<final<<endl;
						int remainder=t.remain(data,u);
						payment=payment+final;
					}
					else
					{
						cout<<"Maximum units are "<<order<<endl;
						cout<<"Would you accept it?Enter y or n"<<endl;
						cin>>y;
						if(y=='y'||y=='Y')
						{
							final=order*money;
							cout<<"Total cost is "<<final<<endl;
							payment=payment+final;
						}
						else
						{
							cout<<"Particular Order rejected"<<endl;
						}
					}
					}
					else
					{
						cout<<" Medicine is not present"<<endl;
					}
					cout<<"Total payment as of now"<<endl;
					cout<<"Rs."<<payment<<endl;
					temp->med[i]=data;
					temp->quantity[i]=u;
					temp->rate=payment;
					strcpy(temp->name,k.name);
					temp->location=k.location;
				}
		temp->next=NULL;
			if(front==NULL)
			{
				front=temp;
				rear=temp;
			}
			else
			{
				rear->next=temp;
				rear=temp;
			}
		}
	void display()
	{
		fstream fout;
		fout.open("orders.txt",ios::app);
		node *temp=front;
		cout<<"Summary of all orders"<<endl;
		while(temp!=NULL)
		{

			        if(fout.is_open())
			        {
			        	fout<<"Name:"<<temp->name<<"\n";
			        	fout<<"Location:"<<temp->location<<endl;
			        	fout<<"Medicines ordered"<<"\n";
			        				for(int i=0;i<no;i++)
			        				{
			        					fout<<"Name:"<<temp->med[i]<<"\n";
			        					fout<<"Location: "<<temp->quantity[i]<<"\n";
			        				}
			        				fout<<"Total payment is Rs. "<<temp->rate<<"\n";
			        }
			cout<<"Orders of shop "<<temp->name<<" at location "<<temp->location<<" is"<<endl;
			for(int i=0;i<no;i++)
			{
				cout<<temp->med[i]<<endl;
			}
			cout<<"Total payment is Rs. "<<temp->rate<<endl;
			temp=temp->next;
		}
		fout.close();

	}


};

#endif /* QUEUE_H_ */
