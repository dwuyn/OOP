#include <iostream>
#include <numeric>
#include <vector>

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

    long long getNum() const { return num; }
    long long getDen() const { return den; }
};

int main() {
    int n;
    cout << "enter number of fractions: ";
    cin >> n;

    vector<Fraction> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "enter fraction " << i+1 << " (x/y): ";
        arr[i].input();
    }

    Fraction sum(0, 1);
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }

    cout << "\nSum: ";
    sum.print();
    cout << "\n";

    Fraction maxFrac = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxFrac) {
            maxFrac = arr[i];
        }
    }

    cout << "Biggest fraction: ";
    maxFrac.print();
    cout << "\n";

    return 0;
}
