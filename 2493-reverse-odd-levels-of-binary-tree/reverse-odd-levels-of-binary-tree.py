class Solution:
  def reverseOddLevels(self, root: TreeNode | None) -> TreeNode | None:
    def dfs(left: TreeNode | None, right: TreeNode | None, level: int) -> None:
      if not left:
        return
      if level % 2 == 1:  # Check if it's an odd level
        left.val, right.val = right.val, left.val
      dfs(left.left, right.right, level + 1)
      dfs(left.right, right.left, level + 1)
    
    if not root:
      return None
    dfs(root.left, root.right, 1)
    return root