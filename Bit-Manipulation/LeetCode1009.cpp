class Solution {
public:
    int bitwiseComplement(int n) {
       

    if (n == 0) return 1;

    unsigned mask = ~0; 
    // mask = 11111111
    // n =    00000101
    // mask = 11111000

    11111000
    00000101
    // n | mask
    // 11111101
    // 00000010

    // 11111101
    // ~(n|mask) ~mask & ~n
    // 00000010

    while (n & mask) mask <<= 1;

    return ~mask & ~n;

    }
};
