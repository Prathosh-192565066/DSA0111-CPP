#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int zoneNumber = 3;
    long long farePaise = 3000;
    long long journeys = 3000000LL;
    double rupees = static_cast<double>(farePaise) / 100.0;

    cout << "sizeof(bool): " << sizeof(bool) << '\n';
    cout << "sizeof(char): " << sizeof(char) << '\n';
    cout << "sizeof(int): " << sizeof(int) << '\n';
    cout << "sizeof(long long): " << sizeof(long long) << '\n';
    cout << "sizeof(float): " << sizeof(float) << '\n';
    cout << "sizeof(double): " << sizeof(double) << '\n';
    cout << "Zone: " << zoneNumber << ", fare: Rs "
         << fixed << setprecision(2) << rupees << '\n';
    cout << "Network total at Rs 30 per journey: "
         << journeys * farePaise << " paise\n";
    cout << "INT_MAX: " << INT_MAX << '\n';
    cout << "LLONG_MAX: " << LLONG_MAX << '\n';
}