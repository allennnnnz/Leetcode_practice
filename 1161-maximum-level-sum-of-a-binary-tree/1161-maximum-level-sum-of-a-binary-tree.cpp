/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        std::queue<TreeNode*> BFS_queue;
        BFS_queue.push(root);
        int max = root->val;
        int max_level = 1;
        int cur_level = 1;
        while(!BFS_queue.empty()){
            int levelnum_node = BFS_queue.size();
            int next_lelvel_sum = 0;
            bool no_child = true;
            for(int i=0 ; i< levelnum_node;i++){
                TreeNode* cur_node = BFS_queue.front();
                BFS_queue.pop();
                TreeNode* left_node = cur_node -> left;
                TreeNode* right_node = cur_node -> right; 
                if(left_node){
                    BFS_queue.push(left_node);
                    next_lelvel_sum += left_node -> val;
                    no_child = false;
                }
                if(right_node){
                    BFS_queue.push(right_node);
                    next_lelvel_sum += right_node -> val;
                    no_child = false;
                }
            }

            cur_level += 1;
            cout<< next_lelvel_sum << endl;

            if(!no_child){
                if(max < next_lelvel_sum){
                    max = next_lelvel_sum;
                    max_level = cur_level;
                }
            }
            
        
            
        }
        return max_level;
    }
};