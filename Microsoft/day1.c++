// Problem Statement: 1401. Circle and Rectangle Overlapping
// SOLUTION-------------------------------------------------------------------
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xNearest=max(x1,min(xCenter,x2));
        int yNearest=max(y1,min(yCenter,y2));

        int disX=(xCenter-xNearest);
        int disY=(yCenter-yNearest);

        int disSquare=(disX*disX+disY*disY);
        if(disSquare>radius*radius){
            return false;
        }
        return true;
    }
};


// Problem Statement: 1823. Find the Winner of the Circular Game
// SOLUTION-------------------------------------------------------------------
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }

        while(q.size()>1){
            for(int j=1;j<=k-1;j++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};

//354. Russian Doll Envelopes
//SOLUTION-------------------------------------------------------------------
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        
        vector<int>heights;
        for(const auto& en:envelopes){
            heights.push_back(en[1]);
        }

        vector<int>dp;
        for(int h:heights){
            auto it=lower_bound(dp.begin(),dp.end(),h);
            if(it==dp.end()){
                dp.push_back(h);
            }else{
                *it=h;
            }
        }
        return dp.size();
    }
};
