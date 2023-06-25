#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string line;
    std::cin >> line;

    const int WINDOW = 14;
    int invalidEntries = 0;
    std::unordered_map<char, int> m;
    
    for (int i=0; i<WINDOW; i++) {
        if (m[line[i]] != 0) {
            invalidEntries++;
        }

        m[line[i]]++;
    }

    if (invalidEntries == 0) {
        return WINDOW;
    }

    for (int i=WINDOW; i<line.size(); i++) {
        if (m[line[i-WINDOW]] > 1) {
            invalidEntries--;
        }

        m[line[i-WINDOW]]--;

        if (m[line[i]] == 0 && invalidEntries == 0) {
            std::cout << i + 1 << "\n";
            return 0;
        } 

        if (m[line[i]] != 0) {
            invalidEntries++;
        }

        m[line[i]]++;
    }

    std::cout << "Fail\n";
}