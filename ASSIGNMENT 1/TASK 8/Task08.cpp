#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int hour;
    cout << "Enter journey hour (0-23): ";
    if (!(cin >> hour)) {
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input error cleared.\n";
        return 0;
    }
    if (hour < 0 || hour > 23) {
        cout << "Hour out of range.\n";
        return 0;
    }

    long long balancePaise = 10000;
    cout << "Hour accepted: " << hour << '\n';
    cout << "Balance: Rs " << fixed << setprecision(2)
         << static_cast<double>(balancePaise) / 100.0 << '\n';
    cout << "Report generated.\n";
}