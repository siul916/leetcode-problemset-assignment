#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string word : strs) {
            string key = word;
            sort(key.begin(), key.end());

            groups[key].push_back(word);
        }

        vector<vector<string>> result;

        for (auto group : groups) {
            result.push_back(group.second);
        }

        return result;
    }
};

void printGroups(vector<vector<string>> groups) {
    cout << "[";

    for (int i = 0; i < groups.size(); i++) {
        cout << "[";

        for (int j = 0; j < groups[i].size(); j++) {
            cout << "\"" << groups[i][j] << "\"";

            if (j + 1 < groups[i].size()) {
                cout << ",";
            }
        }

        cout << "]";

        if (i + 1 < groups.size()) {
            cout << ",";
        }
    }

    cout << "]" << endl;
}

int main() {
    Solution solution;

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = solution.groupAnagrams(strs);

    printGroups(result);

    return 0;
}
