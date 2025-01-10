//168. Excel Sheet Column Title
//problem link https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";

        while(columnNumber){
            columnNumber--;//to match ascaii value
            int rem=columnNumber%26;
            char ch=rem+'A';
            ans.push_back(ch);
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//GFG Nuts and Bolts Problem
//https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/0

class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
       string order="!#$%&*?@^";
       
       unordered_map<char,int>mpp;
       for(int i=0;i<order.length();i++){
        mpp[order[i]]=i;
       }

       auto comparater[&mpp](char a,char b){
            return mpp[a]<mpp[b];
       };

       sort(nuts,nuts+n,comparater);
       sort(bolts,bolts+n,comparater);
    }
}

// 297. Serialize and Deserialize Binary Tree
//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        string s ="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
           TreeNode* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->val)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }
};