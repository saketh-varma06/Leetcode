# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        result=[]
        def inorder(curr,result):
            if curr is None:
                return
            inorder(curr.left,result)
            result.append(curr.val)
            inorder(curr.right,result)
        inorder(root,result)
        return result