#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Recursive function to generate permutations
    void getPerms(string &s, int idx, vector<string> &ans) {
        // Base Case: when index reaches end of string
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }

        // Fix each character at position idx
        for (int i = idx; i < s.size(); i++) {
            swap(s[idx], s[i]);          // choose
            getPerms(s, idx + 1, ans);   // explore
            swap(s[idx], s[i]);          // un-choose (backtrack)
        }
    }

    // Wrapper function (same idea as before)
    vector<string> permute(string s) {
        vector<string> ans;
        getPerms(s, 0, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    string s = "abc";

    vector<string> result = obj.permute(s);

    cout << "All permutations:\n";
    for (auto &perm : result) {
        cout << perm << "\n";
    }

    return 0;
}
