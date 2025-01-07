//problem Statement 2461. Maximum Sum of Distinct Subarrays With Length K
//Problem Link https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/submissions/1500992703/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long maxi=0,currsum=0;
         
        unordered_set<int>st;
        int i=0,j=0;
        while(j<n){
            //check if nums[j] is already present in current windowor not 
            while(st.count(nums[j])){
                currsum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            currsum+=nums[j];
            st.insert(nums[j]);
            if(j-i+1==k){
                maxi=max(maxi,currsum);

                currsum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return maxi;
    }
};


//problem statemrnt 188. Best Time to Buy and Sell Stock IV
//problem link https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        
        // If k is larger than half the number of days, it's equivalent to unlimited transactions
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }

        // DP table
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int i = 1; i <= k; ++i) {
            int max_diff = -prices[0];
            for (int j = 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + max_diff);
                max_diff = max(max_diff, dp[i - 1][j] - prices[j]);
            }
        }

        return dp[k][n - 1];
    }
};


//problem statement 845. Longest Mountain in Array
//problem link https://leetcode.com/problems/longest-mountain-in-array/description/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0; // A mountain requires at least 3 elements

        int maxLength = 0;
        int i = 1;

        while (i < n - 1) {
            // Check if arr[i] is a peak
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                // Expand left
                int left = i - 1;
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }

                // Expand right
                int right = i + 1;
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                // Calculate the length of the mountain
                int length = right - left + 1;
                maxLength = max(maxLength, length);

                // Move `i` to the end of this mountain
                i = right;
            } else {
                i++;
            }
        }

        return maxLength;
    }
};

