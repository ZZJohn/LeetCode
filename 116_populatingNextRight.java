public void connect(TreeLinkNode root) 
{
    if(root==null) return;
    TreeLinkNode tmp = root;
    TreeLinkNode curr = null;
    while(tmp.left != null)
    {
        curr = tmp;
        while(curr != null)
        {
            curr.left.next = curr.right;
            if(curr.next != null)
                curr.right.next = curr.next.left;
            curr = curr.next;
        }
        tmp = tmp.left;
    }
}