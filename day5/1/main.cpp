#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

int main() {
    std::vector<std::string> v = {
        "TVJWNRMS", "VCPQJDWB", "PRDHFJB",
        "DNMBPRF", "BTPRVH", "TPBC", "LPRJB",
        "WBZTLSCN", "GSL"
    };

    int NUM_STACKS = 9;
    std::stack<char> stacks[NUM_STACKS];
    
    for (int i=0; i<NUM_STACKS; i++) {
        std::reverse(v[i].begin(), v[i].end());
        for (auto c : v[i]) {
               stacks[i].push(c);
        }
    }

    std::string line;
    for (int i=0; i<10; i++) {
        std::getline(std::cin, line);
    }

    const int N = 6;
    std::vector<std::string> cmds(N);
    int cidx, cmd[3];
    std::stringstream ss;
    while (std::getline(std::cin, line)) {
        cidx = 0;
        
        ss.clear();
        ss.str(line);
        while (std::getline(ss, cmds[cidx++], ' '));

        cmd[0] = std::stoi(cmds[1]);
        cmd[1] = std::stoi(cmds[3]) - 1;
        cmd[2] = std::stoi(cmds[5]) - 1;

        std::cout << cmd[0] << " " << cmd[1] << " " << cmd[2] << std::endl;

        while (cmd[0]-- > 0) {
            if (stacks[cmd[1]].empty()) {
                break;
            }

            stacks[cmd[2]].push(stacks[cmd[1]].top());
            stacks[cmd[1]].pop();
        }
    }

    for (auto s : stacks) {
        std::cout << s.top();
    }
}