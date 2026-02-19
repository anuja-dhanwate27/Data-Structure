#include<iostream>
using namespace std;

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






int main()
{
    
    int iValue = 0;
    
    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue);

    aobj.Accept();
    aobj.Display();



    


    
    return 0;
}