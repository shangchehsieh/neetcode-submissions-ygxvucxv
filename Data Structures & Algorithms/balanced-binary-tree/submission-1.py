# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def height(self, node):
        if node is None:
            return 0
        node_left = self.height(node.left)
        if node_left == -1:
            return -1
        node_right = self.height(node.right)
        if node_right == -1:
            return -1
        if abs(node_left - node_right) > 1:
            return -1

        return 1 + max(node_left, node_right)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.height(root) != -1
        