///////////////////////////////////////////////////////////////////////
//final code of doubly linear linked list using generic approach
///////////////////////////////////////////////////////////////////////



#include<iostream>
using namespace std ;

#pragma pack(1)
template<class T>
class doublyLLLnode
{
    public:
          T data;
          doublyLLLnode<T> *next;
          doublyLLLnode<T> * prev;

        doublyLLLnode(T no)
         {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
         }
};

template<class T>
class DoublyLLL
{
    private:
         doublyLLLnode<T> *first;
          int iCount;
    public: 
          DoublyLLL();

          void InsertFirst(T);
          void InsertLast(T);
          void InsertAtPos(T, int);

          void DeleteFirst();
          void DeleteLast();
          void DeleteAtPos(int);


          void Display();
          int Count();

};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";
    this->first = NULL;
    this->iCount = 0;

}

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
   doublyLLLnode<T> *newn = NULL;
    newn = new doublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;

    }

    this->iCount++;
}

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    doublyLLLnode<T> *newn = NULL;
    doublyLLLnode<T> * temp = NULL;
    newn = new doublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp =  temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        

    }

    this->iCount++;
    
}

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
   doublyLLLnode<T> *newn= NULL;
    doublyLLLnode<T> *temp = NULL;

    int iCnt = 0;

   

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos==1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = this->first;
        newn = new doublyLLLnode<T>(no);
        for(iCnt =1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;

        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;


        this->iCount++;


    }
    
}

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    
    if(this->first == NULL)             
    {
        return;
    }
    else if(this->first->next == NULL)    
    { 
        delete this->first;
        this->first = NULL;
    }
    else                                
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev=NULL;
       


    }
    this->iCount--;
    
}

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    doublyLLLnode<T> *temp = NULL;
    if(this->first == NULL)              
    {
        return;
    }
    else if(this->first->next == NULL)    
    { 
        delete this->first;
        this->first = NULL;
    }
    else                                
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
       


    }
    this->iCount--;
    
}

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
     doublyLLLnode<T> *temp = NULL;

    int iCnt = 0;

    

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos==1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for(iCnt =1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;


    }
    
}


template<class T>
void DoublyLLL<T> :: Display()
{
    doublyLLLnode<T> * temp = NULL;

    temp = this->first;

    cout<<"\nNULL<=>";
    while( temp != NULL)
    {
        cout<<"| "<< temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
    
}





int main()
{
    DoublyLLL <char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";


    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";


    dobj->DeleteFirst();
    

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";


    dobj->DeleteLast();


    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";


    dobj->InsertAtPos('$',4);
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";




    delete dobj;

    return 0;
}