//299. Bulls and Cows
//PROBLEM STATEMENT: https://leetcode.com/problems/bulls-and-cows/description/

//SOLUTION-------------------------------------------------------------------
class Solution {
public:
    string getHint(string secret, string guess) {
       int n=secret.length();
       int x=0;//bulls
       int y=0;//cows

        vector<int>secretCount(10,0);
        vector<int>guessCount(10,0);
       string ans="";
       //count bulls
       for(int i=0;i<n;i++){
        if(secret[i]==guess[i]){
            x++;
        }else{
            secretCount[secret[i]-'0']++;
            guessCount[guess[i]-'0']++;
        }
       }
       
       //count cows
       for(int i=0;i<10;i++){
        y+=min(secretCount[i],guessCount[i]);
       }

       ans=to_string(x)+"A"+to_string(y)+"B";
       return ans; 
    }
};

//462. Minimum Moves to Equal Array Elements II
//PROBLEM STATEMENT: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int n=nums.size();
       int mid=nums[n/2];//here we should take median not the avg ,i.e nums[0]+nums[n-1]/2;

       int count=0;
       for(int i=0;i<n;i++){
        count+=abs(mid-nums[i]);
       }

       return count;   
    }
};

// 497. Random Point in Non-overlapping Rectangles
//PROBLEM STATEMENT: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
class Solution {
    int num_pts;
    vector<int> rect_cum_count;
    vector<vector<int>> rects;
public:
    Solution(vector<vector<int>>& rects) {
        num_pts = 0;
        this->rects = rects;
        for(vector<int>& rect: rects){
            num_pts += (rect[2] - rect[0] + 1)*(rect[3] - rect[1] + 1);
            rect_cum_count.push_back(num_pts);
        }
    }
    
    vector<int> pick() {
        int pt_idx = rand() % num_pts;
        int l = 0, r = rects.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(rect_cum_count[mid] <= pt_idx) l = mid+1;
            else r = mid;
        }
        // l = rectangle index
        vector<int>& rect = rects[l];
        int x_pts = rect[2] - rect[0] + 1;
        int y_pts = rect[3] - rect[1] + 1;
        int pts_in_rect = x_pts*y_pts;
        int pt_start = rect_cum_count[l] - pts_in_rect;
        int offset = pt_idx - pt_start;
        return {rect[0] + offset%x_pts, rect[1] + offset/x_pts};
    }
};