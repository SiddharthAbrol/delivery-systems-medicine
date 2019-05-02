//============================================================================
// Name        : Delivery.cpp
// Author      : Our Group
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : sdfgh.cpp
// Author      : d
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;
#include "Tree.h"
#include "hashing.h"
#include "queue.h"
#include "graph.h"
//#include "graph.h"//
int main()
{
	char y;
		Tree t;
		keyval k;
	hashing h;
	h.create();
		h.set_data();
		h.make();
		string g;
		queue q;
		int p;
	int no,*l;
	cout<<"Enter the number of orders"<<endl;
	cin>>no;
	q.a();
	for(int i=0;i<no;i++)
	{
  k=h.display();
    q.ins(g,k);
	}
	q.display();
	graph obj;
	obj.enter();
	do
	{
	cout<<"\nENTER SOURCE AND DESTINATION VERTEX: ";
	int n,m;
	cin>>n>>m;
	obj.print(n,m);


	cout<<"Do you want to repeat"<<endl;
	cin>>y;
	}
	while(y=='y'||y=='Y');
 return 0;
}
