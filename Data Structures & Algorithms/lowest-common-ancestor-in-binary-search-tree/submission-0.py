# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        #BST: 左邊小、右邊大
        if root is None:
            return 0
        
        n1 = min(p.val,q.val)
        n2 = max(p.val,q.val)

        while root:
            if root.val > n2:
                root = root.left
            elif root.val < n1:
                root = root.right
            else:
                return root

