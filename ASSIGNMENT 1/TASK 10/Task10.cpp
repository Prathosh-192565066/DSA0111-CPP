#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const long long farePaise = 3000;
    const double fareRupees = 30.0;
    const long long counts[] = {20000, 500000, 3000000};

    cout << fixed << setprecision(2);
    for (long long n : counts) {
        long long exactPaise = n * farePaise;
        double floatingRupees = n * fareRupees;
        long long integerRupees = exactPaise / 100;
        cout << "Journeys: " << n
             << " | integer total: Rs " << integerRupees
             << " | double total: Rs " << floatingRupees
             << " | difference: Rs " << (floatingRupees - integerRupees)
             << '\n';
    }
    cout << "3,000,000 journeys in paise: " << 3000000LL * farePaise << '\n';
}