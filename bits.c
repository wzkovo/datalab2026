/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return ~(x&y) & ~(~x&~y);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if(!x && !y) return 1;
    if(!x) return 0;
    if(!y) return 0;
    x = x & (1 << 31);
    y = y & (1 << 31);
    if(x^y) return 0;
    else return 1;
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int r = 0;
    int s;
    s = ((v >> 16) > 0) << 4;   v = v >> s;   r = r | s;   // 16
    s = ((v >> 8)  > 0) << 3;   v = v >> s;   r = r | s;   // 8
    s = ((v >> 4)  > 0) << 2;   v = v >> s;   r = r | s;   // 4
    s = ((v >> 2)  > 0) << 1;   v = v >> s;   r = r | s;   // 2
    r = r | ((v >> 1) > 0);      
    return r;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int bitn = (n << 3),bitm = (m << 3);
    int n1 = (255<<bitn);
    int m1 = (255<<bitm);
    int _n = x & n1;
    int _m = x & m1;
    x ^= _n ^ _m;
    _n >>= bitn;
    _n <<= bitm;
    _n &= m1;

    _m >>= bitm;
    _m <<= bitn;
    _m &= n1;
    x ^= _n ^ _m;
    return x;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned m;

    m = 0x0000FFFF; v = ((v & m) << 16) | ((v >> 16) & m);
    m = 0x00FF00FF; v = ((v & m) <<  8) | ((v >>  8) & m);
    m = 0x0F0F0F0F; v = ((v & m) <<  4) | ((v >>  4) & m);
    m = 0x33333333; v = ((v & m) <<  2) | ((v >>  2) & m);
    m = 0x55555555; v = ((v & m) <<  1) | ((v >>  1) & m);
    return v;
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int y = ~x;
    int n = !y;
    int c;

    c = !(y >> 16);
    n = n + (c << 4);
    y = y << (c << 4);

    c = !(y >> 24);
    n = n + (c << 3);
    y = y << (c << 3);

    c = !(y >> 28);
    n = n + (c << 2);
    y = y << (c << 2);

    c = !(y >> 30);
    n = n + (c << 1);
    y = y << (c << 1);

    c = !(y >> 31);
    n = n + c;

    return n;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned ans = 0, y = x, t, sh;
    int o = 0;

    if (x < 0) { y = -y; ans = 1u << 31; }
    if (!y) return 0;

    t = y;
    while (t) t >>= 1, ++o;

    y -= (1u << (o - 1));
    ans += (o + 126) << 23;

    if (o <= 24) ans += y << (24 - o);
    else {    
        sh = o - 24;
        y = (y + (1u << (sh - 1)) - 1 + ((y >> sh) & 1)) >> sh;
        if (y >> 23) { ans += 1u << 23; y = 0; }
        ans += y;
    }
    return ans;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned s = uf & 0x80000000;
    unsigned E = (uf >> 23) & 0xFF;
    unsigned w = uf & 0x007FFFFF;
    if(E == 255) return uf;
    else if(E == 0) return (w << 1) + s;
    else if(E == 254) return s + ((E + 1) << 23);
    else return s + ((E + 1) << 23) + w;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned tmp = uf1;
    uf1 = uf2;
    uf2 = tmp;
    unsigned s = uf1 & 0x80000000;
    unsigned E = (uf1 >> 20) & 0x7FF;
    if(E <= 1022) return 0;
    else if(E >= 1054) return 0x80000000;
    else {
        unsigned o = E - 1023;
        o+=1;
        unsigned x = 0x80000000 + ((uf1 & 0x000FFFFF) << 11) + ((uf2 >> 21) & 0x7FF);
        x >>= (32 - o);
        if(s) return ~x+1;
        else return x;
    }
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if(x < -149) return 0;
    else if(x > 128) return 0x7F800000;
    else if(x < -126){
        unsigned o = -126 - x - 1;
        return ((1u<<22)>>o);

    } else {
        unsigned E = x + 127;
        return (E << 23);
    }
}
