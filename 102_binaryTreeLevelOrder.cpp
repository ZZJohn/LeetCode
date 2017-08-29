vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> res;
	if(root == NULL)
		return res;
	queue<TreeNode*> q;
	vector<int> path;
	q.push(root);
	int n = q.size();
	while(!q.empty())
	{
		n = q.size();
		while(n>0)
		{
			TreeNode* node = q.front();
			q.pop();
			path.push_back(node->val);
			if(node->left != NULL)
				q.push(node->left);
			if(node->right != NULL)
				q.push(node->right);
			n--;
		}
		res.push_back(path);
		path.clear();
	}
	return res;
}