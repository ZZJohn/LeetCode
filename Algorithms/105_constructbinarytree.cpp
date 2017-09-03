TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	return build(preorder, inorder, 0, 0, inorder.size()-1);
}

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prestart, int instart, int inend)
{
	if(prestart>preorder.size()-1 || instart>inend)
		return NULL;
	TreeNode* root = new TreeNode(preorder[prestart]);
	int index = -1;
	for(int i=instart; i<=inend; i++)
	{
		if(inorder[i] == preorder[prestart])
		{
			index = i;
			break;
		}
	}
	root->left = build(preorder, inorder, prestart+1, instart, index-1);
	root->right = build(preorder, inorder, prestart+index-instart+1, index+1, inend);
	return root;
}