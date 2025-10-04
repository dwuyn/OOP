#include <iostream>
using namespace std;

class SoPhuc {
private:
    double phanThuc;
    double phanAo;

public:
    SoPhuc(double thuc = 0, double ao = 0) {
        phanThuc = thuc;
        phanAo = ao;
    }

    void setPhanThuc(double thuc) {
        phanThuc = thuc;
    }

    void setPhanAo(double ao) {
        phanAo = ao;
    }

    double getPhanThuc() const {
        return phanThuc;
    }

    double getPhanAo() const {
        return phanAo;
    }

    void input() {
        cout << "nhap phan thuc: ";
        cin >> phanThuc;
        cout << "nhap phan ao: ";
        cin >> phanAo;
    }

    void print() const {
        if (phanAo >= 0)
            cout << phanThuc << " + " << phanAo << "i";
        else
            cout << phanThuc << " - " << -phanAo << "i";
    }

    SoPhuc cong(const SoPhuc &sp2) const {
        SoPhuc kq;
        kq.phanThuc = this->phanThuc + sp2.phanThuc;
        kq.phanAo = this->phanAo + sp2.phanAo;
        return kq;
    }

    SoPhuc tru(const SoPhuc &sp2) const {
        SoPhuc kq;
        kq.phanThuc = this->phanThuc - sp2.phanThuc;
        kq.phanAo = this->phanAo - sp2.phanAo;
        return kq;
    }

    SoPhuc nhan(const SoPhuc &sp2) const {
        SoPhuc kq;
        kq.phanThuc = this->phanThuc * sp2.phanThuc - this->phanAo * sp2.phanAo;
        kq.phanAo = this->phanThuc * sp2.phanAo + this->phanAo * sp2.phanThuc;
        return kq;
    }

    SoPhuc chia(const SoPhuc &sp2) const {
        SoPhuc kq;
        double mau = sp2.phanThuc * sp2.phanThuc + sp2.phanAo * sp2.phanAo;
        kq.phanThuc = (this->phanThuc * sp2.phanThuc + this->phanAo * sp2.phanAo) / mau;
        kq.phanAo = (this->phanAo * sp2.phanThuc - this->phanThuc * sp2.phanAo) / mau;
        return kq;
    }
};

int main() {
    SoPhuc a, b;

    cout << "nhap so phuc thu nhat:\n";
    a.input();

    cout << "nhap so phuc thu hai:\n";
    b.input();

    cout << "\nso phuc thu nhat: ";
    a.print();
    
    cout << "\nso phuc thu hai: ";
    b.print();

    cout << "\n";

    SoPhuc tong = a.cong(b);
    SoPhuc hieu = a.tru(b);
    SoPhuc tich = a.nhan(b);
    SoPhuc thuong = a.chia(b);

    cout << "\ntong: ";
    tong.print();

    cout << "\nhieu: ";
    hieu.print();

    cout << "\ntich: ";
    tich.print();

    cout << "\nthuong: ";
    thuong.print();

    cout << "\n";

    a.setPhanThuc(10);
    cout << "\nsau khi doi phan thuc so phuc thu nhat: ";
    a.print();

    a.setPhanAo(10);
    cout << "\nsau khi doi phan ao so phuc thu nhat: ";
    a.print();
    cout << "\n";

    cout << "\nlay gia tri phan thuc cua so phuc thu hai: " << b.getPhanThuc() << "\n";
    cout << "lay gia tri phan ao cua so phuc thu hai: " << b.getPhanAo() << "\n";

    return 0;
}

