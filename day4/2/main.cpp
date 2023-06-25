#include <iostream>
#include <string>
#include <sstream>
#include <vector>

    
void parsePair(std::string s, long long &a, long long &b) {
    int i=0;
    std::stringstream ss;
    std::vector<std::string> v(2);

    ss.str(s);
    while (std::getline(ss, v[i++], '-'));

    a = std::stoll(v[0]);
    b = std::stoll(v[1]);
}

int main() {
    int idx, answer = 0;
    long long a, b, c, d;
    std::string line, tbuf;

    while (std::getline(std::cin, line)) {
        idx = line.find(',');

        parsePair(line.substr(0, idx), a , b);
        parsePair(line.substr(idx+1, line.size() - idx - 1), c, d);

        if (!((a < c && b < c) || (c < a & d < a))) {
            answer++;
        }
    }

    std::cout << answer << "\n";
}