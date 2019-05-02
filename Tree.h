/*
 * Tree.h
 *
 *  Created on: May 1, 2019
 *      Author: Neena Abrol
 */

#ifndef TREE_H_
#define TREE_H_
#include<iostream>
	#include<string>
	using namespace std;
	class BST {
	    friend class Tree;
	    int cost;
	    int units;
		string data;
		BST *left;
		BST *right;
	};


class Tree {


	BST *root;
		public:
			Tree()
			{
				root=NULL;
			}
			void insertING(string data,int cost,int units);
			void inorder(BST *root);
			void call();
			void create();
			int search(string key);
			int search2(string key);
			void find();
			int calculate(int key);
			int remain(string key,int b);
	};
	void Tree::insertING(string data,int cost,int units)
	{
				BST *tn=new BST;
				tn->data=data;
				tn->left=NULL;
				tn->right=NULL;
				tn->cost=cost;
				tn->units=units;
				if(root==NULL)
				{
					root=tn;
				}
				else
				{
					BST *temp=root;
					BST *p;
					while(temp!=NULL)
					{
						p=temp;
						if(tn->data>temp->data)
						{
							temp=temp->right;
						}
						else if(tn->data<temp->data)
						{
							temp=temp->left;
						}
					}
					if(tn->data<p->data)
					{
						p->left=tn;
					}
					else if(tn->data>p->data)
					{
						p->right=tn;
					}

					}
	}
	void Tree::create()
	{
		insertING("HallsPack",100,30);
		insertING("Mesacol-400",90,300);
		insertING("GalvusMet-50/500",235,500);
		insertING("GalvusMet-50/1000",325,300);
	    insertING("Saridon",10,300);
	    insertING("Volvin",50,230);
	    insertING("Paracetmol",60,290);
	   	insertING("GlizidMod-60",100,400);
	    insertING("Anathesia",50,300);
	    insertING("Injection",60,250);
	    insertING("Tennovate",100,300);
	    insertING("Mesacol-800",100,200);
	    insertING("Jardians-25",500,120);
	    insertING("MedpureXL-50",120,300);
	    insertING("IcePack",90,100);
	    insertING("Crocin",5,500);
	    insertING("Disprin",5,300);
	    insertING("SeaCod",70,100);
	    insertING("Calaptin-25",30,290);
	    insertING("Shanka-Pushpi",150,150);
	    insertING("AloeCream,Gel",200,100);
	    insertING("StrepsilsPack",40,240);
	    insertING("Altroxin100",100,300);
	    insertING("PudinHara",10,200);
	    insertING("Ibuprofen",50,90);
	    insertING("CapsuleMedicines",60,700);
	    insertING("Betadine",50,300);
	    insertING("Savlon",50,300);
	    insertING("Antihistamines",80,300);
	    insertING("Bithionol",40,100);
	    insertING("Antacids",60,600);
	    insertING("Eno",30,500);
	    insertING("Glucon-D",70,400);
		}
	void Tree:: call()
	{
		inorder(root);
	}
	void Tree::inorder(BST *root)
	{
		while(root!=NULL)
		{
			inorder(root->left);
			cout<<root->data<<" "<<root->cost<<" "<<root->units<<endl;
			inorder(root->right);
			break;
		}
	}
	int Tree::search(string key) // @suppress("No return")
	{
		BST *temp=root;
	while(temp!=NULL)
					{
						if(key>temp->data)
						{
							temp=temp->right;
						}
						else if(key<temp->data)
						{
							temp=temp->left;
						}
						else if(key==temp->data)
						{
								return(temp->units);
							break;

						}
					}
					if(temp==NULL)
					{

						return 0;
			}
		}
		int Tree::search2(string key)
	{
		BST *temp=root;
	while(temp!=NULL)
					{
						if(key>temp->data)
						{
							temp=temp->right;
						}
						else if(key<temp->data)
						{
							temp=temp->left;
						}
						else if(key==temp->data)
						{
								return(temp->cost);
							break;

						}
					}
					if(temp==NULL)
					{

						return (0);
			}
		}
		int Tree:: remain(string key,int b)
		{
			BST *temp=root;
	while(temp!=NULL)
					{
						if(key>temp->data)
						{
							temp=temp->right;
						}
						else if(key<temp->data)
						{
							temp=temp->left;
						}
						else if(key==temp->data)
						{
							temp->units=temp->units-b;
								return(temp->units);
							break;

						}
					}
					if(temp==NULL)
					{

						return 0;
			}
		}
	void Tree::find()
	{
		string data;
		int order,money;
		int u,final,payment=0;
		char y,rep;
		cout<<"Checking validity of orders of customers"<<endl;
		do
		{
		cout<<"Enter the product which customer  wants"<<endl;
		cin>>data;
		order=search(data);
		money=search2(data);
		if(order!=0)
		{

			cout<<order <<" Units of medicine are present"<<endl;
			cout<<"Enter the number of units you want"<<endl;
			cin>>u;
			if(u<=order)
			{
			final=u*money;
			cout<<"The cost is "<<final<<endl;
			int remainder=remain(data,u);
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
		cout<<"Do you want to repeat"<<endl;
		cin>>rep;
	}

	while(rep=='y'||rep=='Y');
	}
#endif /* TREE_H_ */
