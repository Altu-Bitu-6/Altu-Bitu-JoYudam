#include <deque>
#include <iostream>
#include <string>
#include <vector>
#define MAX 1010

using namespace std;

int numWheels, numCommands;
vector<int> wheel[MAX];
vector<pair<int, int>> commands;

int reverseDirection(int direction) { return (direction == 1) ? -1 : 1; }

vector<pair<int, int>> findTurningWheels(int wheelIdx, int direction) {
    vector<pair<int, int>> turningWheels;
    turningWheels.push_back(make_pair(wheelIdx, direction));

    int leftSide = wheel[wheelIdx].at(2);
    int rightSide;
    int currentDirection = direction;

    for (int i = wheelIdx + 1; i <= numWheels; i++) {
        rightSide = wheel[i].at(6);

        if (leftSide != rightSide) {
            turningWheels.push_back(
                make_pair(i, reverseDirection(currentDirection)));
            leftSide = wheel[i].at(2);
            currentDirection = reverseDirection(currentDirection);
        } else {
            break;
        }
    }

    leftSide = wheel[wheelIdx].at(6);
    rightSide = -1;
    currentDirection = direction;

    for (int i = wheelIdx - 1; i >= 1; i--) {
        rightSide = wheel[i].at(2);

        if (leftSide != rightSide) {
            turningWheels.push_back(
                make_pair(i, reverseDirection(currentDirection)));
            leftSide = wheel[i].at(6);
            currentDirection = reverseDirection(currentDirection);
        } else {
            break;
        }
    }

    return turningWheels;
}

void turnWheel(int wheelIdx, int direction) {
    if (direction == 1) {
        int temp = wheel[wheelIdx].at(7);

        for (int i = 6; i >= 0; i--) {
            wheel[wheelIdx].at(i + 1) = wheel[wheelIdx].at(i);
        }

        wheel[wheelIdx].at(0) = temp;
    } else {
        int temp = wheel[wheelIdx].at(0);

        for (int i = 1; i <= 7; i++) {
            wheel[wheelIdx].at(i - 1) = wheel[wheelIdx].at(i);
        }

        wheel[wheelIdx].at(7) = temp;
    }
}

void executeCommands(vector<pair<int, int>> wheelsToTurn) {
    for (int i = 0; i < wheelsToTurn.size(); i++) {
        int wheelIdx = wheelsToTurn[i].first;
        int direction = wheelsToTurn[i].second;
        turnWheel(wheelIdx, direction);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> numWheels;

    for (int i = 1; i <= numWheels; i++) {
        string state;
        cin >> state;

        for (int j = 0; j < state.length(); j++) {
            wheel[i].push_back(state[j] - '0');
        }
    }

    cin >> numCommands;

    for (int i = 0; i < numCommands; i++) {
        int wheelIdx, direction;
        cin >> wheelIdx >> direction;
        commands.push_back(make_pair(wheelIdx, direction));
    }

    for (int i = 0; i < numCommands; i++) {
        int wheelIdx = commands[i].first;
        int direction = commands[i].second;
        vector<pair<int, int>> wheelsToTurn =
            findTurningWheels(wheelIdx, direction);
        executeCommands(wheelsToTurn);
    }

    int count = 0;
    for (int i = 1; i <= numWheels; i++) {
        if (wheel[i].at(0) == 1) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
