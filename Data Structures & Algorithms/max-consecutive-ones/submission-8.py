class Solution:
    '''
    Solution to neet code easy 
    '''
    # Aim for speed and memory reduction
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        # current counter
        current = 0

        # best so far
        best = 0

        # Create and enter iterator context
        for v in nums: # preform iterator step
            current = current*v+v # we have a binary setup so it counts
            # in the case where it aint bin
            
            switch=((best-current)>>32)&1
            best = current*switch+best*(1-switch)

        return best

        