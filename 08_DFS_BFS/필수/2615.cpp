#include <iostream>
#define MAX 19
using namespace std;

int graph[MAX][MAX];
bool visited[MAX][MAX][4];

// 4개의 주요 방향 정의: 가로, 세로, 우하향 대각선, 우상향 대각선
int moving[4][2] = { {0,1},{1,0},{1,1},{-1,1} };

bool check(int r, int c, int color) {
    for (int dir = 0; dir < 4; ++dir) {
        if (visited[r][c][dir]) continue; // 이미 탐색한 방향은 스킵

        int cnt = 1; // 현재 바둑알 포함
        int nR = r, nC = c;

        // 현재 방향으로 연속된 바둑알 탐색
        for (int i = 1; i < 5; ++i) {
            nR += moving[dir][0];
            nC += moving[dir][1];
            if (nR < 0 || nR >= MAX || nC < 0 || nC >= MAX || graph[nR][nC] != color) break;
            ++cnt;
        }

        if (cnt == 5) {
            // 연속된 바둑알의 반대 방향 체크
            int prevR = r - moving[dir][0];
            int prevC = c - moving[dir][1];
            int nextR = nR + moving[dir][0];
            int nextC = nC + moving[dir][1];
            
            // 연속된 바둑알의 양 끝이 경계 내에 있고, 반대 방향에 같은 색의 바둑알이 없는 경우 승리
            if (!((prevR >= 0 && prevR < MAX && prevC >= 0 && prevC < MAX && graph[prevR][prevC] == color) ||
                  (nextR >= 0 && nextR < MAX && nextC >= 0 && nextC < MAX && graph[nextR][nextC] == color))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (graph[i][j] != 0) {
                if (check(i, j, graph[i][j])) {
                    cout << graph[i][j] << '\n' << i + 1 << ' ' << j + 1;
                    return 0;
                }
            }
        }
    }

    cout << 0;
    return 0;
}
