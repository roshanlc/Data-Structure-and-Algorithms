//stack implementation using linked list
//stack to store int values
#include<iostream>
using namespace std;

class node
{               //node to create linked list
    public:
    int value;
    node *link;
};

node *top=NULL;  //store the address of topmost node in the stack
node *tempNode;  //a temporary node

int isEmpty()  //function to check if the stack is empty
{
    if(top==NULL) return 1;
    else return 0;
}

node *createNode(int x) //function to create a new node
{
    tempNode = new node;
    tempNode->value = x;
    tempNode->link = NULL;
    return tempNode;
}

void push(node *x) //function to insert an item into the stack
{

 if(top==NULL)
    {
        top = x;
        top->link=NULL;
    }
    else
    {
        x->link = top;
        top = x;
    }
}

void pop() //function to remove the topmost item from stack
{
    if(isEmpty() )
    {
        cout<<"Illegal operation: Stack Underflow"<<endl;
    }
    else
    {
        tempNode = top;
        top=top->link;
        delete tempNode;
    }
}

void displayStack() //traverse and display each item of stack
{
    tempNode = top;
    if(isEmpty() == 1)
    {
        cout<<"Illegal operation: Empty Stack!"<<endl;
    }
    else
    {
        while(tempNode!=NULL)
        {
            cout<<tempNode->value<<"\t";
            tempNode = tempNode->link;
        }
    }

}

                    //function to delete all items of stack,
void deleteAll()    // mainly used to delete the dynamically created nodes at the time of program exit
{
	if(!isEmpty())
	{
	    tempNode = top;
        while(tempNode!=NULL)
        {
        top=top->link;
        delete tempNode;
        tempNode=top;
        }
	}
}

void search() //function to search for an specific item in the stack
{
    if(isEmpty())
    {
        cout<<"Illegal operation: Stack underflow!"<<endl;
    }
    else
    {
        int t,c;
        cout<<"Enter item to search for :";
        cin >>t;
        while(tempNode!=NULL)
        {
            if(t == tempNode->value)
            {
                cout<< "Item found!"<<endl;
                c=1;
                break;
            }
            tempNode = tempNode->link;
            c=0;
        }
        if(c==0) cout<<"Item not found !"<<endl;
    }
}
int main()
{
    int n;
    int val;
    node *y;
    while(1)
    {

        cout<<endl<<"1.push\n2.pop\n3.Display all items\n4.isEmpty()\n5.Search\n6.Exit"<<endl;
        cout<<"Enter a option: ";
        cin>>n;
        switch(n)
        {
            case 1:
                cout<<"\nEnter a value: ";
                cin>>val;
                y = createNode(val);
                push(y);
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;
            case 4:
                if(isEmpty() == 1) cout<<"\n The stack is empty !\n";
                else cout<<"\nThe stack is not empty!\n";
                break;
            case 5:
                search();
                break;

            case 6:
                deleteAll(); //calling this function is necessary, otherwise not deleting dynamically created nodes may cause memory leak
                exit(0);
        }
    }
    return 0;
}
