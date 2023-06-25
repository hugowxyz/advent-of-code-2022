#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <cctype>

int main() {
    int i, mid, result = 0;
    std::string line;
    
    const char N = 52;
    std::unordered_set<char> s(N);

    while (std::getline(std::cin, line)) {
        mid = line.size() / 2;
        for (i=0; i<mid; i++) {
            s.insert(line[i]);
        }

        for (i=mid; i<line.size(); i++) {
            if (s.count(line[i]) != 0) {
                if (std::isupper(line[i])) {
                    result = result + line[i] - 'A' + 27;
                } else {
                    result = result + line[i] - 'a' + 1;
                }

                break;
            }
        }

        s.clear();
    }

    std::cout << result << "\n";

    return 0;
}