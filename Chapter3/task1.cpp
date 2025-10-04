#include <iostream>
#include <string>
using namespace std;

int main() {
    string hoTen;
    double diemToan, diemVan, diemTB;
    string xepLoai;

    cout << "Nhap ho ten hoc sinh: ";
    getline(cin, hoTen); 

    cout << "Nhap diem Toan: ";
    cin >> diemToan;

    cout << "Nhap diem Van: ";
    cin >> diemVan;

    diemTB = (diemToan + diemVan) / 2.0;

    if (diemTB >= 8.0)
        xepLoai = "Gioi";
    else if (diemTB >= 6.5)
        xepLoai = "Kha";
    else if (diemTB >= 5.0)
        xepLoai = "Trung binh";
    else 
        xepLoai = "Yeu";

    cout << "\nHo ten: " << hoTen << "\n";
    cout << "Diem Toan: " << diemToan << "\n";
    cout << "Diem Van: " << diemVan << "\n";
    cout << "Diem trung binh: " << diemTB << "\n";
    cout << "Xep loai: " << xepLoai << "\n";

    return 0;
}

