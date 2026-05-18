class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int current = 0;
        int best = 0;
        
        for (int v : nums) {
            // Branchless accumulate
            current = current * v + v;
            
            int diff = best - current;
            int mask;
            
            // Inline Assembly: Shift Arithmetic Right Long (sarl) by 31 bits.
            __asm__ (
                "sarl $31, %0"
                : "=r" (mask)  // Output operand
                : "0" (diff)   // Input operand
            );
            
            // Branchless max selection using a bitwise MUX:
            // If mask == -1 (all 1s): (current & -1) | (best & 0) -> current
            // If mask ==  0 (all 0s): (current &  0) | (best & -1) -> best
            best = (current & mask) | (best & ~mask);
        }
        
        return best;
    }
};