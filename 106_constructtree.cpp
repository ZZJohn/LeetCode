TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	return build(inorder, postorder, postorder.size()-1, 0, inorder.size()-1);
}

TreeNode* build(vector<int>& inorder, vector<int>& postorder, int postend, int instart, int inend)
{
	if(postend<0 || instart>inend)
		return NULL;
	TreeNode* root = new TreeNode(postorder[postend]);
	int index = -1;
	for(int i=instart; i<=inend; i++)
	{
		if(inorder[i] == postorder[postend])
		{
			index = i;
			break;
		}
	}
	root->left = build(inorder, postorder, postend-inend+index-1, instart, index-1);
	root->right = build(inorder, postorder, postend-1, index+1, inend);
	return root;
}