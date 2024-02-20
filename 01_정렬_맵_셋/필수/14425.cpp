#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    cin >> N;

    int M;
    cin >> M;

    vector<string> arr1(N);
    int count = 0;
    for (int i = 0; i < N; ++i) {
        cin >> arr1[i];
    }

    for (int j = 0; j < M; ++j) {
        string K;
        cin >> K;
        for (int i = 0; i < N; ++i) {
            if (arr1[i] == K) {
                cout << K << std::endl;
                count++;
            }
        }
    }
    cout << count;

    return 0;
}
