#include <iostream>
#include <queue>

using namespace std;

// 요세푸스 순열을 구하는 함수
string josephusSequence(int N, int K) {
    queue<int> q;

    // 큐에 1부터 N까지의 숫자를 넣음
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    string sequence = "<";

    while (!q.empty()) {
        // K번째 사람 제거
        for (int i = 0; i < K - 1; ++i) {
            // K-1번째 사람까지는 제거하지 않고 다시 큐의 뒤로 보냄
            int front = q.front();
            q.pop();
            q.push(front);
        }

        // K번째 사람을 제거하여 결과에 추가
        sequence += to_string(q.front()) + ", ";
        q.pop();
    }

    // 마지막 쉼표와 공백 제거 후 마지막 꺽쇠 추가
    sequence.pop_back();
    sequence.pop_back();
    sequence += ">";

    return sequence;
}

int main() {
    int N, K;
    cin >> N >> K;

    // 요세푸스 순열 출력
    cout << josephusSequence(N, K) << endl;

    return 0;
}
