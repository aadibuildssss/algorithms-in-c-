int height(node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

pair<int,int> diameterFast(node* root){
    // returns {diameter_in_nodes, height_in_nodes}
    if(root == NULL){
        return make_pair(0, 0);
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int leftDiameter  = left.first;
    int rightDiameter = right.first;
    int leftHeight    = left.second;
    int rightHeight   = right.second;

    // diameter passing through current root (in nodes)
    int throughRoot = leftHeight + rightHeight;

    int bestDiameter = max(leftDiameter, max(rightDiameter, throughRoot));
    int heightHere   = max(leftHeight, rightHeight) + 1;

    return make_pair(bestDiameter, heightHere);
}
