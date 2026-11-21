from collections import Counter
class Solution:
    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        ans=[]
        dic=Counter(nums)
        for i in range(1,len(nums)+1):
            if i not in dic:
                ans.append(i)
        return ans