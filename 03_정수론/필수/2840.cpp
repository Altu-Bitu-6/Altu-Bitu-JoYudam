#include <iostream>
#include <vector>

void rotateWheel(int wheel_size, int rotation_count, int &arrow_index,
                 std::vector<char> &wheel) {
    for (int i = 0; i < rotation_count; i++) {
        int change_count;
        char letter;
        std::cin >> change_count >> letter;

        change_count %= wheel_size;
        arrow_index = (arrow_index + change_count) % wheel_size;
        if (wheel[arrow_index] != letter && wheel[arrow_index] != '?') {
            std::cout << "!\n";
            return;
        }

        wheel[arrow_index] = letter;
    }
}

int main() {
    int wheel_size, rotation_count;
    std::cin >> wheel_size >> rotation_count;

    std::vector<char> wheel(wheel_size, '?');

    int arrow_index = 0;
    rotateWheel(wheel_size, rotation_count, arrow_index, wheel);

    for (int i = 0; i < wheel_size; i++) {
        for (int j = i + 1; j < wheel_size; j++) {
            if (wheel[i] != '?' && wheel[i] == wheel[j]) {
                std::cout << "!\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < wheel_size; i++) {
        std::cout << wheel[(i + arrow_index) % wheel_size];
    }
    std::cout << '\n';

    return 0;
}
