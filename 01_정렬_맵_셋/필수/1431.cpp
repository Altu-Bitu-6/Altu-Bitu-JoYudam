#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 시리얼 번호를 비교하는 함수
bool compareSerials(string a, string b) {
    // 길이가 다르면 짧은 것이 먼저 옵니다.
    if (a.length() != b.length())
        return a.length() < b.length();
    
    // 길이가 같은 경우 각 자리의 숫자를 더한 합을 비교합니다.
    int sumA = 0, sumB = 0;
    for (char c : a) {
        if (isdigit(c)) sumA += c - '0';
    }
    for (char c : b) {
        if (isdigit(c)) sumB += c - '0';
    }
    if (sumA != sumB) return sumA < sumB;

    // 합이 같은 경우 사전순으로 비교합니다.
    return a < b;
}

int main() {

    int N;
    cin >> N;

    vector<string> serials(N);
    for (int i = 0; i < N; ++i) {
        cin >> serials[i];
    }

    // 시리얼 번호를 정렬합니다.
    sort(serials.begin(), serials.end(), compareSerials);

    // 정렬된 시리얼 번호를 출력합니다.
    for (const string& serial : serials) {
        cout << serial << '\n';
    }

    return 0;
}
