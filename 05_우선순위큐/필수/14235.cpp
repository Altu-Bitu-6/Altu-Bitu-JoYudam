#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> gifts;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (a == 0) {
            if (gifts.empty()) {
                cout << "-1" << endl;
            } else {
                cout << gifts.top() << endl;
                gifts.pop();
            }
        } else {
            for (int j = 0; j < a; ++j) {
                int gift;
                cin >> gift;
                gifts.push(gift);
            }
        }
    }

    return 0;
}
