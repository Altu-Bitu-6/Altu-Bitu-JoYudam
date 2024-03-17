#include <iostream>
#include <queue> // 우선순위 큐를 사용하기 위해 필요
#include <vector>

using namespace std;

// n번째로 큰 수를 찾는 함수
int findNthLargest(int n) {
    priority_queue<int, vector<int>, greater<int>>
        minHeap; // 오름차순 정렬을 위한 최소 힙
    int value;
    for (int i = 0; i < n * n; i++) {
        cin >> value;
        minHeap.push(value); // 힙에 수를 삽입
        if (minHeap.size() > n) {
            minHeap.pop(); // 힙의 크기가 n을 초과하면 가장 작은 수를 제거하여
        }
        // 상위 n개의 수를 유지
    }
    return minHeap
        .top(); // 상위 n개의 수 중 가장 작은 수, 즉 n번째로 큰 수 반환
}

int main() {
    ios_base::sync_with_stdio(
        false);       // C++ iostream과 C의 stdio를 동기화하지 않음
    cin.tie(nullptr); // cin과 cout이 상호간에 묶이는 것을 방지

    int n;
    cin >> n;                           // n 입력 받기
    int nthLargest = findNthLargest(n); // n번째로 큰 수 찾기
    cout << nthLargest;                 // n번째로 큰 수 출력

    return 0;
}
