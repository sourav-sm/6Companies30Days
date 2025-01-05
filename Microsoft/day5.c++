//LEETCODE 638. Shopping Offers
//problem link-https://leetcode.com/problems/shopping-offers/description/

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // Helper function to calculate the cost recursively
        return dfs(price, special, needs);
    }

private:
    // Memoization map to store previously computed results
    unordered_map<string, int> memo;

    // Convert the current needs to a string as a unique key for memoization
    string serialize(const vector<int>& needs) {
        string key;
        for (int need : needs) {
            key += to_string(need) + ",";
        }
        return key;
    }

    // Recursive DFS function to compute the minimum cost
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // Serialize the current needs
        string key = serialize(needs);

        // Check if the result for the current needs is already computed
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Calculate the cost without using any special offers
        int minCost = 0;
        for (int i = 0; i < needs.size(); ++i) {
            minCost += needs[i] * price[i];
        }

        // Try using each special offer
        for (const auto& offer : special) {
            vector<int> newNeeds(needs);
            bool valid = true;

            // Check if the offer can be applied
            for (int i = 0; i < needs.size(); ++i) {
                if (offer[i] > newNeeds[i]) {
                    valid = false;
                    break;
                }
                newNeeds[i] -= offer[i];
            }

            // If the offer is valid, compute the cost with the offer applied
            if (valid) {
                minCost = min(minCost, offer.back() + dfs(price, special, newNeeds));
            }
        }

        // Store the result in the memoization map
        memo[key] = minCost;
        return minCost;
    }
};


//2970. Count the Number of Incremovable Subarrays Iv
//Problem link https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/


class Solution {
public:
    bool isStrictlyIncreasing(const std::vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

    int incremovableSubarrayCount(std::vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Iterate through all possible subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Create a copy of the array without the subarray nums[i..j]
                std::vector<int> remaining;
                for (int k = 0; k < i; k++) {
                    remaining.push_back(nums[k]);
                }
                for (int k = j + 1; k < n; k++) {
                    remaining.push_back(nums[k]);
                }

                // Check if the remaining array is strictly increasing
                if (isStrictlyIncreasing(remaining)) {
                    count++;
                }
            }
        }

        return count;
    }
};


//2976. Minimum Cost to Convert String I
//Problem link https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

class Solution {
public:
    void dijkstra(char &source, unordered_map<char, vector<pair<char, int>>> &adj, vector<vector<long long>> &costMatrix) {

        //min-heap
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

        pq.push({0, source});

        while(!pq.empty()) {
            int d        = pq.top().first;
            char adjNode = pq.top().second;
            pq.pop();

            for(auto &it : adj[adjNode]) {
                char adjNode = it.first;
                int cost      = it.second;

                if(costMatrix[source - 'a'][adjNode - 'a'] > d + cost) {
                    costMatrix[source - 'a'][adjNode - 'a'] = d + cost;
                    pq.push({d + cost, adjNode});
                }
            }

        }
        return;
    }
    //V = # of vertices
    //E = # of edges
    //O(n * (V+E)log(V))
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;

        for(int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<long long>> costMatrix(26, vector<long long>(26, INT_MAX));

        //Populate the costMatrix using Dijkstra's Algorithm
        for(int i = 0; i < source.length(); i++) { //n
            char ch = source[i];
            dijkstra(ch, adj, costMatrix);
        }

        long long ans = 0;

        for(int i = 0; i < source.length(); i++) {
            if(source[i] == target[i]) {
                continue;
            }

            if(costMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }

            ans += costMatrix[source[i] - 'a'][target[i] - 'a'];

        }

        return ans;
    }
};