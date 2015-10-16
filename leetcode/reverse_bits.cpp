#include <cstdio>
#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for (int i=0; i<32; i++) {
            m |= ((n&(1<<i))>>i)<<(31-i);
        }
        return m;
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    uint32_t n = 43261596u;
    printf("Reverse %u = %u", n, s.reverseBits(n));
    return 0;
}
