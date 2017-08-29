int maxDepth(TreeNode* root)
{
	int maxlevel = 0;
	if(root == NULL)
		return maxlevel;
	maxlevel++;
	int level = maxlevel;
	helper(root, level, maxlevel);
	return maxlevel;
}

void helper(TreeNode* root, int level, int& maxlevel)
{
	if(root == NULL)
		return;
	if(level > maxlevel)
		maxlevel = level;
	if(root->left)
		helper(root->left, level+1, maxlevel);
	if(root->right)
		helper(root->right, level+1, maxlevel);
}