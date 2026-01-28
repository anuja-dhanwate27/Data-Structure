////////////////////////////////////////////////////////////////////////////////
//                Generalised Data Structure Libraryy
////////////////////////////////////////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------------------------------------------------
  Type          |        Name of class for node                    |                    Name of class for functionality
--------------------------------------------------------------------------------------------------------------------------------
Singly Linear   |        SinglyLLLnode                             |                    SinglyLLL       Done
  
Singly Circular |          SinglyCLLnode                           |                    singlyCLL      

Doubly Linear   |          DoublyLLLnode                           |                    DoublyLLL       Done

Doubly Circular |         DoublyCLLnode                            |                    DoublyCLL 

---------------------------------------------------------------------------------------------------------------------------------
*/



#include<iostream>
using namespace std ;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                  singly linear linked list using generic approach
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode 
{ 
    public:
         T data ;
         SinglyLLLnode<T>* next;

         SinglyLLLnode( T no)
         {
            this->data = no;
            this->next = NULL;
         }
};


template<class T>
class SinglyLLL
{
    private:       // IMPORTANT
        SinglyLLLnode<T> *first;
         int iCount;

        
    public:
        SinglyLLL();
         void InsertFirst(T);
         void InsertLast(T);
         void DeleteFirst();
         void DeleteLast();
         void Display();
         int Count();
        void InsertAtPos(T  , int );
        void DeleteAtPos(int);
        

};



template<class T>
SinglyLLL<T> :: SinglyLLL()
{
cout<<"Object of SinglyLL gets created.\n";
this->first = NULL;
this->iCount = 0;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :         InsertFirst
//    Input :                 Data of node
//    OutPut :                Nothing
//    Description :           Used to insert node at first position
//    Author :                Anuja Santosh Dhanwate
//    Date   :                06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
template<class T>
void  SinglyLLL<T> ::InsertFirst(T no) // updated fun
{
SinglyLLLnode<T> *newn = NULL;
newn = new SinglyLLLnode<T>(no);



newn->next = this->first;
this->first = newn;

this->iCount++;

}


template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{

   SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;
    newn = new SinglyLLLnode<T>(no);


if(this->iCount == 0)          // updated 
{
    this->first = newn;


}
else
{
    temp = this->first;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newn;


    

}
this->iCount++;

}



template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)   // else if(this->iCount ==1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;

}


template<class T>
void SinglyLLL<T> :: DeleteLast()
{
   SinglyLLLnode<T> * temp = NULL;
        if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)   // else if(this->iCount ==1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;



}

this->iCount--;

}


template<class T>
void SinglyLLL<T> :: Display()
{
   SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;


    for(iCnt = 1; iCnt <= this->iCount; iCnt++)       
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";

}


template<class T>
int SinglyLLL<T> :: Count()
{
  return this->iCount;
}


template<class T>
void SinglyLLL<T> :: InsertAtPos(T no , int pos)
{
   SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos ==1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);
        
        temp = this->first;

        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;

}
}


template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T>* temp = NULL;
   SinglyLLLnode<T>* target = NULL;

int iCnt = 0;

if((pos < 1) || (pos > this->iCount))
{
    cout<<"Invalid position\n";
    return;
}

if(pos ==1)
{
    this->DeleteFirst();
}
else if(pos == this->iCount)
{
    this->DeleteLast();
}
else
{
    temp = this->first;

    for(iCnt = 1; iCnt < pos-1 ; iCnt++ )
    {
        temp = temp->next;
    }
    target = temp->next;
    temp->next = target->next;
    delete target;



    this->iCount--;

}
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                  doubly linear linked list using generic approach
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////   End Of Library  //////////////////////////////////////////////////////////////////////

int main()
{

    return 0;
}