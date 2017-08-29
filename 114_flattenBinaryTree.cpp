void flatten(TreeNode* root)
{
	TreeNode* pre = NULL;
	helper(root, pre);
}

void helper(TreeNode* node, TreeNode* &pre)
{
	if(node == NULL)
		return;
	TreeNode* left = node->left;
	TreeNode* right = node->right;
	if(pre != NULL)
	{
		pre->right = node;
		pre->left = NULL;
	}
	pre = node;
	if(left)
		flatten(left, pre);
	if(right)
		flatten(right, pre);
}