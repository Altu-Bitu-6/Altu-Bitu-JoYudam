#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    string result = "";
    int carry = 0; // 올림 값

    // 두 문자열의 길이를 맞춰줌
    int len1 = num1.length(), len2 = num2.length();
    int maxLength = max(len1, len2);
    num1 = string(maxLength - len1, '0') + num1;
    num2 = string(maxLength - len2, '0') + num2;

    // 뒤에서부터 한 자리씩 더해가면서 결과 문자열을 구함
    for (int i = maxLength - 1; i >= 0; --i) {
        int digitSum = (num1[i] - '0') + (num2[i] - '0') + carry;
        result += to_string(digitSum % 10);
        carry = digitSum / 10;
    }

    // 마지막 올림 값이 있으면 결과 문자열에 추가
    if (carry > 0) {
        result += to_string(carry);
    }

    // 결과 문자열을 뒤집어서 리턴
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;

    string result = addStrings(num1, num2);
    cout << result << endl;

    return 0;
}
