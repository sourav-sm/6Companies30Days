// 2126. Destroying Asteroids
// problem linkhttps://leetcode.com/problems/destroying-asteroids/description/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // Sort the asteroids in ascending order to process the smallest asteroid first
        sort(asteroids.begin(), asteroids.end());
        
        // Initialize the planet's mass as a long long to avoid overflow
        long long currentMass = mass;
        
        for (int asteroid : asteroids) {
            // If the current mass of the planet is less than the asteroid's mass, the planet is destroyed
            if (currentMass < asteroid) {
                return false;
            }
            // Otherwise, the planet absorbs the asteroid
            currentMass += asteroid;
        }
        
        // If all asteroids are processed, return true
        return true;
    }
};

/*************************************************************************** -----------------------------------------------***** */

// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
//problem link https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

// CODE--
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize distances based on edges
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        // Distance to itself is 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Floyd-Warshall algorithm to find shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int cntCity = INT_MAX, cityNo = -1;

        // Find the city with the smallest number of reachable cities within the distance threshold
        for (int city = 0; city < n; city++) {
            int count = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                if (dist[city][adjCity] <= distanceThreshold) {
                    count++;
                }
            }
            // Update if a smaller count is found, or if counts are the same, choose the city with the larger number
            if (count < cntCity || (count == cntCity && city > cityNo)) {
                cntCity = count;
                cityNo = city;
            }
        }

        return cityNo;
    }
};

/*************************************************************************** -----------------------------------------------***** */

//273. Integer to English Words
//problem link-https://leetcode.com/problems/integer-to-english-words/description/

// CODE--
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        string result;
        
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000) + thousands[i] + " " + result;
            }
            num /= 1000;
            i++;
        }
        
        while (result.back() == ' ') result.pop_back();  // Remove trailing spaces
        return result;
    }
    
private:
    vector<string> lessThan20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return lessThan20[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
        else return lessThan20[num / 100] + " Hundred " + helper(num % 100);
    }
};

/*************************************************************************** -----------------------------------------------***** */

//187. Repeated DNA Sequences
//problem link https://leetcode.com/problems/repeated-dna-sequences/description/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> substringCount; // Map to store counts of 10-letter substrings
        vector<string> result; // Vector to store the result
        int n = s.size();
        
        // Iterate through the string and extract all 10-letter substrings
        for (int i = 0; i <= n - 10; ++i) {
            string substring = s.substr(i, 10); // Extract a 10-letter substring
            substringCount[substring]++; // Increment its count
        }
        
        // Find substrings that occur more than once
        for (const auto& entry : substringCount) {
            if (entry.second > 1) {
                result.push_back(entry.first); // Add substring to the result
            }
        }
        
        return result;
    }
};
