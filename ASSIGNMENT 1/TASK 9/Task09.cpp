#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Zone { Inner = 1, Middle = 2, Outer = 3 };
constexpr long long MIN_BALANCE = 5000;

bool isPeak(int hour, int minute) {
    int total = hour * 60 + minute;
    return (total >= 8 * 60 && total < 10 * 60) ||
           (total >= 17 * 60 && total < 20 * 60);
}
long long baseFare(Zone z) {
    switch (z) {
        case Zone::Inner: return 1000;
        case Zone::Middle: return 2000;
        case Zone::Outer: return 3000;
    }
    return 0;
}
long long calculateFare(Zone z, int hour, int minute) {
    long long fare = baseFare(z);
    if (fare == 0) return 0;
    if (isPeak(hour, minute)) fare += fare * 20 / 100;
    return fare;
}
bool canTravel(long long balance, long long fare) {
    return fare > 0 && balance - fare >= MIN_BALANCE;
}

int main() {
    struct Test { string name; Zone zone; int hour; int minute; long long balance; long long expectedFare; bool expectedAllowed; };
    vector<Test> tests = {
        {"Inner off-peak", Zone::Inner, 11, 0, 10000, 1000, true},
        {"Middle peak", Zone::Middle, 9, 0, 10000, 2400, true},
        {"Outer off-peak", Zone::Outer, 10, 0, 10000, 3000, true},
        {"Exactly 08:00", Zone::Inner, 8, 0, 10000, 1200, true},
        {"Exactly 10:00", Zone::Inner, 10, 0, 10000, 1000, true},
        {"Exactly 17:00", Zone::Outer, 17, 0, 10000, 3600, true},
        {"Exactly 20:00", Zone::Outer, 20, 0, 10000, 3000, true},
        {"Leaves exactly Rs50", Zone::Outer, 12, 0, 8000, 3000, true}
    };
    cout << "TEST CASES\n";
    for (const auto& t : tests) {
        long long f = calculateFare(t.zone, t.hour, t.minute);
        bool allowed = canTravel(t.balance, f);
        bool pass = (f == t.expectedFare && allowed == t.expectedAllowed);
        cout << t.name << ": fare=" << f << " paise, "
             << (allowed ? "APPROVED" : "DENIED") << " [" << (pass ? "PASS" : "FAIL") << "]\n";
    }

    long long balance = 20000;
    long long total = 0;
    struct Trip { Zone zone; int hour; int minute; };
    Trip day[] = {{Zone::Inner, 11, 0}, {Zone::Middle, 9, 0},
                  {Zone::Outer, 10, 0}, {Zone::Inner, 8, 0},
                  {Zone::Middle, 20, 0}};
    for (const auto& t : day) {
        long long f = calculateFare(t.zone, t.hour, t.minute);
        if (canTravel(balance, f)) { balance -= f; total += f; }
    }
    cout << "Five-journey total: " << total << " paise; remaining: "
         << balance << " paise\n";

    cout << "Invalid zone check: "
         << (baseFare(static_cast<Zone>(99)) == 0 ? "REJECTED" : "ACCEPTED") << '\n';
    long long recharge = -500;
    cout << "Negative recharge check: " << (recharge < 0 ? "REJECTED" : "ACCEPTED") << '\n';
}