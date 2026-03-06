using namespace std;
#include <iostream>

bool IsYearLeap(int y);
int MaxDayOFMonth(int m, int y);
bool IsDateValid(unsigned int d, unsigned int  m, unsigned int y);
void CalcDate(unsigned int& d, unsigned int& m, unsigned int& y, int n);


int main()
{
    unsigned int d, m, y;
    int n;
    cout << "Enter day, month, year: ";
    cin >> d >> m >> y;
    cout << "Enter number of days to add: ";
    cin>> n;
    if (!IsDateValid(d, m, y)) cout << "Date is unvalid!";
    else
    {
        CalcDate(d, m, y, n);
        cout <<" New date: "<< d << " " << m << " " << y;
    }
}

void CalcDate(unsigned int &d, unsigned int &m,unsigned int &y, int n)
{
    while (n > 0)
    {
        int daysCurrent = MaxDayOFMonth(m, y);
        if (IsDateValid(d + n, m, y))
        {
            d += n;
            n = 0;
        }
        else
        {
            n = (d+n)- daysCurrent-1;
            d = 1;
            m++;

            if (m > 12)
            {
                m = 1;
                y++;
            }
        }
    }
    
    
}

int MaxDayOFMonth(int m, int y)
{
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    if (m == 2 && IsYearLeap(y)) return 29;
    if (m == 2 && !IsYearLeap(y)) return 28;
}
bool IsDateValid(unsigned int d,unsigned int  m, unsigned int y)
{
    if (m > 12) return false;
    if (d>MaxDayOFMonth(m,y)) return false;
    return true;

}

bool IsYearLeap(int y)
{
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    {
        return true;
    }return false;
}