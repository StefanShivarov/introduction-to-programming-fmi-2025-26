#include <iostream>
using std::cin;
using std::cout;
using std::endl;

double getPerimeter(int a1,int a2, int b1,int b2, int c1,int c2)
{
    double a = sqrt((b1 - a1) * (b1 - a1) + (b2 - a2) * (b2 - a2)); //AB
    double b = sqrt((c1 - b1) * (c1 - b1) + (c2 - b2) * (c2 - b2)); //BC
    double c = sqrt((a1 - c1) * (a1 - c1) + (a2 - c2) * (a2 - c2)); //CA
    return a + b + c;
}
double getArea(int a1, int a2, int b1, int b2, int c1, int c2)
{
    double area = (a1 * (b2 - c2) + b1 * (c2 - a2) + c1 * (a2 - b2)) / 2;
    if (area>0)
    {
        return area;
    }
    else
    {
        return -area;
    }
}
bool isInsideCircleWithRadius(int a1, int a2, int b1, int b2, int c1, int c2, int r)
{
    if (
        (a1 * a1 + a2 * a2) <= r * r && 
        (b1 * b1 + b2 * b2) <= r * r && 
        (c1 * c1 + c2 * c2) <= r * r
       )
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int a1,a2, b1,b2, c1,c2, r;
    cin >> a1>>a2>> b1>>b2>> c1>>c2>> r;
    cout << "Perimeter is : " << getPerimeter(a1,a2, b1,b2, c1,c2)<<endl;
    cout << "Area is : " << getArea(a1, a2, b1, b2, c1, c2) << endl;
    cout << "Is inside circle with radius " << r<<" : ";
    if (isInsideCircleWithRadius(a1, a2, b1, b2, c1, c2, r))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

}