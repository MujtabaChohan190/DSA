#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Recursive function to generate all subsets
    // Time complexity: O(n * 2^n)
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
        // Base case: if we've processed all elements
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // --------------------
        // INCLUDE nums[i]
        // --------------------
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        // Backtrack: remove the last element
        ans.pop_back();

        // --------------------
        // EXCLUDE nums[i]
        // --------------------
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }

    // Wrapper function to return all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets; // stores all subsets
        vector<int> ans;                // temporary vector for one subset
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = obj.subsets(nums);

    cout << "All subsets are:\n";
    for (auto subset : result) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
