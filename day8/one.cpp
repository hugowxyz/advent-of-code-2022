#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <climits>

int main() {
    constexpr int N = 99;
    int grid[N][N];
    bool visited[N][N];
    int i = 0, j = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        for (char c : line) {
            grid[i][j++] = c - '0';
        }
        i++; j = 0;
    }

    int ans = 0;

    for (int c=0; c<N; c++) {
        int r, prev = INT_MIN, count = 0;
        for (r=0; r<N; r++) {
            if (!(visited[r][c] || grid[r][c] <= prev)) {
                count++;
                visited[r][c] = true;
            }

            if (grid[r][c] > prev) {
                prev = grid[r][c];
            }
        }

        ans += count;

        count = 0;
        prev = INT_MIN;
        for (r=N-1; r>=0; r--) {
            if (!(visited[r][c] || grid[r][c] <= prev)) {
                count++;
                visited[r][c] = true;
            }

            if (grid[r][c] > prev) {
                prev = grid[r][c];
            }
        }

        ans += count;
    }

    for (int r=0; r<N; r++) {
        int c, prev = INT_MIN, count=0;
        for (c=0; c<N; c++) {
            if (!(visited[r][c] || grid[r][c] <= prev)) {
                count++;
                visited[r][c] = true;
            }

            if (grid[r][c] > prev) {
                prev = grid[r][c];
            }
        }

        ans += count;

        count = 0;
        prev = INT_MIN;
        for (c=N-1; c>=0; c--) {
            if (!(visited[r][c] || grid[r][c] <= prev)) {
                count++;
                visited[r][c] = true;
            }

            if (grid[r][c] > prev) {
                prev = grid[r][c];
            }
        }

        ans += count;
    }

    std::cout << ans << std::endl;
}