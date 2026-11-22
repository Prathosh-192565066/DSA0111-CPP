#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_PERCENT = 20;
constexpr long long FARES[] = {1000, 2000, 3000};

long long calculateFare(Zone zone, bool peak) {
    long long fare = 0;
    switch (zone) {
        case Zone::Inner: fare = FARES[0]; break;
        case Zone::Middle: fare = FARES[1]; break;
        case Zone::Outer: fare = FARES[2]; break;
    }
    if (peak) fare += fare * PEAK_PERCENT / 100;
    return fare;
}

class SmartCard {
    long long balancePaise;
public:
    explicit SmartCard(long long initial) : balancePaise(initial) {}
    bool deduct(long long fare) {
        if (fare <= 0 || balancePaise - fare < MIN_BALANCE_PAISE) return false;
        balancePaise -= fare;
        return true;
    }
    long long balance() const { return balancePaise; }
};

int main() {
    SmartCard card(10000);
    long long fare = calculateFare(Zone::Outer, true);
    cout << "Calculated fare: " << fare << " paise\n";
    cout << "Journey: " << (card.deduct(fare) ? "APPROVED" : "DENIED") << '\n';
    cout << "Remaining: " << card.balance() << " paise\n";
    cout << "Daily network total for 3,000,000 Outer off-peak trips: "
         << 3000000LL * FARES[2] << " paise\n";
}