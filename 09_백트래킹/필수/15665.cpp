#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateSequences(vector<int>& seq, vector<int>& numbers, int m, int depth) {
    if (depth == m) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    int prev = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        if (i > 0 && numbers[i] == numbers[i-1]) continue;  // 중복된 수 건너뛰기
        seq.push_back(numbers[i]);
        generateSequences(seq, numbers, m, depth + 1);
        seq.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());  // 중복 제거를 위해 먼저 정렬

    vector<int> seq;
    generateSequences(seq, numbers, m, 0);

    return 0;
}
