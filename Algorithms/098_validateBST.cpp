vector<int> inorder;
void inOrder(TreeNode* root)
{
	if(root->left!=NULL) inOrder(root->left);
	inorder.push_back(root->val);
	if(root->right!=NULL) inOrder(root->right);
}

bool isValidBST(TreeNode* root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL)) return 1;
	inOrder(root);
	for(int i=1; i<inorder.size(); i++)
	{
		if(inorder[i] <= inorder[i-1]) return 0;
	}
	return 1;
}