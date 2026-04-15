/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void helper(struct TreeNode* node, int* res, int* index){
    if(node != NULL){
        helper(node->left,res,index);
        res[*index] = node->val;
        *index = *index + 1;
        helper(node->right,res,index);
    }

}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    int* res = malloc(100 * sizeof(int)); // 先假設最多100個節點
    int index = 0;
        
    helper(root , res, &index);
    *returnSize = index ;
    return res;
    
    free(res);

}