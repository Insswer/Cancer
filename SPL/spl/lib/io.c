#include <io.h>


void sr32(u32 addr, u32 start_bit, u32 num_bits, u32 value)
{
	u32 tmp, msk = 0;
	msk = 1 << num_bits;
	--msk;
	tmp = readl(addr) & ~(msk << start_bit);
	tmp |=  value << start_bit;
	writel(tmp, addr);
}


u32 wait_on_value(u32 read_bit_mask, u32 match_value, u32 read_addr,
			  u32 bound)
{
	u32 i = 0, val;
	do {
		++i;
		val = readl(read_addr) & read_bit_mask;
		if (val == match_value)
			return 1;
		if (i == bound)
			return 0;
	} while (1);
}

