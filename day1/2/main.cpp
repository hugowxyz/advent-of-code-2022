#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;
    
    std::string line;
    long long currStars = 0;
    
    while (std::getline(std::cin, line)) {
        if (line == "") {
            pq.push(-currStars);
            if (pq.size() > 3) pq.pop();
            currStars = 0;
        } else {
            currStars += std::stoll(line);
        }
    }

    long long result = 0;
    while (!pq.empty()) {
        result += (-pq.top());
        pq.pop();
    }
    
    std::cout << result;

    return 0;
}