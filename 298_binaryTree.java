private int max = 0;
public int longestConsecutive(TreeNode root)
{
    if(root == null)
        return 0;
    int curr = 0;
    helper(root, curr, root.val);
    return max;
}

private void helper(TreeNode root, int curr, int val)
{
    if(root == null)
        return;
    if(root.val == val+1)
        curr++;
    else
        curr = 1;
    max = Math.max(curr, max);
    helper(root.left, curr, root.val);
    helper(root.right, curr, root.val);
}