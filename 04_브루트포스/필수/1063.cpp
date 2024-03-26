#include <iostream>
#include <string>
using namespace std;

const int BOARD_SIZE = 8;

// 이동 방향에 대한 상대 좌표
int dx[BOARD_SIZE] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[BOARD_SIZE] = {1, -1, 0, 0, 1, -1, 1, -1};

int main(void) {
    string king_pos, stone_pos, direction;
    int n;
    cin >> king_pos >> stone_pos >> n;

    // 킹과 돌의 초기 위치를 좌표로 변환
    int king_col = king_pos[0] - 'A';
    int stone_col = stone_pos[0] - 'A';
    int king_row = BOARD_SIZE - (king_pos[1] - '0');
    int stone_row = BOARD_SIZE - (stone_pos[1] - '0');

    int dir = 0;
    for (int i = 0; i < n; i++) {
        cin >> direction;

        // 입력된 방향에 따라 방향 설정
        if (!direction.compare("R"))
            dir = 0;
        else if (!direction.compare("L"))
            dir = 1;
        else if (!direction.compare("B"))
            dir = 2;
        else if (!direction.compare("T"))
            dir = 3;
        else if (!direction.compare("RT"))
            dir = 4;
        else if (!direction.compare("LT"))
            dir = 5;
        else if (!direction.compare("RB"))
            dir = 6;
        else if (!direction.compare("LB"))
            dir = 7;

        // 킹의 새로운 위치 계산
        int newKing_row = king_row + dx[dir];
        int newKing_col = king_col + dy[dir];

        // 새로운 위치가 체스판을 벗어나면 무시
        if (newKing_row < 0 || newKing_row >= BOARD_SIZE || newKing_col < 0 ||
            newKing_col >= BOARD_SIZE)
            continue;

        // 새로운 위치에 돌이 있는 경우
        if (newKing_row == stone_row && newKing_col == stone_col) {
            // 돌을 이동시킨 새로운 위치 계산
            int newStone_row = stone_row + dx[dir];
            int newStone_col = stone_col + dy[dir];

            // 돌의 새로운 위치가 체스판을 벗어나면 무시
            if (newStone_row < 0 || newStone_row >= BOARD_SIZE ||
                newStone_col < 0 || newStone_col >= BOARD_SIZE)
                continue;

            // 킹과 돌의 새로운 위치 업데이트
            stone_row = newStone_row;
            stone_col = newStone_col;
        }

        // 킹의 새로운 위치 업데이트
        king_row = newKing_row;
        king_col = newKing_col;
    }

    // 결과 출력
    cout << (char)(king_col + 'A') << BOARD_SIZE - king_row << '\n';
    cout << (char)(stone_col + 'A') << BOARD_SIZE - stone_row << '\n';

    return 0;
}
