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

            b = c*(((b-c)>>32)&1)+b*(1-(((b-c)>>32)&1))

        return b

        