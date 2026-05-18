class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        # resizing sliding window
        left =-1
        right=-1

        # at start no zeros found
        max_val=0
        lnum = len(nums)

        # must be linear time
        for i in range(lnum):

            # we got a zero so right safely moves in
            # distance between left and right increases
            if(nums[i]==1):
                right+=1
            else:
                # we got a non zero
                # get current distance 
                maxval_pot=right-left

                # if current distance greater switch
                if(maxval_pot>max_val):
                    max_val=maxval_pot
                right=left=i

        # end catch case for if all 0        
        maxval_pot=right-left

        # if current distance greater switch
        if(maxval_pot>max_val):
            max_val=maxval_pot
        return max_val

        