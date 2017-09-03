vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> res;
	vector<int> path;
	helper(root, sum, path, res);
	return res;
}

void helper(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res)
{
	if(root == NULL)
		return;
	path.push_back(root->val);
	if(root->left == NULL && root->right == NULL)
	{
		if(root->val == sum)
			res.push_back(path);
		path.pop_back();
		return;
	}
	helper(root->left, sum-root->val, path, res);
	helper(root->right, sum-root->val, path, res);
	path.pop_back();
}