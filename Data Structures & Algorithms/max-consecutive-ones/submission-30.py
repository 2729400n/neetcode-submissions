class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        best = 0
        current = 0
        
        for n in nums:
            if n: 
                current += 1
            else:
                if current > best:
                    best = current
                current = 0
                
        # Catch the final run if the list ends in a 1
        if current > best:
            best = current
            
        return best
        