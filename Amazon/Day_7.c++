//problem Statement Phone directory
//problem link https://www.geeksforgeeks.org/problems/phone-directory4628/1

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // Use a set to store unique contacts in sorted order
        set<string> uniqueContacts(contact, contact + n);
        vector<vector<string>> result;
        string prefix = "";

        // Iterate through each character in the query string `s`
        for (char c : s) {
            prefix += c; // Build the current prefix
            vector<string> matchedContacts;

            // Search for contacts matching the current prefix
            for (const string& entry : uniqueContacts) {
                if (entry.substr(0, prefix.size()) == prefix) {
                    matchedContacts.push_back(entry);
                }
            }

            // If no matches are found, add "0" to the result
            if (matchedContacts.empty()) {
                result.push_back({"0"});
            } else {
                result.push_back(matchedContacts);
            }
        }

        return result;
    }
};

//Brackets in Matrix Chain Multiplication
//Problem link https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

class Solution {
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<string>> brackets(n, vector<string>(n, ""));

        // Initialize single matrices
        for (int i = 1; i < n; i++) {
            brackets[i][i] = string(1, 'A' + i - 1); // Matrix names A, B, C...
        }

        // Length of the chain
        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        brackets[i][j] = "(" + brackets[i][k] + brackets[k + 1][j] + ")";
                    }
                }
            }
        }

        return brackets[1][n - 1];
    }
};


//Problem Statement K Sized Subarray Maximum
//problem link https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result; // To store the maximum of each subarray
        deque<int> dq; // To store indices of elements in the current window

        for (int i = 0; i < arr.size(); i++) {
            // Remove indices of elements not in the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove indices of smaller elements from the back
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // Add the maximum of the current window to the result
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};