//2002. Maximum Product of the Length of Two Palindromic Subsequences
//problem link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }

    int maxProduct(string s) {
        int n = s.size();
        int maxProd = 0;

        // Generate all subsets of indices using bitmasking
        for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
            string subseq1;

            // Build the first subsequence
            for (int i = 0; i < n; ++i) {
                if (mask1 & (1 << i)) {
                    subseq1 += s[i];
                }
            }

            // Check if the first subsequence is a palindrome
            if (!isPalindrome(subseq1)) continue;

            // Generate complementary subsequences
            for (int mask2 = 0; mask2 < (1 << n); ++mask2) {
                if (mask1 & mask2) continue; // Ensure disjoint subsequences

                string subseq2;
                for (int i = 0; i < n; ++i) {
                    if (mask2 & (1 << i)) {
                        subseq2 += s[i];
                    }
                }

                if (isPalindrome(subseq2)) {
                    int product = subseq1.size() * subseq2.size();
                    maxProd = max(maxProd, product);
                }
            }
        }

        return maxProd;
    }
};

//324. Wiggle Sort II
//problem link: https://leetcode.com/problems/wiggle-sort-ii/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);
        //step 1:sort it
        sort(nums.begin(),nums.end());
        //step 2:reorder it
        int i=1,j=n-1;
        while(i<n){
            temp[i]=nums[j];
            i+=2;
            j--;
        }
        i=0;
        while(i<n){
            temp[i]=nums[j];
            i+=2;
            j--;
        }

        //step 3:fill in actual array nums
        for(int i=0;i<n;i++){
            nums[i]=temp[i];
        }
    }
};
