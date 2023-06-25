#include <iostream>
#include <string>

int main() {
    std::string line;
    int index = 0, answer = -1;
    long long currStars = 0, maxStars = -1;
    
    while (std::getline(std::cin, line)) {
        if (line == "") {
            if (currStars > maxStars) {
                answer = index;
                maxStars = currStars;
            } 

            index++;
            currStars = 0;
        } else {
            currStars += std::stoll(line);
        }
    }

    std::cout << maxStars;
    
    return 0;
}