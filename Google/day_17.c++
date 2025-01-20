//1686. Stone Game VI
//https://leetcode.com/problems/stone-game-vi/description/
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        
        // Create a list of indices sorted by combined value (aliceValues[i] + bobValues[i])
        vector<pair<int, int>> stones;
        for (int i = 0; i < n; ++i) {
            stones.push_back({aliceValues[i] + bobValues[i], i});
        }
        
        // Sort stones by combined value in descending order
        sort(stones.rbegin(), stones.rend());
        
        int aliceScore = 0, bobScore = 0;
        
        // Alternate turns picking stones
        for (int turn = 0; turn < n; ++turn) {
            int index = stones[turn].second;
            if (turn % 2 == 0) { // Alice's turn
                aliceScore += aliceValues[index];
            } else { // Bob's turn
                bobScore += bobValues[index];
            }
        }
        
        // Determine the winner
        if (aliceScore > bobScore) return 1;
        if (bobScore > aliceScore) return -1;
        return 0;
    }
};



// 23. Merge k Sorted Lists
//https://leetcode.com/problems/merge-k-sorted-lists/description/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap based on node value
        };

        // Priority queue to hold the heads of the linked lists
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        // Push the head of each linked list into the min-heap
        for (auto list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        // Dummy node to act as the start of the merged linked list
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        // Extract the smallest element from the heap and advance the pointer
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Add the smallest node to the merged list
            current->next = smallest;
            current = current->next;

            // If the smallest node has a next node, push it into the heap
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        return dummy->next; // Return the merged list, skipping the dummy node
    }
};


//2233. Maximum Product After K Increments
//problem link https://leetcode.com/problems/maximum-product-after-k-increments/description/

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const long long MOD=1e9+7;

        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num:nums){
            pq.push(num);
        }

        for(int i=0;i<k;i++){
            int minele=pq.top();
            pq.pop();
            minele++;
            pq.push(minele);
        }

        long long ans=1;
        while(!pq.empty()){
            ans=(ans*pq.top())%MOD;
            pq.pop();
        }
        return ans;
    }
};