#include <cmath>
#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    // 초기 상태 입력 받기
    int W0, I0, T;
    cin >> W0 >> I0 >> T;

    // 다이어트 기간 입력 받기
    int D, I, A;
    cin >> D >> I >> A;

    // 초기 상태에서의 일일 기초 대사량 설정
    int daily_metabolic_rate = I0;

    // 체중과 일일 기초 대사량을 저장할 변수 설정
    int weight = W0;

    // 다이어트 기간 동안의 체중과 일일 기초 대사량 계산
    for (int day = 0; day < D; ++day) {
        // 다이어트 기간 동안의 총 일일 에너지 섭취량과 총 일일 활동 대사량 계산
        int total_daily_intake = I;
        int total_daily_activity = A;

        // 체중 변화량 계산
        int energy_difference =
            total_daily_intake - (daily_metabolic_rate + total_daily_activity);
        weight += energy_difference;

        // 일일 기초 대사량 변화량 계산
        if (abs(energy_difference) > T) {
            daily_metabolic_rate += floor(energy_difference / 2.0);
        }

        // 일일 기초 대사량은 최소 0 Kcal 이상이어야 함
        if (daily_metabolic_rate <= 0 || weight <= 0) {
            cout << W0 << " " << I0 << endl;
            cout << "Danger Diet" << endl;
            return 0;
        }
    }

    // 첫 번째 줄: 일일 기초 대사량의 변화를 고려하지 않았을 때의 다이어트 후
    // 예상 체중 출력
    cout << W0 << " " << I0 << endl;

    // 두 번째 줄: 일일 기초 대사량의 변화를 고려했을 때의 다이어트 후 예상
    // 체중과 일일 기초 대사량을 출력하고, 요요 현상 발생 여부 출력
    cout << weight << " " << daily_metabolic_rate << " ";
    if (I0 - daily_metabolic_rate > 0) {
        cout << "YOYO" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
