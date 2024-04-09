#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[101]; // 네트워크 상의 컴퓨터를 연결하는 정보를 저장하는 배열
bool visited[101]; // 방문한 컴퓨터를 체크하는 배열

// DFS 함수
void dfs(int node) {
    visited[node] = true; // 현재 노드를 방문했다고 표시
    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m; // 컴퓨터의 수, 연결된 쌍의 수
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // 양방향으로 연결
        adj[v].push_back(u);
    }

    dfs(1); // 1번 컴퓨터부터 탐색 시작

    int count = -1; // 1번 컴퓨터는 제외하고 세야 하므로 -1부터 시작
    for (int i = 1; i <= n; i++) {
        if (visited[i]) count++;
    }

    cout << count << endl;

    return 0;
}
