#include <iostream>
#include <string>
using namespace std;

class FareTable {
public:
    static int baseFarePaise(int zone) {
        if (zone == 1) return 1000;
        if (zone == 2) return 2000;
        if (zone == 3) return 3000;
        return 0;
    }
};

class SmartCard {
    long long balancePaise;
public:
    explicit SmartCard(long long balance) : balancePaise(balance) {}
    bool canTravel(long long fare) const {
        return fare > 0 && balancePaise - fare >= 5000;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balancePaise -= fare;
        return true;
    }
    long long balance() const { return balancePaise; }
};

int main() {
    SmartCard card(10000);
    int zone = 3;
    int fare = FareTable::baseFarePaise(zone);
    if (card.deduct(fare))
        cout << "Journey approved. Fare Rs " << fare / 100
             << "." << (fare % 100 < 10 ? "0" : "") << fare % 100 << '\n';
    else
        cout << "Journey denied.\n";
    cout << "Remaining balance in paise: " << card.balance() << '\n';
}