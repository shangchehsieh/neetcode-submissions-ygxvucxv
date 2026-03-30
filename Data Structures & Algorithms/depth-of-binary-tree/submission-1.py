# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def maxDepth(self, root: Optional[TreeNode]) -> int:

        if root is None: #空樹高度為0
            return 0
        
        #遞迴計算left subtree -> 從leaf慢慢往上層計算
        node_left = self.maxDepth(root.left)
        # if node_left == -1: #subtree not balance
        #     return -1
        #遞迴計算right subtree -> 從leaf慢慢往上層計算
        node_right = self.maxDepth(root.right)
        # if node_right == -1: #subtree not balance
        #     return -1
        # if abs(node_left - node_right) > 1:
        #     return -1 #左右高度差 > 1 not balance

        #balance, return  1 (當前節點) + 左右子樹中較高的那一邊
        return 1 + max(node_left, node_right)