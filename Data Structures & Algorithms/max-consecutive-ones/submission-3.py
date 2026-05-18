class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        current = 0
        best = 0
        for v in nums:

            current = current*v+v
            if current > best:
                best = current
        return best

        