#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Recursive function to generate permutations
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        // Base Case: if idx reaches the end, we found one permutation
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Try placing each element at index 'idx'
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);                  // choose
            getPerms(nums, idx + 1, ans);              // explore
            swap(nums[idx], nums[i]);                  // un-choose (backtrack)
        }
    }

    // Wrapper function
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = obj.permute(nums);

    cout << "All permutations:\n";
    for (auto& perm : result) {
        cout << "{ ";
        for (int x : perm) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
