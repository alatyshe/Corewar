#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	unsigned char	a, r, mask;

	a = 0xCA;
	
	//	это все работет только с unsigned тк там остаток от деления берется

	printf("original char :\n");
	printf("%02X - %d%d%d%d%d%d%d%d\n", 
		a, a>>7, (a>>6)%2, (a>>5)%2, (a>>4)%2,
		(a>>3)%2, (a>>2)%2, (a>>1)%2, a%2);

	r = ~a;			//	битовое отрицание
	printf("display after ~ :\n");
	printf("%02X - %d%d%d%d%d%d%d%d\n", 
		r, r>>7, (r>>6)%2, (r>>5)%2, (r>>4)%2,
		(r>>3)%2, (r>>2)%2, (r>>1)%2, r%2);

	mask = 0x0F;	// те разряды где меня интересует значение, мы ставим 1, в данном случе будет 0000 1111

	printf("\nPRINT MASK:\n");
	printf("%02X - %d%d%d%d%d%d%d%d\n", 
		mask, mask>>7, (mask>>6)%2, (mask>>5)%2, (mask>>4)%2,
		(mask>>3)%2, (mask>>2)%2, (mask>>1)%2, mask%2);

	r = a & mask;	//	битовая коньюнция
	printf("display after & apply mask to A :\n");
	printf("%02X - %d%d%d%d%d%d%d%d\n", 
		r, r>>7, (r>>6)%2, (r>>5)%2, (r>>4)%2,
		(r>>3)%2, (r>>2)%2, (r>>1)%2, r%2);

	r = a | mask;	//	битовая дизьюнкция
	printf("display after | apply mask to A :\n");
	printf("%02X - %d%d%d%d%d%d%d%d\n", 
		r, r>>7, (r>>6)%2, (r>>5)%2, (r>>4)%2,
		(r>>3)%2, (r>>2)%2, (r>>1)%2, r%2);

	r = a ^ mask;	// исключаещее или
	printf("display after ^ apply mask to A :\n");
	printf("%02X - %d%d%d%d%d%d%d%d\n", 
		r, r>>7, (r>>6)%2, (r>>5)%2, (r>>4)%2,
		(r>>3)%2, (r>>2)%2, (r>>1)%2, r%2);


	r = a & ~mask;	//	битовая коньюнция (удаляем ненужные биты с помощью данной маски)
	printf("display after & apply ~mask to A :\n");
	printf("%02X - %d%d%d%d%d%d%d%d\n", 
		r, r>>7, (r>>6)%2, (r>>5)%2, (r>>4)%2,
		(r>>3)%2, (r>>2)%2, (r>>1)%2, r%2);


	printf("\noriginal char :\n");
	printf("%02X - %d%d%d%d%d%d%d%d\n", 
		a, a>>7, (a>>6)%2, (a>>5)%2, (a>>4)%2,
		(a>>3)%2, (a>>2)%2, (a>>1)%2, a%2);

	r = a<<2;
	printf("a<<2 :\n");
	printf("%02X - %d%d%d%d%d%d%d%d\n", 
		r, r>>7, (r>>6)%2, (r>>5)%2, (r>>4)%2,
		(r>>3)%2, (r>>2)%2, (r>>1)%2, r%2);

	r = a>>2;
	printf("a>>2 :\n");
	printf("%02X - %d%d%d%d%d%d%d%d\n", 
		r, r>>7, (r>>6)%2, (r>>5)%2, (r>>4)%2,
		(r>>3)%2, (r>>2)%2, (r>>1)%2, r%2);
	return 0;
}