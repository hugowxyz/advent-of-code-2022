#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <cctype>

void increment(int *s, char c) {
    if (std::isupper(c)) {
        s[c - 'A' + 26] += 1;
    } else {
        s[c - 'a'] += 1;
    }
}

int count(int *s, char c) {
    if (std::isupper(c)) {
        return s[c - 'A' + 26];
    } else {
        return s[c - 'a'];
    }

    return 0;
}

int score(char c) {
    if (std::isupper(c)) {
        return c - 'A' + 27;
    } else {
        return c - 'a' + 1;
    }
}

int main() {
    int i, c = 1, result = 0;
    std::string line;
    
    const char N = 52;
    int s[N], tbuf[N];
    std::fill(s, s+N, 0);
    std::fill(tbuf, tbuf+N, 0);

    while (std::getline(std::cin, line)) {
        for (i=0; i<line.size(); i++) {
            if (count(tbuf, line[i]) == 0) {
                increment(s, line[i]);
                increment(tbuf, line[i]);
            }
        }

        std::fill(tbuf, tbuf+N, 0);

        if (c % 3 == 0) {
            for (i=0; i<N; i++) {
                if (s[i] == 3) {
                    if (i < 26) {
                        result += score('a' + i);
                    } else {
                        result += score('A' + i - 26);
                    }

                    break;
                }
            }

            std::fill(s, s+N, 0);
        }

        c++;
    }

    std::cout << "ANSWER: " << result << "\n";

    return 0;
}