class Solution {
private:
    void solveCombination(vector<vector<int>>& ans1, vector<int>& ans2, int index, int sum, int n, int k){
        //base case
        if(sum == n && k == 0){
            ans1.push_back(ans2);
            return;
        }
        
        if(sum > n){
            return;
        }

        for(int i = index; i <= 9; i++){
            if(i > n){
                break;
            }
            ans2.push_back(i); // stores number one by one
            solveCombination(ans1, ans2, i + 1, sum + i, n, k-1); // recursive function
            ans2.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans2; // stores only 1 combination and assign all combination to ans1
        
        vector<vector<int>> ans1; // stores all valid combinations

        solveCombination(ans1, ans2, 1, 0, n, k);
        return ans1;
    } 
};
