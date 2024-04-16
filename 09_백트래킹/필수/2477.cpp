#include <iostream>
using namespace std;

int K;
int direction[12];
int length[12];

void inputData() {
    cin >> K;
    for (int i = 0; i < 6; i++) {
        cin >> direction[i] >> length[i];
        direction[6 + i] = direction[i]; // 배열 확장
        length[6 + i] = length[i];       // 배열 확장
    }
}

int solve() {
    int small_area = 0, big_area = 0;
    for (int i = 0; i < 6; i++) {
        // 패턴 매칭을 위한 반복
        if ((direction[i] == 1 && direction[i+1] == 3) || 
            (direction[i] == 4 && direction[i+1] == 1) || 
            (direction[i] == 2 && direction[i+1] == 4) || 
            (direction[i] == 3 && direction[i+1] == 2)) {
            // 작은 사각형 면적
            small_area = length[i] * length[i+1];
            // 큰 사각형 면적 (순환 구조를 이용)
            big_area = length[i+3] * length[i+4];
            return K * (big_area - small_area);
        }
    }
    return 0; // 패턴 매칭 실패 시 0 반환
}

int main() {
    inputData(); // 입력 받기
    int ans = solve(); // 면적 계산 및 참외 수 계산
    cout << ans << endl; // 결과 출력
    return 0;
}
