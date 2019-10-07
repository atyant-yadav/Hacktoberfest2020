# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : root node of tree
    # @return the root node in the tree
    def flatten(self, a):
        def preord(a,r):
            if not a:
                return
            r.append(a.val)
            preord(a.left,r)
            preord(a.right,r)
        r=[]
        preord(a,r)
        h=n=TreeNode(r[0])
        for i in range(1,len(r)):
            n.right=TreeNode(r[i])
            n=n.right
        return h
