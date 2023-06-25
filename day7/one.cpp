#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>

struct fs_node {
    std::string name;
    int size;
    fs_node* parent;
    std::unordered_map<std::string, fs_node*> children;
};

int consolidate_size(fs_node* node) {
    for (auto p : node->children) {
        node->size += consolidate_size(p.second);
    }

    return node->size;
}

std::vector<fs_node*> answer;

void dfs(fs_node* node) {
    if (node->size <= 100000) {
        answer.push_back(node);
    }

    for (auto p : node->children) {
        dfs(p.second);
    }
}

int main() {
    std::string line;
    fs_node* curr_dir;
    fs_node* root = new fs_node{"/", 0, nullptr, {}};

    while (std::getline(std::cin, line)) {
        if (line[0] == '$') {
            auto command_arg = line.substr(2);
            auto idx = command_arg.find(" ");
            auto command = command_arg.substr(0, idx);
            auto arg = command_arg.substr(idx + 1);
            
            if (command == "cd") {
                if (arg == "/") {
                    curr_dir = root;
                } else if (arg == "..") {
                    curr_dir = curr_dir->parent;
                } else {
                    if (curr_dir->children.count(arg) == 0) {
                        auto node = new fs_node{arg, 0, curr_dir, {}};
                        curr_dir->children[arg] = node;
                    }

                    curr_dir = curr_dir->children[arg];
                }
            } else if (command == "ls") {
                if (curr_dir->size != 0) {
                    continue;
                }

                while (std::cin.peek() != '$' && std::cin.peek() != EOF) {
                    std::string ls_line;
                    std::getline(std::cin, ls_line);
                    
                    if (!std::isdigit(ls_line[0])) {
                        continue;
                    }

                    auto idx = ls_line.find(" ");
                    auto size = std::stoi(ls_line.substr(0, idx));
                    auto file_name = ls_line.substr(idx + 1);
                    curr_dir->size += size;
                }
            }
        }
    }

    consolidate_size(root);
    dfs(root);

    int res = 0;
    for (auto i : answer) {
        res += i->size;
    }

    std::cout << res << std::endl;
    
    return 0;
}