# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    #100. Same Tree
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        if p is None and q is None:  #都是None
            return True
        if p is None or q is None: #其中一個是None
            return False
        if p.val != q.val: #都不是None → 比較val
            return False
        #val也沒有不一樣 → val相同!
        return self.isSameTree(p.left,q.left) and self.isSameTree(p.right, q.right) #True and True才會return True

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if subRoot is None: #subroot為空，空樹是任何樹的子樹
            return True
        if root is None:
            return False

        if self.isSameTree(root,subRoot): #若root / subroot 完全相同
            return True

        #root / subroot 不同
        return self.isSubtree(root.left,subRoot) or self.isSubtree(root.right,subRoot)
        
        


