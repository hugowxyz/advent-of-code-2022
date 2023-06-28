#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <climits>

constexpr int N = 5;
int grid[N][N];
bool visited[N][N];

int calculate_scenic_score(int r, int c) {
    int score = 1, score_temp = 0, prev = INT_MIN;
    // right
    for (int ct=c+1; ct<N; ct++) {
        if (prev >= grid[r][c]) {
            if (grid[r][ct] > prev) {
            // std::cout << "1" << std::endl;
            score_temp++;
            // visited[r][ct] = true;
            }

            if (grid[r][ct] > prev) {
                prev = grid[r][ct];
            }
        } else {
            score_temp++;
        }  
    }

    std::cout << score_temp << " aaa" << std::endl;
    score *= score_temp;

    score_temp = 0;
    prev = INT_MIN;
    for (int ct=c-1; ct>=0; ct--) {
        if (prev >= grid[r][c]) {
            if (grid[r][ct] > prev) {
            // std::cout << "1" << std::endl;
            score_temp++;
            // visited[r][ct] = true;
            }

            if (grid[r][ct] > prev) {
                prev = grid[r][ct];
            }
        } else {
            score_temp++;
        }  
    }

    std::cout << score_temp << " aaa" << std::endl;
    score *= score_temp;

    score_temp = 0;
    prev = INT_MIN;
    for (int rt=r+1; rt<N; rt++) {
        if (prev >= grid[r][c]) {
            if (grid[rt][c] > prev) {
            // std::cout << "1" << std::endl;
            score_temp++;
            // visited[r][ct] = true;
            }

            if (grid[rt][c] > prev) {
                prev = grid[rt][c];
            }
        } else {
            score_temp++;
        }  
    }

    std::cout << score_temp << " aaa" << std::endl;
    score *= score_temp;

    score_temp = 0;
    prev = INT_MIN;
    for (int rt=r-1; rt>=0; rt--) {
        if (prev >= grid[r][c]) {
            if (grid[rt][c] > prev) {
            // std::cout << "1" << std::endl;
            score_temp++;
            // visited[r][ct] = true;
            }

            if (grid[rt][c] > prev) {
                prev = grid[rt][c];
            }
        } else {
            score_temp++;
        }  
    }

    std::cout << score_temp << " aaa" << std::endl;
    score *= score_temp;
    return score;
}

int main() {
    int i = 0, j = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        for (char c : line) {
            grid[i][j++] = c - '0';
        }
        i++; j = 0;
    }

    int ans = INT_MIN;

    std::cout << calculate_scenic_score(3, 2) << std::endl;

    // for (int r=0; r<N; r++) {
    //     for (int c=0; c<N; c++) {
    //         int res = calculate_scenic_score(r, c);
    //         // std::cout << res << std::endl;
    //         if (res > ans) {
    //             ans = res;
    //         }
    //     }
    // }

    std::cout << ans << std::endl;
}