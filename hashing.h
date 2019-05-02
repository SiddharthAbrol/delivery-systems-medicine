/*
 * hashing.h
 *
 *  Created on: May 1, 2019
 *      Author: Neena Abrol
 */


#ifndef HASHING_H_
#define HASHING_H_
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
class keyval //Class to create data
{
	friend class hashing;
	friend class queue;
	char name[30];
	int id,password;
	string location;
public:
};
class hashing//Cass to create the hash functions
{
	friend class queue;
	int *flag,size,constant,no,mkey;
	keyval *a;
	char z;
	public:
		hashing() // @suppress("Class members should be properly initialized")
		{
			constant=0;
			no=0;
		}
		int hashfn(int d,int b)
		{
			int c;
			c=d%b;
			return c;
		}
		void create()//Function to create the array of data and array of allocated data
		{

			size=150;
			a=new keyval[size];
			flag=new int[size];
			constant=1;
			for(int i=0;i<size;i++)
			{
				flag[i]=0;
			}

		}
		int empty()
		{
			int a;
			for(int i=0;i<size;i++)
			{
				if(flag[i]==0)
				{
					a=1;
				}
				else
				{
					a=0;
					break;
				}
			}
			if(a==1)
			{
				return 1;
			}
			else if(a==0)
			{
				return 0;
			}
		}
		void insert(int id, int pass, const char *str,string loc)//Insert procedure of data
		{
            size=150;
			int rem;
			rem=hashfn(id,size);
			if(flag[rem]==0)
			{
			strcpy(a[rem].name,str);
			a[rem].id=id;
			a[rem].password=pass;
			a[rem].location=loc;
				flag[rem]=1;
				no++;			}
			else if(flag[rem]==1)
			{
				int i=0;

				while(flag[rem]!=0)
				{
				rem=hashfn(id+i,size);
				i++;
				}
				if(search(id)==-1)
				{
			strcpy(a[rem].name,str);
			a[rem].id=id;

			a[rem].password=pass;
				flag[rem]=1;
				no++;
			}
			}
}
void set_data()//Inserting th data of predefined customers
{
insert(2348,62,"MedPlus","Pulgate");
insert(936,32,"Metro_Chemist","Kondhwa");
insert(428,22,"Dixit_Medicals","Khadakwasla");
insert(912,12,"Avanti_Drugs","Deccan");
insert(805,152,"Roy_Stores","NIBM");
insert(3369,82,"Mukesh_Medicals","Koregaon_Park");
insert(962,72,"Vandana_Medicals","Kalyani_Nagar");
insert(2681,52,"Medico_Point","Saras_Bag");
insert(515,212,"Apollo_Pharmacy","Hadapsar");
insert(101,192,"Ghosh_Medicals","Wanworie");
insert(1019,112,"Wellness_Forever","Salunkhe_Vihar");
insert(5063,172,"Alankar_Stores","Bibwewadi");
insert(8196,202,"Neena_Medicals","Shivaji_Nagar");
insert(3333,222,"Sahyadri_Hospital","Alandi");
insert(124,252,"Hari_Stores","Fatima_Nagar");
}
		void make()
		{
			int id,age,pass;
			char s1[30],rep;
			string l;
			if(constant==0)
			{
				cout<<"Hash table not created"<<endl;
			}
			else
			{
			if(no!=size)
			{
			insert(id,pass,s1,l);
		}
		else
		{
			cout<<"Overflow"<<endl;
		}
	}
		}

		int search(int key)//Search function to display and update according to id
		{

			int finder,i=0;
			finder=hashfn(key,size);
			while(i<=size)
			{
			if(a[finder].id==key)
			{
				return finder;
			}
			else
			{
					finder=hashfn(key+i,size);
					i++;
				}
			}
			return (-1);

		}
		keyval display()
		{
		    if(constant==0)
			{
				cout<<"Hash table not created"<<endl;
			}
			else
			{
			 if(empty()==1)
			{
				cout<<"Hash table empty"<<endl;
			}
			else
			{
			    cout<<"Enter the ID: ";
			    cin>>mkey;
			    int loc=search(mkey);
				if(loc!=-1)
				{
					cout<<"Location no "<<loc<<" is"<<endl;
				cout<<"Name:"<<a[loc].name<<endl;
				cout<<"ID: "<<a[loc].id<<endl;
                cout<<"Password: "<<a[loc].password<<endl;
                cout<<"Location: "<<a[loc].location<<endl;
                return(a[loc]);
		}
				else if(loc==-1)
				{
					cout<<"System terminated due to wrong ID"<<endl;
					exit(0);
					}
			}
		}
        }
void copy()
{
	fstream fout;
	fout.open("customers.txt",ios::app);
	if(fout.is_open())
{
	for(int i=0;i<size;i++)
	{
		if(flag[i]==1)
		{
			fout<<"Location no "<<i<<" is"<<endl;
							fout<<"Name:"<<a[i].name<<endl;
							fout<<"ID: "<<a[i].id<<endl;
			                fout<<"Password: "<<a[i].password<<endl;
			                fout<<"Location: "<<a[i].location<<endl;
		}
	}
}
	fout.close();
}

};

#endif /* HASHING_H_ */
