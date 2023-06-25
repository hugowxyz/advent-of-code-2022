#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    long long answer = 0;
    char opponent, you;
    std::string line;
    // A, B, C = rock, paper, scissors
    // X, Y, Z = lose, draw, win
    int weights[3][3] = {
        {
            3, 1, 2
        }, 
        {
            1, 2, 3
        },
        {
            2, 3, 1
        }
    };

    while (std::getline(std::cin, line)) {
        opponent = line[0];
        you = line[2];

        answer += weights[opponent - 'A'][2 - ('Z' - you)];

        if (you == 'Y') {
            answer += 3;
        } else if (you == 'Z') {
            answer += 6;
        }
    }

    std::cout << answer;

    return 0;
}