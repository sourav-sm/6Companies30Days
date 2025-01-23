// 455. Assign Cookies
// problem link: https://leetcode.com/problems/assign-cookies/

class Solution { 
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size();
        int n=s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int i=0,j=0;
        while(i<m && j<n){
           if(g[i]<=s[j]){
               i++;//statisfied cookie
           }
           j++;//if not statisfied
        }
        return i;
    }
};

//703. Kth Largest Element in a Stream
//problem link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
 int K;
  priority_queue<int,vector<int>,greater<int>>pq;//min_heap
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto& it:nums){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }

    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }
        return pq.top();
    }
};
