
#define GetBit(reg,bit_num)  ((reg>>bit_num)&1)
#define ClrBit(reg,bit_num)  ((reg) &= ~(1<<bit_num))
#define SetBit(reg,bit_num)  ((reg) |= (1<<(bit_num)))               
#define ToggleBit(reg,bit_num)   ((reg) ^= (1<<(bit_num)))   