//1208. Get Equal Substrings Within Budget
//problem link https://leetcode.com/problems/get-equal-substrings-within-budget/description/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        
        int maxLen = 0;
        int currCost = 0;
        
        int i = 0, j = 0;
        while(j < n) {
            currCost += abs(s[j] - t[j]);
            
            while (currCost > maxCost) {
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        
        return maxLen;
    }
};

/********************************************************** */
//825. Friends Of Appropriate Ages
//problem link-https://leetcode.com/problems/friends-of-appropriate-ages/description/

#include <vector>
#include <algorithm>

class Solution {
public:
    int numFriendRequests(std::vector<int>& ages) {
        std::sort(ages.begin(), ages.end()); // Sort ages
        int n = ages.size();
        int totalRequests = 0;

        for (int i = 0; i < n; ++i) {
            if (ages[i] <= 14) continue; // Skip ages that can't send any requests

            // Find the minimum valid age[y]
            int minAge = 0.5 * ages[i] + 7;

            // Use two pointers to count valid friend requests
            int left = std::lower_bound(ages.begin(), ages.end(), minAge + 1) - ages.begin();
            int right = std::upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin();

            totalRequests += (right - left - 1); // Exclude self
        }

        return totalRequests;
    }
};

/********************************************** */
//718. Maximum Length of Repeated Subarray
//problem linkhttps://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size();
       int n = nums2.size();
        int maxCount=0;
        for(int i=-n+1;i<m;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i+j<0)
                {
                    continue;
                }
                else if(i+j>=m)
                {
                   break; 
                }
                else if(nums1[i+j]==nums2[j])
                {
                   count++;;
                    maxCount = max(maxCount,count);
                }
                else
                {
                    count =0;
                }
            }
        }
        return maxCount;
    }
};