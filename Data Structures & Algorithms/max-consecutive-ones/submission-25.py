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
            # in the case where it isn't bin usint a test is available
            # also we can sub and test

            # [optimization] if statements are to bold
            # removes speed by handling branch predictions removing branching

            # I know everything fits in safe 32bit values so no weird python leb128 shenanigans
            # is it a negative the b<c 
            s=((b-c)>>32)&1

            # use 1 as the if using multiple and sub for 
            b = c*s+b*((~s)&1)

        return b

        