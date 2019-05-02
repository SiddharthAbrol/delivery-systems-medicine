/*
 * graph.h
 *
 *  Created on: May 1, 2019
 *      Author: Neena Abrol
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>

using namespace std;

class stack_node
{
    public:
        int data;
        stack_node* next;

        stack_node()
        {
            next = NULL;
        }
    friend class stack;
};

class stack
{
    public:
        stack_node* top;
        stack()
        {
            top = NULL;
        }

        friend class Dijkstras;
        void push(int s);
        int pop();
        int empty();
};

int stack::empty()
{
    if(this->top == NULL)
        return 1;
    else
        return 0;
}

void stack::push(int s)
{
    stack_node* temp = top;
    stack_node* n = new stack_node;
    n->data = s;
    top = n;
    n->next = temp;
}

int stack::pop()
{
    stack_node* temp = top;
    top = top->next;
    temp->next = NULL;
    return temp->data;
}

class graph
{
private:
    int visited[20]; //visited array will store if node is visited or not
    int dist[20]; // it will be initialized with a max value at beginning
    int parent[200]; //to store the vertext because of which the vertext got updated
    int nodes; //number of nodes
    int edges; // number of edges
    int adjacency[20][20];
    char city[50][20];

public:
    graph() // initializing all arrays and variables
    {


        for(int i = 0; i<20; i++)
            for(int j= 0; j<20; j++)
                adjacency[i][j] = 0; //initializing adjacency matrix to zero

    }

void enter(); // will prepare adjacency matrix of weighted graph
void print(int src, int dest); // will print the output of classic djikstra algo (shortest path distance and the path)



};





void graph::print(int src, int dest)
{
    for(int i=0; i<nodes; i++)
        {
            dist[i] = 1000; //initialize distance array
            visited[i] = 0; //initialize visited array
        }
    dist[src] = 0;
    parent[dest] = dest;

    int min = 0; //to store unvisited vertex which has minimum distance

    for(int i = 0; i< (nodes - 1); i++) //pick vertex with min dist, update dist of it's adjacent nodes, update parents etc, nodes-1 times
    {
        for(int j = 0; j<nodes; j++)
        {
            if(dist[j] < dist[min] && visited[j] == 0)
                min = j;
        }

        visited[min] = 1;

        for(int j = 0 ; j<nodes; j++)
        {
            if(adjacency[min][j] != 0 && dist[j] > dist[min] + adjacency[min][j]) //if edge exists and the dist of node can be relaxed, relax it and update the parent
            {
                dist[j] = dist[min] + adjacency[min][j];
                parent[j] = min;
            }
        }

        for(int k = 0; k<nodes; k++) //find an unvisited vertex and store min at that vertex
        {
            if(visited[k] == 0)
            {
                min = k;
                break;
            }
        }
    }

    //push the path onto the stack such that top is source and bottom is the destination
    stack s;
    s.push(dest);
    int m = dest;
    while(parent[m] != src)
    {
        s.push(parent[m]);
        m = parent[m];

    }

    s.push(src);

    //displaying the shortest path and it's length
    cout<<"\nTHE SHORTEST PATH-LENGTH FROM "<<city[src]<<" TO "<<city[dest]<<" IS: "<<dist[dest]<<endl;
    cout<<"\nSHORTEST PATH IS: "<<s.pop() <<endl;
    fstream fout;
    fout.open("orders.txt",ios::app);
    if(fout.is_open())
    			        {
    fout<<"\nTHE SHORTEST PATH-LENGTH FROM "<<city[src]<<" TO "<<city[dest]<<" IS: "<<dist[dest];
       fout<<"\nSHORTEST PATH IS: "<<s.pop();
    			        }
    fout.close();
    while(!s.empty())
    {
        cout<<"-"<<s.pop();
    }


}

void graph::enter()
{

            cout<<"\nENTER THE NUMBER OF LOCATIONS INCLUDING THE FACTORY. ";
            cin>>nodes;
            cout<<"\nENTER THE NUMBER OF EDGES. ";
            cin>>edges;
        		cout<<"Enter the locations one by one"<<endl;
        		for(int i=0;i<nodes;i++)
        		{
        			cin>>city[i];
        		}
        		cout<<"The cities in order of entry are"<<endl;
        		for(int i=0;i<nodes;i++)
        		{
        			cout<<city[i]<<"-"<<i<<endl;
        		}
            cout<<"\nENTER THE LOCATIONS THROUGH NUMBERS AND DISTANCE BETWEEN THEM. (e.g. FOR EDGE BETWEEN 0 AND 1 OF WEIGHT 5, ENTER 0 1 5)"<<endl;

            for(int i = 0; i<edges; i++)
            {
                int v1, v2, weight;
                cin>>v1>>v2>>weight;
                adjacency[v1][v2] = weight;
                adjacency[v2][v1] = weight;
            }
}


#endif /* GRAPH_H_ */
