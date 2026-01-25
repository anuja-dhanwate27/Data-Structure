#include<iostream>
using namespace std;

class Arithmatic
{
    private:
          int No1,No2;
    public:
          Arithmatic(int A ,int B);
          int Addition();
          int Subtraction();
       
};
// Error----------------------------------------------------------------------------

Arithmatic:: Arithmatic(int A ,int B)
{
  this->No1 = A;
  this->No2 = B;
}

int Arithmatic :: Addition()
{
  return No1+No2;

}


int Arithmatic :: Subtraction()
{
  return No1-No2;

}

int main()
{
    Arithmatic aobj(11,10);
    cout<<aobj.Addition()<<"\n";
     cout<<aobj.Subtraction()<<"\n";

    return 0;

}