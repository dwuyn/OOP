#include <iostream>
#include <cmath>   
using namespace std;

int main() {
    double x, y; 
    double r;     
    double chuVi, dienTich;

    cout << "Nhap toa do tam (x y): ";
    cin >> x >> y;

    cout << "Nhap ban kinh r: ";
    cin >> r;

    chuVi = 2 * M_PI * r;
    dienTich = M_PI * r * r;

    cout << "Tam: (" << x << ", " << y << ")\n";
    cout << "Ban kinh: " << r << endl;
    cout << "Chu vi: " << chuVi << endl;
    cout << "Dien tich: " << dienTich << endl;

    return 0;
}

