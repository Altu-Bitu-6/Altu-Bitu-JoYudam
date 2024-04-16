#include <algorithm>
#include <iostream>

using namespace std;

long long calculateMinimumSpeed(int n, int arr[]) {
    long long speed = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > speed)
            speed = arr[i];
        else {
            if (speed % arr[i])
                speed = (speed / arr[i] + 1) * arr[i];
        }
    }

    return speed;
}

int main() {
    int arr[300000] = {};
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long answer = calculateMinimumSpeed(n, arr);
    cout << answer;

    return 0;
}
