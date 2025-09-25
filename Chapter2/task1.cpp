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

int main() {
    cout << "input first fraction (x/y): ";
    Fraction f1; f1.input();
    cout << "input second fraction (x/y): ";
    Fraction f2; f2.input();

    cout << "add: "; (f1 + f2).print(); cout << "\n";
    cout << "sub: "; (f1 - f2).print(); cout << "\n";
    cout << "mul: "; (f1 * f2).print(); cout << "\n";
    cout << "div: "; (f1 / f2).print(); cout << "\n";

    return 0;
}
