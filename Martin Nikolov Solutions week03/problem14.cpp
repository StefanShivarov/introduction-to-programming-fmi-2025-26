#include<iostream>

int main()
{
   int n;
   int counter=0;
   std::cin>>n;
   for (int i=1; i<=n; i++)
   {
      if (n%i==0) {counter++;}
   }
   std::cout<<counter;
}