class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum=0
        max_sum=nums[0]
        for i in nums:
            sum+=i
            max_sum=max(max_sum,sum)
            if(sum<0):
                sum=0
        return max_sum