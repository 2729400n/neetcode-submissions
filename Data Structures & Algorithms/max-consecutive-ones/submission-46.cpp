class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        // 1. Explicit Register Allocation (GNU C Extension)
        // We force the pointers and accumulators into specific hardware registers.
        register const int* ptr asm("rsi") = nums.data();
        register const int* end asm("rdi") = ptr + nums.size();
        
        // eax will hold 'current', edx will hold 'best'
        register int current asm("eax") = 0;
        register int best asm("edx") = 0;

        // 2. Volatile Inline Assembly Block
        // The compiler is strictly forbidden from optimizing or unrolling this block.
        __asm__ __volatile__ (
            ".p2align 4 \n\t"         // Align the loop start to a 16-byte boundary for the CPU instruction cache
            
            "1: \n\t"                 // Local Label: Loop Start
            
            // --- Memory Fetch ---
            "mov (%%rsi), %%ecx \n\t" // ecx = *ptr (load current array value: 0 or 1)
            "add $4, %%rsi \n\t"      // Advance pointer by 4 bytes (sizeof(int))
            
            // --- Branchless Accumulate ---
            // current = (current + 1) & (-v)
            "inc %%eax \n\t"          // eax = current + 1
            "neg %%ecx \n\t"          // Two's complement negation. If ecx was 1 -> 0xFFFFFFFF. If 0 -> 0x00000000
            "and %%ecx, %%eax \n\t"   // Mask current: resets to 0 if the array value was 0
            
            // --- Branchless Max ---
            // We use r8d as our temporary 'diff' and 'mask' register
            "mov %%edx, %%r8d \n\t"   // r8d = best
            "sub %%eax, %%r8d \n\t"   // r8d = best - current (this is our 'diff')
            
            "mov %%r8d, %%ecx \n\t"   // Copy diff to ecx to create the mask
            "sarl $31, %%ecx \n\t"    // Arithmetic shift right: ecx = -1 (all 1s) if current > best, else 0
            
            "and %%ecx, %%r8d \n\t"   // r8d = diff & mask
            "sub %%r8d, %%edx \n\t"   // best = best - (diff & mask)
            
            // --- Loop Control ---
            "cmp %%rdi, %%rsi \n\t"   // Compare current pointer (rsi) with end pointer (rdi)
            "jne 1b \n\t"             // Jump if not equal back to label 1 (backward jump)
            
            // 3. I/O Constraints
            : "+a" (current), "+d" (best), "+S" (ptr) // Outputs / In-Out variables tied to eax, edx, rsi
            : "D" (end)                               // Inputs tied to rdi
            : "ecx", "r8d", "cc", "memory"            // Clobbered registers and condition codes
        );

        // A final register pop: 'best' is already physically residing in the 'edx' register.
        // Returning it requires zero memory access.
        return best;
    }
};