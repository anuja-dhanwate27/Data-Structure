//////////////////////////////////////////
// Generalized data structure library
//////////////////////////////////////////

/*
----------------------------------------------------------------------------------------------------------------
Type                  Name of class for node                 Name of class for functionality: SinglyLLL
----------------------------------------------------------------------------------------------------------------
Singly Linear         SinglyLLLnode                          SinglyLLL                  Done
Singly Circular       SinglyCLLnode                          SinglyCLL                  Done
Doubly Linear         DoublyLLLnode                          DoublyLLL                  Done
Doubly Circular       DoublyCLLnode                          DoublyCLL                 
Stack                 Stacknode                              Stack                      Done
Queue                 Queuenode                              Queue                      Done
----------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////
//          Singly linear linked list using generic approach
//////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:                            
        SinglyLLLnode<T> *first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);              
        void InsertLast(T );
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout<<"Object of singlyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertFirst
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 
template <class T>
void SinglyLLL<T>::InsertFirst(T no)                    
{
    SinglyLLLnode<T> *newn = NULL;
    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertLast
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 
template <class T>
void SinglyLLL<T>:: InsertLast(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;
    newn = new SinglyLLLnode<T>(no);


    if(this->iCount == 0)                             
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


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteFirst
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 
template <class T>
void SinglyLLL<T>:: DeleteFirst()
{
    SinglyLLLnode<T> *temp = NULL;
    if(this->first==NULL)
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
        this->first = this->first->next;
        delete temp;
    }
    this->iCount--;
 }

 
////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteLast
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 
template <class T>
void SinglyLLL<T>:: DeleteLast()
{
    SinglyLLLnode<T> *temp = NULL;
    if(this->first==NULL)
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
            temp =temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
    }

    
////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Display
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to display each node 
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>:: Display()
{
    SinglyLLLnode<T> *temp = NULL;
    temp = this->first;
    int iCnt = 0;

    for(iCnt=1; iCnt<=this->iCount; iCnt++)                       
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
    }

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Count
//    Input         :   Nothing
//    Output        :   Returns integer value 
//    Description   :   Used to count each node 
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T>:: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertAtPos
//    Input         :   Data of node,int
//    Output        :   Nothing
//    Description   :   Used to intsert node at specific position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
///
/////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertAtPos(T no,int pos)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos<1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        for(iCnt = 1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++; 
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteAtPos
//    Input         :   int
//    Output        :   Nothing
//    Description   :   Used to delete node at specific position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void SinglyLLL <T>::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *target = NULL;
    int iCnt = 0;

    if(pos<1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }
    if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt =1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }
            target = temp->next;
            temp->next = target->next;
            delete target;
            this->iCount--; 
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
//          Singly Circular linked list using generic approach
//////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>

class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;
    
    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);    
        void InsertAtPos(T,int);
        void DeleteFirst(); 
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

template<class T>

SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Object of singlyCL gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertFirst
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void SinglyCLL<T> ::  InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no) ;

    if(this->first== NULL && this->last== NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next  = this->first;
        this->first = newn; 
        
    }
    this->last->next = this->first;
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertLast
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>

void SinglyCLL<T> :: InsertLast(T no)
{ 
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    this->last->next = first;
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertAtPos
//    Input         :   Data of node, int
//    Output        :   Nothing
//    Description   :   Used to insert node at specific position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>

void SinglyCLL<T> ::  InsertAtPos(T no,int pos)
{
    int iCnt = 0;
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *newn = NULL;
    
    if(pos<1 || pos>this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos==iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);
        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteFirst
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>

void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    else if(this->first==last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first  = this->first->next;
        delete temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteLast
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to insert node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 
        
template <class T>

void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next != this->last)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        this->last = temp;
        this->last->next = this->first;
    }  
    this->iCount--;  
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteAtPos
//    Input         :   int
//    Output        :   Nothing
//    Description   :   Used to delete node at specific position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>

void SinglyCLL<T> ::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;
    int iCnt = 0;
    
    if(pos<1 || pos>iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Display
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to display all nodes
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> *temp = NULL;
    temp = this->first;
    do
    {
        cout<< "| " << temp->data << "| ->";
        temp = temp->next; 
    } 
    while(temp != last->next);
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Countt
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to count total node 
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>
int SinglyCLL<T>:: Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////
//          Doubly linear linked list using generic approach
/////////////////////////////////////////////////////////////////////////////////////////


#pragma pack(1)

template<class T>

class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
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
        DoublyLLLnode<T> *first;
        int iCount;  
    
    public:
        DoublyLLL();
        void InsertFirst(T);
        void InsertLast(T );
        void InsertAtPos(T ,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();

};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked list gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertFirst
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>
void DoublyLLL <T>:: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    newn = new  DoublyLLLnode<T>(no);
    
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

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertLast
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>
void DoublyLLL <T> :: InsertLast(T no )
{
     DoublyLLLnode<T> *newn =NULL;
    
     DoublyLLLnode<T> *temp = NULL;
    
    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;

}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertAtPos
//    Input         :   Data of node,int
//    Output        :   Nothing
//    Description   :   Used to insert node at specific position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>
void DoublyLLL <T> :: InsertAtPos(T no ,int pos)
{
     DoublyLLLnode<T> *newn = NULL;
     DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos<1 || pos>this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos==1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt<pos-1; iCnt++)
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

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteFirst
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>
void DoublyLLL <T> :: DeleteFirst()
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
       this->first->prev = NULL;
   }
   this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteLast
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>
void DoublyLLL <T>:: DeleteLast()
{
     DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)       // LL is empty
   {
       return;
   }
   else if(this->first->next == NULL)      // LL contains one node
   {
        delete this->first;
        this->first = NULL;
   }
   else                                   // LL contains more than 1 node
   {
       temp = first;
       while(temp->next->next != NULL)
       {
          temp = temp->next;
       }
       delete temp->next;
       temp->next = NULL;
   }
   this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteAtPos
//    Input         :   int
//    Output        :   Nothing
//    Description   :   Used to delete node at specific position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>
void DoublyLLL <T>:: DeleteAtPos(int pos)
{
     DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos<1 || pos>this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos==1)
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
        for(iCnt = 1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }
    
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Display
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to display all nodes
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>
void DoublyLLL<T> :: Display()
{
     DoublyLLLnode<T> *temp = NULL;
    temp = this->first;
    
    cout<<"\n NULL <=>";
    while(temp != NULL)
    {
         cout<<"| "<<temp->data<<"| <=> ";
         temp = temp->next; 
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Count
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to count all nodes
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////
//           Doubly circular linked list using generic approach
//////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>

class DoublyCLLnode
{
    public:
       T data;
       DoublyCLLnode<T> *next;
       DoublyCLLnode<T> * prev;

       DoublyCLLnode(T no)
       {
           this->data = no;
           this->next = NULL;
           this->prev = NULL;
       }
};

template <class T>

class DoublyCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

template <class T>

DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Object of doubly circular linked list gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertFirst
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    newn = new DoublyCLLnode<T> (no);

    if(this->first==NULL && this->last==NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->first->prev = this->last;
    this->last->next = this->first;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertLast
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    newn = new DoublyCLLnode<T>(no);
    
    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->first->prev = this->last;
    this->last->next = this->first;

    this->iCount++;
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   InsertAtPos
//    Input         :   Data of node,int
//    Output        :   Nothing
//    Description   :   Used to insert node at specific position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyCLLnode<T> *newn = NULL;
    DoublyCLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos<1 || pos>this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos==iCount+1)
    {
        InsertLast(no);
    }
    else 
    {
        newn = new DoublyCLLnode<T>(no);

        temp = first;

        for(iCnt = 1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        this->iCount++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteLast
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
            DoublyCLLnode<T> *temp = NULL;
            if(this->first == NULL && this->last == NULL)
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->first;
                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                temp = this->first;
                this->first = this->first->next;
                delete temp;
                this->first->prev = this->last;
                this->last->next = this->first;
            }
            this->iCount--;
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteLast
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(this->first==NULL && this->last== NULL)
    {
        return;
    }
    else if(this->first==this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;
        this->first->prev = this->last;
        this->last->next = this->first;
    }
    this->iCount--;
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   DeleteAtPos
//    Input         :   int
//    Output        :   Nothing
//    Description   :   Used to delete node at specific position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *target = NULL;

    int iCnt = 0;

    if(pos<1 || pos>iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt =1 ; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        delete target;

        this->iCount--;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Display
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to display all nodes
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> *temp = NULL;
    temp = this->first;
    
    cout<<" <=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    } while (temp != this->last->next);
    cout<<"\n";
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Count
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to count all nodes
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}


//////////////////////////////////////////////////////////////////////////////////////////
//           Stack using generic approach
//////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>

class Stacknode
{
    public:
       T data;
       Stacknode<T> *next;
       
       Stacknode(T no)
       {
           this->data = no;
           this->next = NULL;
       }
}; 

template<class T>

class Stack
{
    private:
       Stacknode<T> *first;
       int iCount;
    
    public:
       Stack();
       void Push(T);            
       T Pop();              
       T Peep();
       void Display();
       int Count();
};

template<class T>

Stack<T> :: Stack()
{
    cout<<"Stack gets created successfully\n";
    this->first = NULL;
    this->iCount = 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Push
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>

void Stack<T>::Push(T no)
{
    Stacknode<T> *newn = NULL;
    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    iCount++;
}   


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Pop
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>

T Stack<T>:: Pop()
{
    T Value = 0;

    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;
    
    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;

}     


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Peep
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to display elements at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>

T Stack<T>:: Peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;    
    return Value;

}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Display
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to display all nodes 
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>

void Stack<T>:: Display()
{
    Stacknode<T> *temp =this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Count
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to count total nodes in stack
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template<class T>

int Stack<T>:: Count()
{
    return this->iCount;
}


//////////////////////////////////////////////////////////////////////////////////////////
//            using generic approach
//////////////////////////////////////////////////////////////////////////////////////////

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


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Enqueue
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at last position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

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


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Dequeue
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at first position
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

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

    Value = this->first->data;
    
    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}     

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Display
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to display all nodes 
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

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

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Count
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to count total nodes in queue
//    Author        :   Anushka Ramesh Patare
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
int Queue<T>:: Count()
{
    return this->iCount;
}

////////////////////////////////////////// End of library ///////////////////////////////////////////////


int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;
    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111); 
    obj->InsertLast(121);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->DeleteFirst();
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->DeleteLast();
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->InsertAtPos(105,4);
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->DeleteAtPos(4);
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

///////////////////////////////////////////////////////////////////////////////////////////////////
   
    SinglyCLL <int> *scobj = new SinglyCLL<int>();

    scobj->InsertFirst(51);
    scobj->InsertFirst(21);
    scobj->InsertFirst(11);

    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    scobj->InsertLast(101);
    scobj->InsertLast(111); 
    scobj->InsertLast(121);

    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    scobj->DeleteFirst();
    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    scobj->DeleteLast();
    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    scobj->InsertAtPos(105,2);
    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    scobj->DeleteAtPos(2);
    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    delete scobj;

///////////////////////////////////////////////////////////////////////////////////////////////////
  
DoublyLLL<char> *dobj = new DoublyLLL<char>();
  
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

    /////////////////////////////////////////////////////////////////////////////////////////////////////

     DoublyCLL<int> *dcobj = new DoublyCLL<int>();

    dcobj->InsertFirst(51);
    dcobj->InsertFirst(21);
    dcobj->InsertFirst(11);

    dcobj->Display();

    cout<<"Number of nodes are  :"<<dcobj->Count()<<"\n";

    dcobj->InsertLast(101);
    dcobj->InsertLast(111);
    dcobj->InsertLast(121);

    dcobj->Display();

    cout<<"Number of nodes are  :"<<dcobj->Count()<<"\n";

    dcobj->InsertAtPos(31,2);

    dcobj->Display();

    cout<<"Number of nodes are  :"<<dcobj->Count()<<"\n";

    dcobj->DeleteFirst();

    dcobj->Display();

    cout<<"Number of nodes are  :"<<dcobj->Count()<<"\n";

    dcobj->DeleteLast();

    dcobj->Display();

    cout<<"Number of nodes are  :"<<dcobj->Count()<<"\n";

    dcobj->DeleteAtPos(2);

    dcobj->Display();

    cout<<"Number of nodes are  :"<<dcobj->Count()<<"\n";

    delete dcobj;

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    Stack<char> *sobj = new Stack<char>();
    
    sobj->Push('A');
    sobj->Push('B');
    sobj->Push('C');
    sobj->Push('D');

    sobj->Display();

    cout<<"Number of elements in stack : "<<sobj->Count()<<"\n";

    cout<<"Return value of peep is : "<<sobj->Peep()<<"\n"; 

    sobj->Display();

    cout<<"Number of elements in stack : "<<sobj->Count()<<"\n";

    cout<<"Popped elements is :"<<sobj->Pop()<<"\n";

    sobj->Display();

    cout<<"Number of elements in stack : "<<sobj->Count()<<"\n";

    cout<<"Popped elements is :"<<sobj->Pop()<<"\n";

    sobj->Display();

    cout<<"Number of elements in stack : "<<sobj->Count()<<"\n";

    sobj->Push('E');
    
    sobj->Display();

    cout<<"Number of elements in stack : "<<sobj->Count()<<"\n";

    delete sobj;
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    
    Queue<double> *qobj = new Queue<double>();
    
    qobj->Enqueue(11.56789);
    qobj->Enqueue(21.56789);
    qobj->Enqueue(51.56789);
    qobj->Enqueue(101.56789);
    
    qobj->Display();

    cout<<"Number of elements in queue: "<<qobj->Count()<<"\n";

    cout<<" Removed elements is :"<<qobj->Dequeue()<<"\n";

    qobj->Display();

    cout<<"Number of elements in queue : "<<qobj->Count()<<"\n";

    cout<<"Removed elements is :"<<qobj->Dequeue()<<"\n";

    qobj->Display();

    cout<<"Number of elements in queue : "<<qobj->Count()<<"\n";

    qobj->Enqueue(121.56789);
    
    qobj->Display();

    cout<<"Number of elements in queue : "<<qobj->Count()<<"\n";

    delete qobj;
    
    return 0;
}// End of main