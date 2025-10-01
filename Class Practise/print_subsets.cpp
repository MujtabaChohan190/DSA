void printSubsets(vector<int> &arr, vector<int> &ans, int i) {
    if(i == arr.size()){
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    //include
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i+1);

    ans.pop_back(); //backtrack

    //exclude
    printSubsets(arr, ans, i+1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans; //store subsets

    printSubsets(arr, ans, 0);

    return 0;
}
