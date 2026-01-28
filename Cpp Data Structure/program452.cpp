// Doubly Circular

#include<iostream>
using namespace std;
struct node 
{
    int data ;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node* PNODE;


class DoublyCL
{
    private:
         PNODE first;
         PNODE last;
         int iCount;
    
    public:
          DoublyCL()
            {
                cout<<"Object of DoublyCL gets created.\n";
                this->first = NULL;
                this->last =  NULL;
                this->iCount = 0;

            }
            void InsertFirst(int no)
            {
                PNODE newn = NULL;
                newn = new NODE;
                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                if(first == NULL && last == NULL)
                {
                    first = newn;
                    last = newn;

                }
                else
                {
                    newn->next = first;
                    first->prev = newn;
                    first=newn;

                }
                last->next = first;
                first->prev = last;

                iCount++;
            }

            void InsertLast(int no)
            {
                PNODE newn = NULL;
                newn = new NODE;
                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                if(first == NULL && last==NULL)
                {
                    first = newn;
                    last = newn;

                }
                else
                {
                    last->next = newn;
                    newn->prev = last;
                    last = newn;

                }
                last->next = first;
                first->prev = last;

                iCount++;

            }

           


            void DeleteFirst()
            {
                if(first == NULL && last ==NULL)
                {
                    return;
                }
                else if(first == last)
                {
                    delete first;
                    first = NULL;
                    last = NULL;

                }
                else
                {
                    first = first->next;
                    delete first->prev;
                    last->next = first;
                    first->prev = last;
                }
                iCount--;

            }

            void DeleteLast()
            {
                 if(first == NULL && last ==NULL)
                {
                    return;
                }
                else if(first == last)
                {
                    delete first;
                    first = NULL;
                    last = NULL;

                }
                else
                {
                    last = last->prev;
                    delete last->next;

                    last->next = first;
                    first->prev = last;
                }
                iCount--;
            }

           
            void Display()
            {
                PNODE temp = NULL;
                temp = first;

                if(first == NULL && last == NULL)
                {
                    cout<<"Linked list is empty";
                    return;
                }
                
                cout<<"<=>";
                do
                {
                    cout<<"|"<<temp->data<<"|<=>";
                    temp = temp->next;
                    
                } while (temp != last->next);
                cout<<"\n";
            }

            int Count()
            {
                return this->iCount;
            }

            void InsertAtPos(int no , int pos)
            {
                PNODE newn = NULL;
                PNODE temp = NULL;
                int iCnt = 0;

                if(pos < 1 && pos > iCount+1)
                {
                    cout<<"Invalid position\n";
                    return;
                }

                if(pos == 1)
                {
                    this->InsertFirst(no);

                }
                else if(pos == iCount+1)
                {
                    this->InsertLast(no);
                }
                else
                {
                    newn = new NODE;
                    newn->data = no;
                    newn->next = NULL;
                    newn->prev = NULL;

                    temp = first;
                    for(iCnt = 1; iCnt < pos-1 ; iCnt++)
                    {
                        temp=temp->next;

                    }
                    newn->next = temp->next;
                    temp->next->prev = newn;
                    temp->next = newn;
                    newn->prev = temp;



                    iCount++;

                    


                }



            }

           
            void DeleteAtPos(int pos)
            {
                
                PNODE temp = NULL;
                PNODE target = NULL;
                int iCnt = 0;

                if(pos < 1 && pos > iCount)
                {
                    cout<<"Invalid position\n";
                    return;
                }

                if(pos == 1)
                {
                    this->DeleteFirst();

                }
                else if(pos == iCount)
                {
                    this->DeleteLast();
                }
                else
                {
                    temp = first;

                    for(iCnt = 1 ;iCnt < pos-1; iCnt++)
                    {
                        temp = temp->next;
                    }
                    target = temp->next;

                    temp->next = target->next;
                    temp->next->prev = temp;
                    delete target;

                    iCount--;



                    
                }
                
                
            }


};


int main()
{

   
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

  

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";


    obj.InsertAtPos(105 ,4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.DeleteAtPos(4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";




    



    return 0;
}