public List<List<Integer>> combinationSum3(int k, int n) 
{
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> path = new ArrayList<>();
    helper(res, path, 1, k, n);
    return res;
}

public void helper(List<List<Integer>> res, List<Integer> path, int start, int k, int n)
{
    if(path.size()==k && n==0)
    {
        res.add(new ArrayList<Integer>(path));
        return;
    }
    if(path.size()==k && n!=0)
        return;
    for(int i=start; i<=9; i++)
    {
        path.add(i);
        helper(res, path, i+1, k, n-i);
        path.remove(path.size()-1);
    }
}