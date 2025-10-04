#include <iostream>
#include <cmath>   
using namespace std;

int main() {
    double x1, y1, x2, y2;
    double khoangCach;

    cout << "Nhap toa do diem A (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Nhap toa do diem B (x2 y2): ";
    cin >> x2 >> y2;

    khoangCach = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    cout << "\nKhoang cach giua 2 diem A(" << x1 << ", " << y1 << ") va B(" << x2 << ", " << y2 << ") la: " << khoangCach << endl;

    return 0;
}

