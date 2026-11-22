
#include <iostream>
using namespace std;

int& highestMark(int marks[], int n) {
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (marks[i] > marks[index]) {
            index = i;
        }
    }

    return marks[index];
}

const int& highestMarkConst(const int marks[], int n) {
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (marks[i] > marks[index]) {
            index = i;
        }
    }

    return marks[index];
}

int highestMarkCopy(const int marks[], int n) {
    int highest = marks[0];

    for (int i = 1; i < n; i++) {
        if (marks[i] > highest) {
            highest = marks[i];
        }
    }

    return highest;
}

// Dangerous: never return a reference to a local variable.
// int& wrongFunction() {
//     int x = 100;
//     return x;
// }

int main() {
    int marks[5] = {75, 90, 85, 95, 80};

    cout << "Highest mark: " << highestMark(marks, 5) << '\n';

    highestMark(marks, 5) += 2;

    cout << "After moderation: ";
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }

    cout << "\nConst reference: "
         << highestMarkConst(marks, 5);

    cout << "\nReturned copy: "
         << highestMarkCopy(marks, 5);

    cout << '\n';
}


