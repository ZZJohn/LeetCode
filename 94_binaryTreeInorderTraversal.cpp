vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> res;
	TreeNode* pNode = root;
	stack<TreeNode *> node_stack;
	while(pNode || !node_stack.empty())
	{
		if(pNode != NULL)
		{
			node_stack.push(pNode);
			pNode = pNode->left;
		}
		else
		{
			pNode = node_stack.top();
			node_stack.pop();
			res.push_back(pNode->val);
			pNode = pNode->right;
		}
	}
	return res;
}