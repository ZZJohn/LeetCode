vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> res;
	if(root == NULL) return res;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		vector<int> element;
		int n = q.size();
		for(int i=0; i<=n-1; i++)
		{
			TreeNode* tmp = q.front();
			q.pop();
			if(tmp->left != NULL)
				q.push(tmp->left);
			if(tmp->right != NULL)
				q.push(tmp->right);
			element.push_back(tmp->val);
		}
		res.push_back(element);
	}
	reverse(res.begin(), res.end());
	return res;
}