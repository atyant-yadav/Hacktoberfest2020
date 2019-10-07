class Solution:
	# @param A : list of integers
	# @param B : list of integers
	# @return the root node in the tree
	def buildTree(self, A, B):
	    if not B:
	        return None
	    root_pos = A.index(B[-1])
	    new_node = TreeNode(B[-1])
	    new_node.left = self.buildTree(A[:root_pos], B[:root_pos])
	    new_node.right = self.buildTree(A[root_pos+1:], B[root_pos:-1])
	    return new_node
