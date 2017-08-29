public List<List<Integer>> generate(int numRows) {
	List<List<Integer>> res = new ArrayList<List<Integer>>();
	List<Integer> tmp = new ArrayList<Integer>();
	for(int i=1; i<=numRows; i++) {
		tmp.add(0, 1);
		for(int j=1; j<=tmp.size()-2; j++)
			tmp.set(j, tmp.get(j)+tmp.get(j+1));
		res.add(new ArrayList<Integer>(tmp));
	}
	return res;
}