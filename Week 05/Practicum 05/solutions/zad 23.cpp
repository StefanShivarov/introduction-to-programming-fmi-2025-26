using namespace std;
#include <iostream>


double AbsoluteValue(double n);
double getPerimeter(int x1, int y1, int x2, int y2, int x3, int y3);
double getArea(int x1, int y1, int x2, int y2, int x3, int y3);
bool isInsideCircleWithRadius(int x1, int y1, int x2, int y2, int x3, int y3, int r);

int main()
{
	int x1, y1, x2, y2, x3, y3,r;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3>>r;
	cout << "Perimeter: "<<getPerimeter(x1, y1, x2, y2, x3, y3) << endl;
	cout <<"Area: " << getArea(x1, y1, x2, y2, x3, y3)<<endl;
	cout << ((isInsideCircleWithRadius(x1, y1, x2, y2, x3, y3, r)) ? "is inside" : "is not inside");
}
double AbsoluteValue(double n)
{
	if (n < 0)return -n;
	else return n;
}
double getPerimeter(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	double b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	double c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	return a + b + c;
}

double getArea(int x1, int y1, int x2, int y2, int x3, int y3)
{

	return AbsoluteValue((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))) / 2;
}

bool isInsideCircleWithRadius(int x1, int y1, int x2, int y2, int x3, int y3, int r)
{
	bool inside1 = (x1 * x1 + y1 * y1) <= r * r;
	bool inside2 = (x2 * x2 + y2 * y2) <= r * r;
	bool inside3 = (x3 * x3 + y3 * y3) <= r * r;
	if (inside1 && inside2 && inside3)
	{
		return true;
	} return false;
}
