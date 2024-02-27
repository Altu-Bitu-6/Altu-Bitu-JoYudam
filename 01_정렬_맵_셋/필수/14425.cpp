#include <cmath>
#include <iostream>
#include <tuple>
using namespace std;

// 다이어트 함수 정의
tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) {
    // 초기값 설정
    int w1 = w0, m1 = i0; // 기초대사량 변화 고려 X
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려 O

    // 다이어트 기간 동안의 체중과 기초 대사량 계산
    while (d--) {
        // 체중 변화량 계산: 체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
        // 일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
        w1 += i - (m1 + a);
        w2 += i - (m2 + a);

        // 일일 기초대사량 변화 (m2만 변화)
        if (abs(i - (m2 + a)) > t) {
            // float끼리의 나눗셈으로 수행하고 소수점 버림
            m2 += float(i - (m2 + a)) / 2.0;
        }
    }
    // 결과 반환
    return {w1, w2, m2};
}

// 메인 함수
int main() {
    // 입력 변수 선언
    int w0, i0, i, a; // 초기 체중, 초기 일일 에너지 섭취량 및 기초 대사량,
                      // 다이어트 기간 일일 에너지 섭취량 및 활동 대사량
    int d, t; // 다이어트 기간, 기초 대사량 변화 역치

    // 입력 받기
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    // 다이어트 함수 호출
    tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t);
    int w1 = get<0>(tmp), m1 = i0;          // 기초대사량 변화 고려 X
    int w2 = get<1>(tmp), m2 = get<2>(tmp); // 기초대사량 변화 고려 O

    // 첫 번째 결과 출력
    if (w1 <= 0) {
        // 다이어트 도중 데시의 사망이 예상되는 경우
        cout << "Danger Diet\n";
    } else {
        // 다이어트 도중 데시의 사망이 예상되지 않는 경우
        cout << w1 << " " << m1 << "\n";
    }

    // 두 번째 결과 출력
    if (w2 <= 0 || m2 <= 0) {
        // 다이어트 도중 데시의 사망이 예상되는 경우
        cout << "Danger Diet";
    } else {
        // 다이어트 도중 데시의 사망이 예상되지 않는 경우
        cout << w2 << " " << m2 << " ";
        if (m2 < i0) {
            // 요요 현상 발생 여부 출력
            cout << "YOYO";
        } else {
            // 요요 현상 미발생 여부 출력
            cout << "NO";
        }
    }

    return 0;
}
