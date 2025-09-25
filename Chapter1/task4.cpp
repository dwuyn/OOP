#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Hocsinh {
private:
    string maHS;
    string hoten;
    double toan, van, ly, hoa;

public:
    Hocsinh() {
        cout << "Nhap ma hoc sinh: ";
        cin >> maHS;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap diem Toan: ";
        cin >> toan;
        cout << "Nhap diem Van: ";
        cin >> van;
        cout << "Nhap diem Ly: ";
        cin >> ly;
        cout << "Nhap diem Hoa: ";
        cin >> hoa;
    }

    double average() {
        return (toan + van + ly + hoa) / 4.0;
    }

    void display() {
        cout << "\nThong tin hoc sinh\n";
        cout << "Ma HS: " << maHS << endl;
        cout << "Ho ten: " << hoten << endl;
        cout << fixed << setprecision(2);
        cout << "Toan: " << toan << ", Van: " << van 
             << ", Ly: " << ly << ", Hoa: " << hoa << endl;
        cout << "Diem trung binh: " << average() << endl;
    }
};

int main() {
    Hocsinh hs;   
    hs.display();    
    return 0;
}

