unsigned int
reverse(register unsigned int x)
{
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return((x >> 16) | (x << 16));

}

/* Simple Method */
unsigned int v;     // input bits to be reversed
unsigned int r = v; // r will be reversed bits of v; first get LSB of v
int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end

for (v >>= 1; v; v >>= 1)
{   
  r <<= 1;
  r |= v & 1;
  s--;
}
r <<= s; // shift when v's highest bits are zero




/* Below sequence can be used when we want to only bits too be reversed in byte 
   Call the byte to be reverse as REVERSE_BIT8(i) */
#define REVERSE_BIT2(num) ((((num) & 0x2) >> 1) | (((num) & 0x01) << 1))
#define REVERSE_BIT4(num) (REVERSE_BIT2(((num) & 0x0C) >> 2) | (REVERSE_BIT2((num) & 0x03) << 2))
#define REVERSE_BIT8(num) (REVERSE_BIT4(((num) & 0xF0) >> 4) | (REVERSE_BIT4((num) & 0x0F) << 4))
