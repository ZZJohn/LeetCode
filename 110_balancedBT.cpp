bool isBalanced(TreeNode* root)
{
	return helper(root)!=-1;
}

int helper(TreeNode* root)
{
	if(root == NULL)
		return 0;
	int l = helper(root->left);
	int r = helper(root->right);
	if(l<0 || r<0 || abs(l-r)>1) return -1;
	return max(l, r)+1;
}