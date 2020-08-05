/**
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 第一次超时 -> 减少函数调用次数 -> 记忆化搜索
class Solution{
    // mp[root].first:  not rob root -> val
    // mp[root].second: rob root -> val
    unordered_map <TreeNode*, pair<int, int>> mp;
    int rob(TreeNode *root) {
        if (root == nullptr) {
            mp[root].first = 0; mp[root].second = 0;
            return 0;
        }
        if (mp.count(root)) {
            return max(mp[root].first, mp[root].second);
        } else {
            // not rob now
            mp[root].first = rob(root -> left) + rob(root -> right);
            // rob now
            int sum = 0;
            if (root -> left != nullptr)
                sum += rob(root -> left -> left) + rob(root -> left -> right);
            if (root -> right != nullptr)
                sum += rob(root -> right -> left) + rob(root -> right -> right);
            mp[root].second = sum + root -> val;
        }
        return max(mp[root].first, mp[root].second);
    }
};
