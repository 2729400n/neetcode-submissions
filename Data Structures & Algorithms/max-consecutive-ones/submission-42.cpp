#include <vector>

class Solution {
public:
    constexpr int findMaxConsecutiveOnes(const std::vector<int>& nums) {
        int current = 0;
        int best = 0;
        
        // Drop down to raw pointers to completely bypass C++ iterator overhead
        const int* ptr = nums.data();
        const int* const end = ptr + nums.size();
        
        // Loop Unrolling: Process 4 elements per loop iteration.
        // This reduces the loop overhead (bounds checking and jumps) by 75%.
        while (ptr + 3 < end) {
            // Element 1
            current = (current + 1) & (-ptr[0]);
            int diff1 = best - current;
            best = best - (diff1 & (diff1 >> 31));
            
            // Element 2
            current = (current + 1) & (-ptr[1]);
            int diff2 = best - current;
            best = best - (diff2 & (diff2 >> 31));
            
            // Element 3
            current = (current + 1) & (-ptr[2]);
            int diff3 = best - current;
            best = best - (diff3 & (diff3 >> 31));
            
            // Element 4
            current = (current + 1) & (-ptr[3]);
            int diff4 = best - current;
            best = best - (diff4 & (diff4 >> 31));
            
            ptr += 4; // Advance pointer by 4
        }
        
        // Tail processing: Handle the remaining 0 to 3 elements
        while (ptr < end) {
            current = (current + 1) & (-*ptr);
            int diff = best - current;
            best = best - (diff & (diff >> 31));
            ptr++;
        }
        
        return best;
    }
};