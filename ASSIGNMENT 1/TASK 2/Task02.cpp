#include <iostream>
using namespace std;

constexpr long long INNER_FARE_PAISE = 1000;
constexpr long long MIDDLE_FARE_PAISE = 2000;
constexpr long long OUTER_FARE_PAISE = 3000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

enum class Zone { Inner = 0, Middle = 1, Outer = 2 };

int main() {
    Zone zone = Zone::Middle;
    long long fare = 0;
    switch (zone) {
        case Zone::Inner: fare = INNER_FARE_PAISE; break;
        case Zone::Middle: fare = MIDDLE_FARE_PAISE; break;
        case Zone::Outer: fare = OUTER_FARE_PAISE; break;
    }
    cout << "Middle base fare: " << fare << " paise\n";
    cout << "Minimum remaining balance: " << MIN_BALANCE_PAISE << " paise\n";
    cout << "Peak surcharge: " << PEAK_SURCHARGE_PERCENT << "%\n";
}