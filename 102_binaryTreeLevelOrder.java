public List<List<Integer>> levelOrder(TreeNode root)
{
	List<List<Integer>> res = new ArrayList<>();
	if(root == null)
		return res;
	Queue<TreeNode> q = new LinkedList<>();
	q.offer(root);
	while(!q.isEmpty())
	{
		int n = q.size();
		List<Integer> tmp = new ArrayList<>();
		for(int i=0; i<=n-1; i++)
		{
			TreeNode node = q.poll();
			tmp.add(node.val);
			if(node.left != null)
				q.offer(node.left);
			if(node.right != null)
				q.offer(node.right);
		}
		res.add(tmp);
	}
	return res;
}