class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        ans=[]
        for num in nums:
            ans.append(num*num)
        return sorted(ans)