//368. Largest Divisible Subset
//problem link https://leetcode.com/problems/largest-divisible-subset/description/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<int> t(n, 1);

        vector<int> prev_idx(n, -1);
        int last_chosen_index = 0;
        int maxL = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j] == 0) {
                    if(t[i] < t[j]+1) {
                        t[i] = t[j]+1;
                        prev_idx[i] = j;
                    }

                    if(t[i] > maxL) {
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }
            }
        }

        vector<int> result;
        while(last_chosen_index >= 0) {
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        return result;
    }
};

/****************************************     ************************ */
//2099. Find Subsequence of Length K With the Largest Sum
//problem link-https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Pair each element with its index
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }
        
        // Sort the array by values in descending order
        sort(indexedNums.begin(), indexedNums.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        });
        
        // Take the first k elements
        vector<pair<int, int>> topK(indexedNums.begin(), indexedNums.begin() + k);
        
        // Sort the selected elements based on their original indices
        sort(topK.begin(), topK.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });
        
        // Extract the values to form the result subsequence
        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }
        
        return result;
    }
};


/***************************************************** **********************/
//2385. Amount of Time for Binary Tree to Be Infected
//problem link https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10

class Solution {
public:
    int result=INT_MIN;
    int solve(TreeNode* root,int start){
        if(root==NULL)return 0;

        int LH=solve(root->left,start);
        int RH=solve(root->right,start);

        if(root->val==start){
            result=max(LH,RH);
            return -1;
        }
        else if(LH>=0 && RH>=0){
            return max(LH,RH)+1;
        }else{
            int d=abs(LH)+abs(RH);
            result=max(result,d);
            return min(LH,RH)-1;
        }
        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        solve(root,start);
        return result;
    }
};

