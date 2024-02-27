#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 괄호의 짝을 확인하는 함수
bool isBalanced(const string &str) {
    stack<char> s;

    for (char ch : str) {
        if (ch == '(' || ch == '[') {
            // 왼쪽 괄호일 경우 스택에 push
            s.push(ch);
        } else if (ch == ')' || ch == ']') {
            // 오른쪽 괄호일 경우
            if (s.empty())
                return false; // 스택이 비어있다면 균형이 맞지 않음

            // 스택에서 가장 위에 있는 괄호와 짝을 이루는지 확인
            char top = s.top();
            if ((ch == ')' && top == '(') || (ch == ']' && top == '[')) {
                s.pop(); // 짝을 이루면 스택에서 제거
            } else {
                return false; // 짝이 맞지 않으면 균형이 맞지 않음
            }
        }
    }

    return s.empty(); // 문자열을 모두 순회한 후 스택이 비어있으면 균형이 맞음
}

int main() {
    string input;
    while (true) {
        getline(cin, input);

        if (input == ".")
            break; // 입력이 마침표인 경우 종료

        // 해당 문자열이 균형잡힌 문자열인지 판단하여 출력
        if (isBalanced(input)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
