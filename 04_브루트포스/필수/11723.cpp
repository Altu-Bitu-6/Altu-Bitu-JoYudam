#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    int s = 0; // 비트마스크로 집합 표현, 초기값은 공집합

    while (m--) {
        string op;
        int x;
        cin >> op;

        if (op == "add") {
            cin >> x;
            s |= (1 << (x - 1)); // x에 해당하는 비트를 1로 설정
        } else if (op == "remove") {
            cin >> x;
            s &= ~(1 << (x - 1)); // x에 해당하는 비트를 0으로 설정
        } else if (op == "check") {
            cin >> x;
            cout << ((s & (1 << (x - 1))) ? 1 : 0)
                 << '\n'; // x에 해당하는 비트가 1이면 1 출력, 아니면 0 출력
        } else if (op == "toggle") {
            cin >> x;
            s ^= (1 << (x - 1)); // x에 해당하는 비트의 상태를 반전
        } else if (op == "all") {
            s = (1 << 20) - 1; // 모든 비트를 1로 설정
        } else if (op == "empty") {
            s = 0; // 모든 비트를 0으로 설정 (공집합)
        }
    }

    return 0;
}
