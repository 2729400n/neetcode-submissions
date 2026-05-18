class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        current = 0
        best = 0
        for v in nums:

            current = current*v+v
            b_c=best-current
            switch=((b_c>>32)&1)
            best = current*switch+best*(1-switch)
            print('best-current=',(b_c),', switch=',switch,', new_best=',best)

        return best

        