#include <iostream>
using namespace std;

int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Date {
public:
    int year, month, day;
    Date() : year(0), month(0), day(0) {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    friend int operator - (const Date &x, const Date &y);
    string operator + (const int &x) {
        int y = x;
        while (y > 0) {
            y--;
            int k = a[month] + (f(year) ? 1 : 0);
            if (day == k) {
                day = 1;
                if (month == 12) {
                    month = 1;
                    year++;
                }
                else month++;
            }
            else day++;
        }
        return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }
    bool operator > (const Date &x) const {
        if (year == x.year) {
            if (month == x.month) return day < x.day;
            return month < x.month;
        }
        return year < x.year;
    }
    void print() {
        cout << to_string(year) + "-" + to_string(month) + "-" + to_string(day) << "\n";
    }
    bool f(int y) { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
};

int operator - (const Date &x, const Date &y)
{   
    Date xx = x, yy = y;
    if (y > x) xx = y, yy = x;
    int res = 0;
    while (xx.year != yy.year || xx.month != yy.month || xx.day != yy.day) {
        int k = a[xx.month] + (xx.f(xx.year) ? 1 : 0);
        if (xx.day == k) {
            xx.day = 1;
            if (xx.month == 12) {
                xx.month = 1;
                xx.year++;
            }
            else xx.month++;
        }
        else xx.day++;
        res++;
    }
    return res;
}

int main()
{
    Date a(2022, 5, 20), b(2020, 5, 22);
    cout << "两个日期相差：" << a - b << "天\n";
    cout << "日期2022-5-20加上50天后的日期为：" << a + 50 << "\n";
    cout << "a和b比较，" << (a > b ? "a" : "b") << "更大, 较大的日期为：";
    a > b ? a.print() : b.print();
    return 0;
}