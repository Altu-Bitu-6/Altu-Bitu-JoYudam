#include <iostream>
#include <string>

using namespace std;

bool isEndOfTheWorldNumber(int n) {
    string num = to_string(n);
    for (int i = 0; i < num.length() - 2; ++i) {
        if (num[i] == '6' && num[i + 1] == '6' && num[i + 2] == '6') {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    int count = 0;
    int number = 666;

    while (true) {
        if (isEndOfTheWorldNumber(number)) {
            ++count;
            if (count == n) {
                cout << number << "\n";
                break;
            }
        }
        ++number;
    }

    return 0;
}
