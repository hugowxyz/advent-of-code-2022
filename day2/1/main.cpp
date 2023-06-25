#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    long long answer = 0;
    char opponent, you;
    std::string line;
    std::unordered_map<char, int> weights = {
        {'X', 1},
        {'Y', 2},
        {'Z', 3}
    };

    while (std::getline(std::cin, line)) {
        opponent = line[0];
        you = line[2];

        answer += weights[you];

        if (
            (opponent == 'A' && you == 'X') ||
            (opponent == 'B' && you == 'Y') ||
            (opponent == 'C' && you == 'Z') 
        ) {
            answer += 3;
        } else if (
            (opponent == 'A' && you == 'Z') ||
            (opponent == 'B' && you == 'X') ||
            (opponent == 'C' && you == 'Y') 
        ) {
            answer += 0;
        } else {
            answer += 6;
        }
    }

    std::cout << answer;

    return 0;
}