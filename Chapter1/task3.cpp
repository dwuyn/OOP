#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class NhanVien {
private:
    string maNV;
    string hoTen;
    string phongBan;
    long long luong;
    long long thuong;
    long long thucLanh;

public:
    NhanVien(string maNV="", string hoTen="", string phongBan="", long long luong=0, long long thuong=0, long long thucLanh=0) {
        this->maNV = maNV;
        this->hoTen = hoTen;
        this-> phongBan = phongBan;
        this->luong = luong;
        this->thuong = thuong;
        this->thucLanh = luong + thuong;
    }

    void input() {
        cout << "Nhap ma NV: ";
        cin >> maNV;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap phong ban: ";
        cin >> phongBan;
        cout << "Nhap luong co ban: ";
        cin >> luong;
        cout << "Nhap thuong: ";
        cin >> thuong;
        thucLanh = luong + thuong;
    }

    void display() {
        cout << "\nMa NV: " << maNV
             << " | Ho ten: " << hoTen
             << " | Phong ban: " << phongBan
             << " | Luong co ban: " << luong
             << " | Thuong: " << thuong
             << " | Thuc lanh: " << thucLanh << "\n";
    }

    int getTotal() const { return thucLanh; }
    int getSalary() const { return luong; }
    int getBonus() const { return thuong; }
    string getId() const { return maNV; }
    string getDept() const { return phongBan; }
};

bool cmp(const NhanVien &a, const NhanVien &b) {
    if (a.getDept() == b.getDept())
        return a.getId() > b.getId();
    return a.getDept() < b.getDept();
}

int main() {
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;

    vector<NhanVien> nhanVien;

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin nhan vien thu " << i+1 << ":\n";
        NhanVien e;
        e.input();
        nhanVien.push_back(e);
    }

    cout << "\nDanh sach nhan vien\n";
    for (auto &e : nhanVien)
        e.display();

    long long sum = 0;
    for (auto &e : nhanVien) 
        sum += e.getTotal();

    cout << "\nTong thuc lanh cua tat ca nhan vien: " << sum << "\n";

    int minLuong = nhanVien[0].getSalary();
    for (auto &e : nhanVien)
        if (e.getSalary() < minLuong)
            minLuong = e.getSalary();

    cout << "\nNhan vien co luong co ban thap nhat:\n";
    for (auto &e : nhanVien)
        if (e.getSalary() == minLuong) 
            e.display();

    int cnt = 0;
    for (auto &e : nhanVien)
        if (e.getBonus() >= 1200000)
            cnt++;
    cout << "\nSo nhan vien co muc thuong >= 1200000: " << cnt << "\n";

    sort(nhanVien.begin(), nhanVien.end(), cmp);
    cout << "Danh sach sau khi sap xep:\n";
    for (auto &e : nhanVien)
        e.display();

    return 0;
}
