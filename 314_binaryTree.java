public List<List<Integer>> verticalOrder(TreeNode root)
{
	List<List<Integer>> res = new ArrayList<>();
	if(root == null)
		return res;
	Map<Integer, List<Integer>> map = new HashMap<>();
	Queue<TreeNode> q = new LinkedList<>();
	Queue<Integer> values = new LinkedList<>();
	q.add(root);
	values.add(0);
	int min=0, max=0;
	while(!q.isEmpty())
	{
		TreeNode node = q.poll();
		int value = values.poll();
		if(!map.containsKey(value))
			map.put(value, new ArrayList<Integer>());
		map.get(value).add(node.val);
		if(node.left!=null)
		{
			q.add(node.left);
			values.add(value-1);
			if(value <= min) min = value-1;
		}
		if(node.right!=null)
		{
			q.add(node.right);
			values.add(value+1);
			if(value >= max) max = value+1;
		}
	}
	for(int i=min; i<=max; i++)
		res.add(map.get(i));
	return res;
}