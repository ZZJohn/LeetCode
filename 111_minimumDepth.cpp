int minDepth(TreeNode* root)
{
	if(root == NULL)
		return 0;
	int l = minDepth(root->left);
	int r = minDepth(root->right);
	if(!l)
		return r+1;
	if(!r)
		return l+1;
	return min(l, r)+1;
}
