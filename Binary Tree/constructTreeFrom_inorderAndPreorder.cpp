class Solution {
public:

    int findPosition(vector<int>& inorder, int element, int n) {
        for(int i = 0; i < n; i++) {
            if(inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int &index, int inorderStart, int inorderEnd, int n) {

        // Base case
        if(index >= n || inorderStart > inorderEnd) {
            return NULL;
        }

        // Create root
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);

        // Find position in inorder
        int position = findPosition(inorder, element, n);

        // Recursive calls
        root->left = solve(preorder, inorder, index,
                           inorderStart, position - 1, n);

        root->right = solve(preorder, inorder, index,
                            position + 1, inorderEnd, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();
        int index = 0;

        return solve(preorder, inorder, index, 0, n - 1, n);
    }
};