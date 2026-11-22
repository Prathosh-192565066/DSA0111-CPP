#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE = 5000;

bool proceduralCanTravel(long long balance, long long fare) {
    return fare > 0 && balance - fare >= MIN_BALANCE;
}
bool proceduralDeduct(long long& balance, long long fare) {
    if (!proceduralCanTravel(balance, fare)) return false;
    balance -= fare;
    return true;
}

class SmartCard {
    long long balance;
public:
    explicit SmartCard(long long initial) : balance(initial) {}
    bool canTravel(long long fare) const {
        return fare > 0 && balance - fare >= MIN_BALANCE;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balance -= fare;
        return true;
    }
    long long getBalance() const { return balance; }
};

int main() {
    long long proceduralBalance = 10000;
    cout << "Procedural approved: "
         << (proceduralDeduct(proceduralBalance, 3000) ? "yes" : "no")
         << ", balance " << proceduralBalance << '\n';

    SmartCard card(10000);
    cout << "OOP approved: " << (card.deduct(3000) ? "yes" : "no")
         << ", balance " << card.getBalance() << '\n';
    cout << "OOP rejects next fare: " << (!card.deduct(3000) ? "yes" : "no") << '\n';
}