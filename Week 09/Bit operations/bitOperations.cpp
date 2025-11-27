bool getKthBitFromRightToLeft(int num, int k) {
    return num & (1 << k);
}

int toggleKthBit(int n, int k) {
    return n ^ (1 << k);
}

bool isEven(int number) {
    int mask = 1;
    // check if the last bit is a 1 to see if it is odd
    // !isOdd => isEven
    return !(number & mask);
}

unsigned powerOfTwo(unsigned power) {
    if(power > 31) {
         // 2^31 is the max power of 2 that can be contained in an unsigned
         return 0;
    }

    return 1 << power; // same as 2^n
}

unsigned setBitZero(unsigned int number, unsigned int index) {
    unsigned int mask = 1;
    // 0000100000
    mask <<= index;
    // 1111011111
    mask = ~mask; // everywhere one apart from the index where you want to set 0

    // 0000100010
    // 1111011111
    // &
    // 0000000010
    return number & mask;
}

unsigned setBitToOne(unsigned number, unsigned index) {
    unsigned int mask = 1;
    // 0000100000
    mask <<= index; // everywhere zero apart from the index where you want to set 1

    // 0000100000
    // 1110000111
    // |
    // 1110100111
    return number | mask;
}
