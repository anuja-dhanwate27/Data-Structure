//////////////////////////////////////////////////////
// Final code of queue using generic approach
/////////////////////////////////////////////////////
#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
class Queuenode
{
    public:
       T data;
       Queuenode<T> *next;
       
        Queuenode(T no)
       {
           this->data = no;
           this->next = NULL;
       }
}; 

template <class T>
class Queue
{
    private:
       Queuenode<T> *first;
       Queuenode<T> *last;
       int iCount;
    
    public:
       Queue();
       void Enqueue(T);            
       T Dequeue();                
       void Display();
       int Count();
};

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created successfully\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void Queue<T>::Enqueue(T no)
{
    Queuenode<T> *newn = NULL;
    newn = new  Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }
    this->iCount++;
}   

template <class T>
T Queue<T>:: Dequeue()
{
    T Value = 0;

    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    else if (this->first == this->last)
    {
        this->first = NULL;
        this->last = NULL;
    }
    
    else
    {
        Value = this->first->data;
        
        this->first = this->first->next;
        delete temp;

        this->iCount--;

        return Value;
    }
}     

template <class T>
void Queue<T>:: Display()
{
    Queuenode<T> *temp =this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T>:: Count()
{
    return this->iCount;
}


int main()
{
    
    Queue<int> *qobj = new Queue<int>();
     
    int iChoice = 0;
    int Value = 0;
    int iRet = 0;

    while(1)                      // Unconditional loop
    {
        cout<<"-----------------------------------------------------------\n";
        cout<<"----------------Please select the option-------------------\n";
        cout<<"1 : Insert new elements into the queue\n";
        cout<<"2 : Remove the elements from queue\n";
        cout<<"3 : Display the elements of queue\n";
        cout<<"4 : Count the number of elements from the queue\n";
        cout<<"0 : Exit the application\n";

        cin>>iChoice;

        switch(iChoice)
        {
            case 1 : 
                cout<<"Enter the elements that you want to insert :\n";
                cin>>Value;
                qobj->Enqueue(Value);
                cout<<"Elements gets inserted successfully.\n";
                break;

            case 2 :
                iRet = qobj->Dequeue();
                if(iRet != -1)
                {
                    cout<<"Elements removed from queue is : "<<iRet<<"\n";

                }
                break;
                
            case 3:
                cout<<"Elements of the queue atre :\n";
                qobj->Display();
                break;
            
            case 4:
                iRet =  qobj->Count();
                cout<<"Number of elements in queue are are : "<<iRet<<"\n";
                break;
            
            case 0:
                cout<<"Thank you for using our application\n";
                delete qobj;
                return 0;
            
            default:
                cout<<"Please enter valid option\n";

        }// End of switch

        cout<<"-----------------------------------------------------------\n";
    }// End of while

    return 0;

}//End of main