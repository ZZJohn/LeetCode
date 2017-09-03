bool isSymmetric(TreeNode* root)
{
	if(root == NULL)
		return true;
	else
		return helper(root->left, root->right);
}

bool helper(TreeNode* t1, TreeNode* t2)
{
	if(t1==NULL && t2==NULL)
		return true;
	if(t1!=NULL && t2==NULL)
		return false;
	if(t1==NULL && t2!=NULL)
		return false;
	else
	{
		if(t1->val == t2->val)
			return helper(t1->left, t2->right) && helper(t1->right, t2->left);
		else
			return false;
	}
}