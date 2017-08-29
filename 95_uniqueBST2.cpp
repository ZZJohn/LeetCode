vector<TreeNode *> generateTrees(int n)
{
	vector<TreeNode *> res;
	if(n==0) return res;
	else return generateTrees1(1, n);
}

vector<TreeNode *> generateTrees1(int begin, int end)
{
	vector<TreeNode *> res;
	if(begin > end)
		res.push_back(NULL);
	else if(begin == end)
	{
		TreeNode* node = new TreeNode(begin);
		res.push_back(node);
	}
	else
	{
		for(int i = begin; i <= end; i++)
		{
			vector<TreeNode *> tleft = generateTrees1(begin, i-1);
			vector<TreeNode *> tright = generateTrees1(i+1, end);
			for(int l = 0; l < tleft.size(); l++)
			{
				for(int r = 0; r < tright.size(); r++)
				{
					TreeNode* root = new TreeNode(i);
					root->left = tleft[l];
					root->right = tright[r];
					res.push_back(root);
				}
			}
		}
	}
	return res;
}