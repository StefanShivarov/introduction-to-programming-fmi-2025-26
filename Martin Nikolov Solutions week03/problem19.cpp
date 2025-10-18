#include<iostream>

int main()
{
int n;
std::cin>>n;
for (int i=1;i<=n; i++)
{
for (int stars=1; stars<=i-1; stars++)
{
std::cout<<"*";
}
for (int numbers=i; numbers<=i; numbers++)
{
std::cout<<numbers;
}
for (int dots=1; dots<=n-i; dots++)
{
std::cout<<".";
}
    std::cout<<std::endl;
}
}