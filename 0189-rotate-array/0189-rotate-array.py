class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        if n==0:
            return
        k%=n
        nums.reverse()
        temp=nums[:k]
        temp.reverse()
        nums[:k]=temp
        temp2=nums[k:]
        temp2.reverse()
        nums[k:]=temp2