#include<iostream>

int main()
{
int n;
std::cin>>n;
int num=0;
for (int i=1; i<=n;i++ )
{
  for (int j=1; j<=i; j++)
  {
    num+=1;
    std::cout<<num<<" ";
  }
  std::cout<<std::endl;
}

}