#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

string solution(string text) {
    string part1 = "", part2 = "";
    map<char, int> counter;

    // Count occurrences of each character
    for (char c : text) {
        counter[c]++;
    }

    // Sort the characters by their counts
    for (auto it = counter.begin(); it != counter.end(); ++it) {
        if (it->second % 2 == 1) {
            if (!part2.empty()) {
                return "I'm Sorry Hansoo";
            }
            part2 = it->first;
        }
        part1 += string(it->second / 2, it->first);
    }

    // Concatenate the parts to form the palindrome
    return part1 + part2 + string(part1.rbegin(), part1.rend());
}

int main() {
    string input;
    cin >> input;

    cout << solution(input);

    return 0;
}