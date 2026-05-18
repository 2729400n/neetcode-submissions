class Solution:
    '''
    Solution to neet code easy 
    '''
    # Aim for speed and memory reduction
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        # current counter
        c = 0

        # best so far
        b = 0

        # Create and enter iterator context
        for v in nums: # preform iterator step
            c = c*v+v # we have a binary setup so it counts
            # in the case where it aint bin

            # s=((b-c)>>32)&1
            # b = c*s+b*(1-s)
            b=max(c,b)

        return b

        