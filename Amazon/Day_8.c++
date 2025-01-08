//Problem Statement 387. First Unique Character in a String
//problem Link https://leetcode.com/problems/first-unique-character-in-a-string/description/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mpp;

        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }

        for(int i=0;i<s.length();i++){
            if(mpp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};

//36. Valid Sudoku
//problem link https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool validBox(int sr,int er,int sc,int ec,vector<vector<char>>& board){
        unordered_set<char>st;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                if(board[i][j]=='.')continue;
                if(st.find(board[i][j])!=st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
     //row check
     for(int i=0;i<9;i++){
        unordered_set<char>st;
        for(int j=0;j<9;j++){
            if(board[i][j]=='.')continue;
            if(st.find(board[i][j])!=st.end()){
                return false;
            }
            st.insert(board[i][j]);
        }
     }
     //col check
     for(int j=0;j<9;j++){
        unordered_set<char>st;
        for(int i=0;i<9;i++){
            if(board[i][j]=='.')continue;
            if(st.find(board[i][j])!=st.end()){
                return false;
            }
            st.insert(board[i][j]);
        }
     }   
     //grid check
     for(int sr=0;sr<9;sr+=3){
        for(int sc=0;sc<9;sc+=3){
            if(!validBox(sr,sr+2,sc,sc+2,board))return false;
        }
     }
     return true;
    }
};