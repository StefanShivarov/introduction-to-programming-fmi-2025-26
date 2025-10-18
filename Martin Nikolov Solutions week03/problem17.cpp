#include<iostream>

int main()
{
int n;
std::cin>>n;
for (int i=1; i<=n; i++)
{
for (int ones=1; ones<=i; ones++)
{
std::cout<<"1 ";
}
for (int zeros=1; zeros<=n-i; zeros++)
{
std::cout<<"0 ";
}
    std::cout<<std::endl;
}
}