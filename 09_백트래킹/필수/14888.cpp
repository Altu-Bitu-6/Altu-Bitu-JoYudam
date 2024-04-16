#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> numbers;
int max_result = -1000000000;  // 최댓값 초기화
int min_result = 1000000000;   // 최솟값 초기화

// 수행할 연산에 따라 결과를 반환하는 함수
int operate(int a, int b, int op) {
    if (op == 0) return a + b;  // 덧셈
    if (op == 1) return a - b;  // 뺄셈
    if (op == 2) return a * b;  // 곱셈
    if (op == 3) return a / b;  // 나눗셈
    return 0;
}

// 백트래킹을 사용하여 모든 가능한 연산자 조합을 생성하고 계산
void backtrack(int index, int currentResult, vector<int>& operatorCount) {
    if (index == n - 1) {  // 모든 연산자를 사용했을 때
        max_result = max(max_result, currentResult);
        min_result = min(min_result, currentResult);
        return;
    }

    for (int i = 0; i < 4; ++i) {  // 4가지 연산자에 대해
        if (operatorCount[i] > 0) {
            operatorCount[i]--;
            int newResult = operate(currentResult, numbers[index + 1], i);
            backtrack(index + 1, newResult, operatorCount);
            operatorCount[i]++;
        }
    }
}

int main() {
    cin >> n;
    numbers.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<int> operatorCount(4);  // 연산자 개수 (+, -, *, /)
    for (int i = 0; i < 4; ++i) {
        cin >> operatorCount[i];
    }

    // 초기 계산 시작
    backtrack(0, numbers[0], operatorCount);

    // 결과 출력
    cout << max_result << endl;
    cout << min_result << endl;

    return 0;
}
