#include<iostream>

int main()
{
    int n;
    std::cin>>n;
    int sum=0;
    int a,b;

    for (int i=1; i<=n; i++)
    {
        if (i>=10) {a=i/10; b=i%10; sum=a+b; if (sum%2==0){std::cout<<i<<" ";}}
        else if (i<10 && i%2==0) {std::cout<<i<<" ";}
    }
}