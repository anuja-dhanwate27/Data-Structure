// singly Circular

#include<iostream>
using namespace std;
struct node 
{
    int data ;
    struct node * next;
};

typedef struct node NODE;
typedef struct node* PNODE;


class SinglyCL
{
    private:
         PNODE first;
         PNODE last;
         int iCount;
    
    public:
           SinglyCL()
            {
                cout<<"Object of SinglyCL gets created.\n";
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
                if((first) == NULL && (last) == NULL)
                {
                    first = newn;
                    last = newn;
                }
                else
                {
                    newn->next = first;
                    first = newn;


                }

                last->next = first;
                iCount++;


            }

            void InsertLast(int no)
            {
                PNODE newn = NULL;
                newn = new NODE;
                newn->data = no;
                newn->next = NULL;

                if((first)==NULL && (last)== NULL)
                {
                    first = newn ;
                    last = newn;

                }
                else
                {
                    last->next = newn;
                    last = newn;

                }
                last->next = first;
                iCount++;

            }

           

            void DeleteFirst()
            {
                PNODE temp= NULL;
                if((first)==NULL && (last)==NULL)
                {
                    return;
                }
                else if(first == last)
                {
                    free(first);
                    first = NULL;
                    last = NULL;
                }
                else
                {
                    temp = first;
                    first = first->next;
                    free(temp);
                    last->next = first;
                }

                this->iCount--;
            }

            void DeleteLast()
            {

                PNODE temp = NULL;
                if((first)==NULL && (last)== NULL)
                {
                    return;
                }
                else if(first == last)
                {
                    free(first);
                    first = NULL;
                    last = NULL;
                }
                else
                {
                    temp = first;
                    while(temp->next != last)
                    {
                        temp = temp->next;

                    }
                    free(last);
                    last = temp;
                    last->next = first;
                }

                this->iCount--;
            }

           

            void Display()
            {
                PNODE temp = NULL;
                temp = first;
                do
                {
                    cout<<"|"<<temp->data<<"|->";
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

               int iCnt  = 0;

               if((pos < 1)|| (pos > this->iCount+1))
               {
                 cout<<"Invalid Position\n";
                 return;

               }

               if(pos ==1)
               {
                 this->InsertFirst(no);
               }
               else if(pos ==2)
               {
                this->InsertLast(no);
               }
               else
               {
                 newn = new NODE;
                 newn->data = no;
                 newn->next = NULL;

                 temp = first;


                 for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
                 {
                    temp = temp->next;
                 }
                 newn->next = temp->next;
                 temp->next = newn;
                 this->iCount++;
                }

            }


            void DeleteAtPos(int pos)
            {
                
               PNODE temp = NULL;
               PNODE target = NULL;

               int iCnt  = 0;

               if((pos < 1)|| (pos > this->iCount))
               {
                 cout<<"Invalid Position\n";
                 return;

               }

               if(pos ==1)
               {
                 this->DeleteFirst();
               }
               else if(pos ==2)
               {
                this->DeleteLast();
               }
               else
               {

                  temp = first;
                  for(iCnt = 1; iCnt < pos-1 ; iCnt++)
                  {
                    temp = temp->next;
                  }
                  target = temp->next;
                  temp->next = target->next;
                  delete target;

                  this->iCount--;

                  

               }
            }

};


int main()
{

   
    SinglyCL obj;
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