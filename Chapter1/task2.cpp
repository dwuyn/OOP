#include <iostream>
#include <numeric> 

using namespace std;

class Fraction {
private:
    long long num, den;

    void reduce() {
        long long g = gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0) { 
            num = -num;
            den = -den;
        }
    }

public:
    Fraction(long long n = 0, long long d = 1) {
        if (d == 0) 
            throw invalid_argument("error denominator");
        num = n;
        den = d;
        reduce();
    }

    void input() {
        char slash;
        cin >> num >> slash >> den;
        if (slash != '/' || den == 0) 
            throw invalid_argument("invalid fraction");
        reduce();
    }

    void print() const {
        cout << num << "/" << den;
    }

    bool operator>(const Fraction& other) const {
        return num * other.den > other.num * den;
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(num * other.den + other.num * den, den * other.den);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(num * other.den - other.num * den, den * other.den);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(num * other.num, den * other.den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.num == 0) {
            throw invalid_argument("");
        }
        return Fraction(num * other.den, den * other.num);
    }
};

class Date {
private:
    int day, month, year;

    bool is_leap_year(int y) const {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    void input() {
        cin >> day >> month >> year;
    }

    void next_day() {
        int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && is_leap_year(year)) {
            month_days[2] = 29;
        }

        day++;
        if (day > month_days[month]) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    void print() const {
        cout << day << "/" << month << "/" << year;
    }
};

int main() {
    char choice;
    cout << "input (a, b, c, d): ";
    cin >> choice;

    try {
        if (choice == 'a') {
            cout << "input a fraction (x/y): ";
            Fraction f;
            f.input();
            cout << "reduced fraction: ";
            f.print();
        }
        else if (choice == 'b') {
            cout << "input first fraction (x/y): ";
            Fraction f1; f1.input();
            cout << "input second fraction (x/y): ";
            Fraction f2; f2.input();
            cout << "bigger fraction: ";
            (f1 > f2 ? f1 : f2).print();
        }
        else if (choice == 'c') {
            cout << "input first fraction (x/y): ";
            Fraction f1; f1.input();
            cout << "input second fraction (x/y): ";
            Fraction f2; f2.input();

            cout << "add: "; (f1 + f2).print(); cout << "\n";
            cout << "sub: "; (f1 - f2).print(); cout << "\n";
            cout << "mul: "; (f1 * f2).print(); cout << "\n";
            cout << "div: "; (f1 / f2).print(); cout << "\n";
        }
        else if (choice == 'd') {
            cout << "input date (dd mm yyyy): ";
            Date dt;
            dt.input();
            dt.next_day();
            cout << "next date: ";
            dt.print();
        }
    }
    catch (const exception& e) {
        cout << e.what() << "\n";
    }

    return 0;
}

