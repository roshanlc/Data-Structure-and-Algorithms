//A basic stack implementation using linked list

#include <iostream>

class node
{                                     
    public:
    int value;                //to hold some value
    node *link;               //class pointer to link one node with other
};

node *top=NULL;           
node *tempNode;

node *createNode(int x)
{
    tempNode = new node;
    tempNode->value = x;
    tempNode->link = NULL;
    return tempNode;
}

void push(node *x)
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

void pop()
{
    if(top==NULL)
    {
        std::cout<<"Illegal operation: Stack Underflow"<<std::endl;
    }
    else
    {
        tempNode = top;
        top=top->link;
        delete tempNode;
    }
}

void displayStack()
{
    tempNode = top;
    if(tempNode == NULL)
    {
        std::cout<<"Illegal operation: Empty Stack!"<<std::endl;
    }
    else
    {
        while(tempNode!=NULL)
        {
            std::cout<<tempNode->value<<"\t";
            tempNode = tempNode->link;
        }
    }

}

int main()
{
    int n,val;
    node *y;    //a temporary node
    while(1)
    {
        std::cout<<std::endl<<"1.push\n2.pop\n3.Display all items\n4.exit"<<std::endl;
        std::cout<<"Enter a option: ";
        std::cin>>n;
        switch(n)
        {
            case 1:
               std::cout<<"\nEnter a value: ";
               std::cin>>val;
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
                exit(0);
        }
    }
    return 0;
}
