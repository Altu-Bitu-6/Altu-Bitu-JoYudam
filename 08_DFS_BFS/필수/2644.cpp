#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n; // 전체 사람 수
int person1, person2; // 촌수를 계산할 두 사람
int m; // 부모 자식간의 관계 수
vector<int> graph[101]; // 관계를 나타내는 그래프
bool visited[101]; // 방문 여부
int distances[101]; // 시작점으로부터의 거리(촌수)

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    distances[start] = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];
            if (!visited[next]) {
                visited[next] = true;
                distances[next] = distances[current] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> person1 >> person2;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child); // 부모에서 자식으로
        graph[child].push_back(parent); // 자식에서 부모로도 갈 수 있게 양방향으로 추가
    }
    
    bfs(person1); // person1에서 시작하는 BFS 실행
    
    if (visited[person2]) { // person2에 도달 가능한 경우
        cout << distances[person2];
    } else { // person2에 도달할 수 없는 경우
        cout << "-1";
    }
    
    return 0;
}
