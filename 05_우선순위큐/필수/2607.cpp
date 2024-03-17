#include <array>
#include <iostream>
#include <string>

using namespace std;

// 두 단어가 비슷한 구성을 가지는지 확인하는 함수
bool isSimilar(const array<int, 26> &alpha1, const array<int, 26> &alpha2) {
    int diffCount = 0; // 알파벳 개수가 다른 횟수를 저장할 변수
    int totalAlpha1 = 0, totalAlpha2 = 0; // 각각의 알파벳 총 개수를 저장할 변수

    // 두 단어의 알파벳 개수를 비교하여 차이를 계산
    for (int i = 0; i < 26; ++i) {
        totalAlpha1 += alpha1[i];
        totalAlpha2 += alpha2[i];
        diffCount += abs(alpha1[i] - alpha2[i]);
    }

    // 알파벳 개수의 차이와 총 알파벳 개수의 차이가 일정 범위 내에 있는지 확인
    return (diffCount <= 2 && abs(totalAlpha1 - totalAlpha2) <= 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // 단어의 개수 입력

    string first;
    cin >> first; // 첫 번째 단어 입력

    // 첫 번째 단어의 알파벳 개수를 세기
    array<int, 26> alphaCount1 = {0};
    for (char c : first)
        ++alphaCount1[c - 'A'];

    // 나머지 단어들과 비교하여 비슷한 단어의 개수 세기
    int similarWordsCount = 0;
    for (int i = 1; i < n; ++i) {
        string word;
        cin >> word; // 다음 단어 입력

        // 현재 단어의 알파벳 개수를 세기
        array<int, 26> alphaCount2 = {0};
        for (char c : word)
            ++alphaCount2[c - 'A'];

        // 비슷한 구성을 가진 경우 카운트 증가
        if (isSimilar(alphaCount1, alphaCount2))
            ++similarWordsCount;
    }

    // 결과 출력
    cout << similarWordsCount << '\n';

    return 0;
}
