class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        current = 0
        best = 0
        for v in nums:
            if v == 1:
                current += 1
                if current > best:
                    best = current
            else:
                current = 0
        return best

        