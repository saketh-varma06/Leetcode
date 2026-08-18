class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        num=2**0
        power=0
        while(num<=n):
            num=2**power
            if(num==n):
                return True
            power+=1
        return False