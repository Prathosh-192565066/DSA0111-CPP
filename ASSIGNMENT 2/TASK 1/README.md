
#include <iostream>
using namespace std;

void change(int a, int& b, int* c) {
    a += 10;
    b += 10;
    *c += 10;
}

int& bigger(int& p, int& q) {
    return p > q ? p : q;
}

void show(int x, int y = 5, int z = 10) {
    cout << x + y + z << " ";
}

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}

void applyConcession(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByPointer(long long* fee, int percent) {
    *fee -= *fee * percent / 100;
}

int main() {
    int a = 1, b = 2, c = 3;

    change(a, b, &c);
    cout << a << " " << b << " " << c << '\n';

    bigger(a, c) = 100;
    cout << a << " " << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << '\n';

    long long fee1 = 45000;
    long long fee2 = 45000;
    long long fee3 = 45000;

    applyByValue(fee1, 10);
    applyConcession(fee2, 10);
    applyByPointer(&fee3, 10);

    cout << "After value: " << fee1 << '\n';
    cout << "After reference: " << fee2 << '\n';
    cout << "After pointer: " << fee3 << '\n';
}


