// Doubly Circular        

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }

}

class  DoublyCL 
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL()
    {
        System.out.println("Objext of DoublyCL gets created");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;
        newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;

        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        last.next = first;
        first.prev = last;

        iCount++;
    }

    public void InsertLast(int no)
    {
         node newn = null;
        newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;

        }
        else
        {
            last.next = newn;
            newn.prev =last;
            last = newn;
           
        }
        last.next = first;
        first.prev = last;
        iCount++;
    }

    public void InsertAtPos(int no , int pos)
    {
        node newn = null;
        node temp = null;
         int iCnt = 0;

        if(pos < 1 && pos > iCount+1)
        {
           System.out.println("Invalide position");
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


    public void DeleteFirst()
    {
        if(first == null && last ==null)
        {
            return;
        }
        else if(first == last)
        {
            
            first = null;
            last = null;

        }
        else
        {
            first = first.next;
            last.next = first;
            first.prev = last;
        }
        iCount--;


    }

    public void DeleteLast()
    {
        if(first == null && last ==null)
        {
            return;
        }
        else if(first == last)
        {
           
            first = null;
            last = null;

        }
        else
        {
            last = last.prev;
           

            last.next = first;
            first.prev = last;
        }
        iCount--;
    }

    public void DeleteAtPos(int pos)
    {}


    public void Display()
    {

        node temp = null;
        temp = first;

        if(first ==null  && last == null)
        {
            System.out.println("Linked list is empty");
            return;
        }
        
          do
        {
            System.out.print("|"+temp.data+"|<=>");
            temp = temp.next;
            
        } while (temp != last.next);
        System.out.println("");
    }

    public int Count()
    {
        return this.iCount;

    }

    
}

public class program449
{
    public static void main(String A[])
    {
         DoublyCL obj = null;

        int iRet = 0;

        obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);


        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
         obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);


        obj.DeleteLast();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.InsertAtPos(105, 4);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteAtPos(4);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);






        // Important for memory deallocation
        obj = null;
        System.gc();


        


        

    }
    

}
