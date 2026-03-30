# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
       
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.sum_edge = 0

        def height(node):
            if node is None: 
                return 0
            
            node_left = height(node.left)
            node_right = height(node.right)
            self.sum_edge = max(self.sum_edge, node_left + node_right)

            return 1 + max(node_left, node_right)
        
        height(root)
        return self.sum_edge
        



        

        