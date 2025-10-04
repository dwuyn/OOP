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
        cout << num << "/" << den << "\n";
        cout << "Value: " << (double) num / den << "\n";
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(num * other.den + other.num * den, den * other.den);
    }
};

int main() {
    vector<Fraction> arr(2);
    for (int i = 0; i < 2; i++) {
        cout << "enter fraction " << i+1 << " (x/y): ";
        arr[i].input();
    }

    Fraction sum(0, 1);
    for (int i = 0; i < 2; i++) {
        sum = sum + arr[i];
        cout << "Fraction " << i+1 << ": ";
        arr[i].print();
    }

    cout << "Sum: ";
    sum.print();
    cout << "\n";

    return 0;
}
