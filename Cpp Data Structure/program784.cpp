#include<iostream>
using namespace std;

#define INC_ORDER 1
#define DEC_ORDER 2

class ArrayX
{
    public:
         int *Arr;
         int iSize;
         bool sorted;


   ArrayX(int no);
   ~ArrayX();


   void Accept();
   void Display();
   
   bool CheckSorted();

   void BubbleSort();
   void BubbleSortEfficient();
   void BubbleSortEfficientX(int iOption);

   void SelectionSort();
};

ArrayX :: ArrayX(int no)
{
   cout<<"Inside constructor\n";
   iSize = no;
   Arr = new int[iSize];
   sorted = true;
}

ArrayX :: ~ArrayX()
{
   cout<<"Inside destructor\n";
   delete [] Arr;
}

void ArrayX :: Accept()
{
   int iCnt = 0;
   cout<<"Inter the elements : \n";

   cin>>Arr[iCnt];
   for(iCnt = 1 ; iCnt < iSize; iCnt++)
   {
      cin>>Arr[iCnt];
      if(Arr[iCnt -1] > Arr[iCnt])
      {
         sorted = false;

      }
   }

   //sorted = CheckSorted();


}

void ArrayX:: Display()
{
   int iCnt = 0;
   cout<<"Elements of the array are : \n";
   for(iCnt = 0 ; iCnt < iSize ; iCnt++)
   {
      cout<<Arr[iCnt]<<"\t";
   }
   cout<<"\n";


}

// 0  1  2  3  4  5  6   7  8  9
// 0  1  2  3  4  5  6   7  8  9
// 12 14 17 24 28 36 48 52 52 65
bool ArrayX:: CheckSorted()
{
   int i = 0;
   bool bFlag = true;

   for(i = 0 ; i < iSize-1 ; i++)
   {
        if(Arr[i] > Arr[i+1])
        {
            bFlag = false;
            break;
        }

   }

   return bFlag;


}



void ArrayX :: BubbleSort()
{
   int i = 0 , j = 0;
   int temp = 0;
   int Pass = 0;
   int Time = 0;


   if(sorted == true)    // important filter
   {
      return;
   }

   Time  =1;

   for(i = 0 , Pass =1; i <iSize -1 ; i++ , Pass++)    // Outer loop
   {


      for(j = 0 ; j< iSize-1-i ; j++, Time++)   // inner
      {
         if(Arr[j] > Arr[j+1])
         {
            temp = Arr[j];
            Arr[j] = Arr[j+1];
            Arr[j+1] = temp;

         }
          

      }

      cout<<"\nData after pass : "<<i+1<<"\n";
      Display();
   }

   cout<<"Number of passes for bubble sort : "<<Pass<<"\n";
   cout<<"Total number of iterations "<<Time<<"\n";


   sorted = true;

    
}


// 21 15 18 16 11
void ArrayX :: BubbleSortEfficient()
{
   int i = 0 , j = 0;
   int temp = 0;
   
   
   bool bFlag = false;



  /* if(sorted == true)    // important filter
   {
      return;
   }
 */

   bFlag = true;

   for( i = 0 ;( i <iSize -1) && (bFlag == true) ; i++)    // Outer loop
   {

      bFlag = false;

      for(j = 0 ; j< iSize-1-i ; j++)   // inner
      {
         if(Arr[j] > Arr[j+1])
         {
            temp = Arr[j];
            Arr[j] = Arr[j+1];
            Arr[j+1] = temp;
            bFlag = true;


         }
          

      }

      cout<<"\nData after pass : "<<i+1<<"\n";
      Display();
   }

   cout<<"Number of passes for bubble sort : "<<i<<"\n";
   

   sorted = true;

    
}


// 1 : Increasing
// 2: Decreasing

void ArrayX :: BubbleSortEfficientX(int iOption = INC_ORDER)
{
   int i = 0 , j = 0;
   int temp = 0;
   
   
   bool bFlag = false;

   if( iOption < INC_ORDER || iOption > DEC_ORDER)
   {
      cout<<"Invalid option for sorting\n";
      cout<<"1 : Increasing \n";
      cout<<"2 : Decresing\n";
   }

  /* if(sorted == true)    // important filter
   {
      return;
   }
 */

   bFlag = true;

   if(iOption == INC_ORDER)
   {
      for( i = 0 ;( i <iSize -1) && (bFlag == true) ; i++)    // Outer loop
      {

         bFlag = false;

         for(j = 0 ; j< iSize-1-i ; j++)   // inner
         {
            if(Arr[j] > Arr[j+1])
               {
                  temp = Arr[j];
                  Arr[j] = Arr[j+1];
                  Arr[j+1] = temp;
                  bFlag = true;
               }
         
         }
         
      }

      cout<<"\nData after pass : "<<i+1<<"\n";
      Display();
   }
   else if(iOption == DEC_ORDER)
   {
      for( i = 0 ;( i <iSize -1) && (bFlag == true) ; i++)    // Outer loop
      {

         bFlag = false;

         for(j = 0 ; j< iSize-1-i ; j++)   // inner
         {
            if(Arr[j] < Arr[j+1])
               {
                  temp = Arr[j];
                  Arr[j] = Arr[j+1];
                  Arr[j+1] = temp;
                  bFlag = true;
               }
         
         }
         
      }


      cout<<"\nData after pass : "<<i+1<<"\n";
      Display();
   
   }

      
   

   cout<<"Number of passes for bubble sort : "<<i<<"\n";
   

   sorted = true;

    
}



void ArrayX :: SelectionSort()
{
   int i = 0, j= 0 , temp = 0;
   int min_index = 0;


   for(i = 0 ; i<iSize -1; i++)
   {
      min_index = i;


      for(j=i+1; j<iSize ; j++)
      {
         if(Arr[j] < Arr[min_index])
         {
            min_index = j;

         }

      }

      
      temp = Arr[i];
      Arr[i] = Arr[min_index];
      Arr[min_index] = temp;
   }




}






int main()
{
    
    int iValue = 0;
    
    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue);

    aobj.Accept();

    cout<<"Data before sorting\n";
    aobj.Display();

    // 1 : increasing
    // 2: Decresing
   
    // aobj.BubbleSortEfficientX(2);
    aobj.SelectionSort();
    cout<<"Data after sorting\n";
    aobj.Display();



    


    
    return 0;
}