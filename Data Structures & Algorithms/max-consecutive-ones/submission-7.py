class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        current = 0
        best = 0
        for v in nums:

            current = current*v+v
            switch=((best-current)>>32)&1
            best = current*switch+best*(1-switch)

        return best

        