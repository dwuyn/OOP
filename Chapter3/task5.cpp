#include <iostream>

using namespace std;

class cHocSinh {
private:
    int ma;
    string hoTen;
    string gioiTinh;
    int namSinh;
    double diemTB;

public:
    cHocSinh(int ma = 0, string hoTen = "", string gioiTinh = "", int namSinh = 0, double diemTB = 0.0) {
        this->ma = ma;
        this->hoTen = hoTen;
        this->gioiTinh = gioiTinh;
        this->namSinh = namSinh;
        this->diemTB = diemTB;
    }

    void input() {
        cout << "Ma HS: ";
        cin >> ma;
        cin.ignore();
        cout << "Ho Ten: ";
        getline(cin, hoTen);
        cout << "Gioi Tinh (Nam/Nu): ";
        cin >> gioiTinh;
        cout << "Nam Sinh: ";
        cin  >> namSinh;
        cout << "Diem TB: ";
        cin >> diemTB;
    }

    string getHoTen() const { return hoTen; }
    int getNamSinh() const { return namSinh; }
    double getDiemTB() const { return diemTB; }
};

int main() {
    cHocSinh hs1, hs2;
    cout << "Nhap thong tin hs thu 1: \n";
    hs1.input();
    cout << "Nhap thong tin hs thu 2: \n";
    hs2.input();

    if (hs1.getDiemTB() > hs2.getDiemTB())
        cout << "HS " << hs1.getHoTen() << " co diem tb cao hon: " << hs1.getDiemTB() << "\n";
    else if (hs2.getDiemTB() > hs1.getDiemTB())
        cout << "HS " << hs2.getHoTen() << " co diem tb cao hon: " << hs2.getDiemTB() << "\n";
    else 
        cout << "2 HS co diem tb bang nhau: " << hs1.getDiemTB() << "\n";

    if (hs1.getNamSinh() > hs2.getNamSinh())
        cout << "HS " << hs1.getHoTen() << " nho tuoi hon HS " << hs2.getHoTen() << "\n";
    else if (hs2.getNamSinh() > hs1.getNamSinh())
        cout << "HS " << hs2.getHoTen() << " nho tuoi hon HS " << hs1.getHoTen() << "\n";
    else 
        cout << "2 HS bang tuoi nhau";

    return 0;
}
