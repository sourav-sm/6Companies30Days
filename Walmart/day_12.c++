//532. K-diff Pairs in an Array
//problem link https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;
    unordered_map<int, int> m;
    for (int n : nums) m[n]++;
    int cnt = 0;
    for (auto p : m) {
      if ((!k && p.second > 1)
        || (k && m.count(p.first + k))) ++cnt;
    }
    return cnt;
  }
};

/******************************* */
//2572. Count the Number of Square-Free Subsets
//problem link https://leetcode.com/problems/count-the-number-of-square-free-subsets/

#define ll long long
class Solution {
public:
    int memo[1001][1024];
    vector<int>vec={2,3,5,7,11,13,17,19,23,29};
    ll mod=1e9+7;
    ll dp(vector<int>&nums,int i,int mask)
    {
        if(i==nums.size()) return 1;
        if(memo[i][mask]!=-1) return memo[i][mask];
        int temp=mask,flag=1;
        for(int j=0;j<10;j++)
        {
            int num=nums[i],count=0;
            while(num%vec[j]==0)  num/=vec[j], count++;
            if(count>=2 or ((count==1) and ((mask>>j)&1)))
            {
                flag=0;
                break;
            }
            if(count) temp=temp|(1<<j);
        }
        if(flag)
               return memo[i][mask]=(dp(nums,i+1,mask)+dp(nums,i+1,temp))%mod;
        else
              return memo[i][mask]=dp(nums,i+1,mask);
        
    }
    
    int squareFreeSubsets(vector<int>& nums) 
    {
        memset(memo,-1,sizeof(memo));
        return 1LL*(dp(nums,0,0)-1+mod)%mod;  
    }
};

/***************************************************************** */
//396. Rotate Function
//peoblem link https://leetcode.com/problems/rotate-function/description/

#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int maxRotateFunction(std::vector<int>& nums) {
        int n = nums.size();
        long long sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long F = 0;

        // Calculate initial F(0)
        for (int i = 0; i < n; ++i) {
            F += i * nums[i];
        }

        long long maxF = F;

        // Calculate F(k) iteratively for k = 1 to n - 1
        for (int k = 1; k < n; ++k) {
            // F(k) = F(k-1) + sum - n * nums[n-k]
            F = F + sum - n * nums[n - k];
            maxF = std::max(maxF, F);
        }

        return maxF;
    }
};

