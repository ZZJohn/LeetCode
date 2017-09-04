vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> res;
	if(root == NULL)
		return res;
	vector<int> path;
	int level = 1;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		int n = q.size();
		while(n-- > 0)
		{
			TreeNode* node = q.front();
			q.pop();
			path.push_back(node->val);
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
		if(level%2 == 0)
			reverse(path.begin(), path.end());
		res.push_back(path);
		path.clear();
		level++;
	}
	return res;
}