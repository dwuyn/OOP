#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   
#include <climits>
using namespace std;

class cArray {
private:
    vector<int> arr;
    int n;

public:
    cArray(int n) {
        this->n = n;
        arr.resize(n);
        srand(time(nullptr));

        for (int i = 0; i < n; ++i) 
            arr[i] = rand() % 1001 - 50;
    }

    void print() const {
        cout << "array: ";
        for (int x : arr) 
            cout << x << " ";
        cout << endl;
    }

    int soAmLonNhat() const {
        int maxAm = INT_MIN;
        bool found = false;
        for (int x : arr) {
            if (x < 0 && (x > maxAm || !found)) {
                maxAm = x;
                found = true;
            }
        }
        return found ? maxAm : 0;
    }

    int demSoLanXuatHien(int x) const {
        int count = 0;
        for (int val : arr)
            if (val == x) count++;
        return count;
    }

    bool checkGiamDan() const {
        for (int i = 0; i < n - 1; i++)
            if (arr[i] < arr[i + 1]) return false;
        return true;
    }

    void sapXepTangDan() {
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j) 
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
    }
};

int main() {
    int n;
    cout << "input n: ";
    cin >> n;

    cArray a(n);

    a.print();

    int maxAm = a.soAmLonNhat();
    if (maxAm != 0)
        cout << "So am lon nhat trong mang: " << maxAm << endl;
    else
        cout << "Mang khong co so am.\n";

    int x;
    cout << "\nNhap so nguyen x de dem so lan xuat hien: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << ": " << a.demSoLanXuatHien(x) << endl;

    cout << "\nMang " << (a.checkGiamDan() ? "co" : "khong") << " giam dan\n";

    a.sapXepTangDan();
    cout << "\nMang sau khi sap xep tang dan:\n";
    a.print();

    return 0;
}
