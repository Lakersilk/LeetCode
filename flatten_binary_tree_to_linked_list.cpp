/**
 * Definition for a binary tree node.
 * struct TreeNode{
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *       
 * };
 * Solution: 先序遍历转化为非递归，使用栈的思想，记录前一节点，转化为单链表时将左子树置空。
 */

class Solution {
    void flatten(TreeNode *root) {
        if (root == nullptr) return ;
        stack <TreeNode *> st;
        if (root -> right != nullptr) st.push(root -> right);
        if (root -> left != nullptr) st.push(root -> left);
        TreeNode *pre = root, *p;
        while (!st.empty()) {
            p = st.top(); st.pop();
            pre -> left = nullptr; pre -> right = p;
            if (p -> right != nullptr) st.push(p -> right);
            if (p -> left != nullptr) st.push(p -> left);
            pre = p;
        }
        return ;
    }
};
