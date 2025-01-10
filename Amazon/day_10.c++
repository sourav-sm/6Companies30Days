
//994. Rotting Oranges
//https://leetcode.com/problems/rotting-oranges/description/

class Solution{
    public:
        int  orangesRotting(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            queue<pair<int,int>>q;
            int time=0,freshcount=0;

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==2){
                        q.push({i,j});
                    }else if(grid[i][j]==1){
                        freshcount++;
                    }
                }
            }

           // Directions array for 4-directional movement
           vector<pair<int,int>>directions={{-1,0},{1,0},{0,-1},{0,1}};

           while(!q.empty() && freshcount>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto[x,y]=q.front();
                q.pop();

                for(auto[dx,dy]:directions){
                    int nx=x+dy;
                    int ny=x+dy;

                    if(nx>=0 && ny>=0 && nx<=m && ny<=n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        freshcount++;
                    }
                }
            }
            time++;
           }   
           if(freshcount>0 ? -1 : time);
        }
};

//GFG : Delete N nodes after M nodes of a linked list
//https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
       Node* curr=head;
       while(curr){
        //skip 1st m node
        for(int i=1;i<m && curr!=nullptr;i++){
            curr=curr->next;
        }

        if(!curr)break;

        Node* temp=curr->next;
        //delete n nodes
        for(int i=0;i<n && temp!=nullptr ; i++){
            Node* todelete=temp;
            temp=temp->next;
            delete todelete;
        }
        curr->next=temp;
        temp=curr;
       }
       return head;
    }
};

//2385. Amount of Time for Binary Tree to Be Infected
//https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

class Solution {
public:
    int result=INT_MIN;

    int solve(TreeNode* root,int start){
        if(root==NULL)return 0;

        int LH=solve(root->left,start);
        int RH=solve(root->right,start);

        if(root->val==start){
            result=max(LH,RH);
            return -1;
        }else if(LH>=0 && RH>=0){
            return max(LH,RH)+1;
        }else{
            int d=abs(LH)+abs(RH);
            result=max(result,d);

            return min(LH,RH)-1;
        }  
        return 0;
    }

    int amountOfTime(TreeNode* root, int start) {
       solve(root,start);
       return result;
    }
}