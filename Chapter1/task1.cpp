#include <iostream>

using namespace std;

void func (int i, int j = 0 ) {
    cout << "So nguyen: " << i << " " << j << endl;
}

void func (float i = 0, float j = 0) {
    cout << "So thuc: " << i << " "<< j << endl;
}

int main() {
    int i = 1, j = 2;
    float f = 1.5, g = 2.5;
    func(); 
    func(i); // su dung func int khi truyen int
    func(f); // su dung func float khi truyen float
    func(i, j); 
    func(f, g);
    return 0;
}

// Output:
// So thuc: 0 0
// So nguyen: 1 0
// So thuc: 1.5 0
// So nguyen: 1 2
// So thuc: 1.5 2.5
