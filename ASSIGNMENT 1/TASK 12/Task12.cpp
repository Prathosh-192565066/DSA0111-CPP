#include <array>
#include <iostream>
using namespace std;

enum class Zone : int { Inner = 0, Middle = 1, Outer = 2, Airport = 3 };
constexpr array<long long, 4> BASE_FARES = {1000, 2000, 3000, 6000};
constexpr long long MIN_BALANCE = 5000;

class MonthlyPass {
    bool active;
    bool covered[4];
public:
    MonthlyPass(int zoneA, int zoneB) : active(true), covered{false, false, false, false} {
        if (zoneA >= 0 && zoneA < 4) covered[zoneA] = true;
        if (zoneB >= 0 && zoneB < 4) covered[zoneB] = true;
    }
    bool covers(Zone z) const {
        int index = static_cast<int>(z);
        return active && index >= 0 && index < 4 && covered[index];
    }
};

long long calculateFare(Zone zone, bool peak, bool weekend) {
    int index = static_cast<int>(zone);
    if (index < 0 || index >= 4) return 0;
    long long fare = BASE_FARES[static_cast<size_t>(index)];
    if (weekend) {
        fare = fare * 90 / 100; // Weekend discount replaces peak surcharge
    } else if (peak) {
        fare += fare * 20 / 100;
    }
    return fare;
}

class SmartCard {
    long long balance;
public:
    explicit SmartCard(long long amount) : balance(amount) {}
    bool deduct(long long fare) {
        if (fare <= 0 || balance - fare < MIN_BALANCE) return false;
        balance -= fare;
        return true;
    }
    long long getBalance() const { return balance; }
};

int main() {
    cout << "Airport peak weekday fare: " << calculateFare(Zone::Airport, true, false) << " paise\n";
    cout << "Airport weekend fare: " << calculateFare(Zone::Airport, true, true) << " paise\n";
    MonthlyPass pass(static_cast<int>(Zone::Inner), static_cast<int>(Zone::Airport));
    cout << "Pass covers Inner: " << (pass.covers(Zone::Inner) ? "yes" : "no") << '\n';
    cout << "Pass covers Airport: " << (pass.covers(Zone::Airport) ? "yes" : "no") << '\n';
    cout << "Pass covers Middle: " << (pass.covers(Zone::Middle) ? "yes" : "no") << '\n';

    SmartCard card(20000);
    long long airportWeekendFare = calculateFare(Zone::Airport, false, true);
    cout << "Airport weekend journey: "
         << (card.deduct(airportWeekendFare) ? "APPROVED" : "DENIED")
         << ", balance " << card.getBalance() << " paise\n";
}