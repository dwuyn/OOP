#include <iostream>
#include <iomanip>

using namespace std;

class Student {
private:
    string sID;
    string sName;
    string gender;
    double math;
    double physics;
    double chemistry;

public:
    // Student(string sID="", string sName="", string gender="", double math=0, double physics=0, double chemistry=0) {
    Student() {
        cout << "Nhap ma HS: ";
        cin >> sID;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, sName);
        cout << "Nhap diem Toan: ";
        cin >> math;
        cout << "Nhap diem Ly: ";
        cin >> physics;
        cout << "Nhap diem Hoa: ";
        cin >> chemistry;
    }

    double average() {
        return (math+physics+chemistry) / 3.0;
    }

    void print() {
        cout << "Ma HS: " << sID << "\n";
        cout << "Ho ten: " << sName << "\n";
        cout << "Gioi tinh: " << gender << "\n";
        cout << "Diem toan: " << math << "\n";
        cout << fixed << setprecision(2);
        cout << "Diem ly: " << physics << "\n";
        cout << "Diem hoa: " << chemistry << "\n";
        cout << "Diem trung binh: " << average() << "\n";
    }

};

int main() {
    Student s;
    s.print();

    return 0;
}
