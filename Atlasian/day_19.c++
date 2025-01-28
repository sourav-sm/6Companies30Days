// 1385. Find the Distance Value Between Two Arrays
// problem link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
class Solution {
public: 
    bool check(int a,int b,int d){
        if(abs(a-b)<=d)return true;
        else return false;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<arr2.size();j++){
                if(check(arr1[i],arr2[j],d)){
                    count++;
                    break;
                }
            }
        }
        return arr1.size()-count;
    }
};

/********************************************************************************************************************************************************************************************/

//1969. Minimum Non-Zero Product of the Array Elements
//problem link: https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int minNonZeroProduct(int p) {
        if (p == 1) return 1; // Base case for smallest range.

        long long maxNum = (1LL << p) - 1; // Maximum number in the range [1, 2^p - 1].
        long long secondMax = maxNum - 1; // Second maximum number.

        // Total count of secondMax elements to multiply.
        long long count = (maxNum / 2) % (mod - 1); // Using Fermat's Little Theorem for mod.

        long long result = (modPow(secondMax % mod, count, mod) * (maxNum % mod)) % mod;
        return (int)result;
    }
};

/*********************************************************************************************************************** */
// 1838. Frequency of the Most Frequent Element
// problem link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int i=0,maxLen=0;

        for(int j=0;j<nums.size();j++){
            mpp[nums[j]]++;

            //ensure the subarray is good 
            while(mpp[nums[j]]>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            maxLen=max(maxLen,j-i+1);
        }
        return maxLen;
    }
};

/**************************************************************************************************************************************** */

