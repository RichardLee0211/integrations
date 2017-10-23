#include "functions.h"
#include <stdio.h>
#include <math.h>

/***********************************/
/*                1                */
/***********************************/
int isFib(unsigned long n)
{
	unsigned long curr, next, temp;
	int i;

	if(n == 0) return 1;
	if(n == 1) return 2;

	i = 2;
	curr = 1;
	next = 1;
	while(next <= n) {
		i++;
		if(next == n) return i;
		temp = next;
		next += curr;
		curr = temp;
	}
	return -1;
}

/***********************************/
/*                2                */
/***********************************/
unsigned int count_units(unsigned int num) {
    unsigned int count;
    switch(num) {
	case 1: /* OnE */
	case 3: /* thrEE */
	case 4: /* fOUr */
	case 5: /* fIvE */
	case 7: /* sEvEn */
	case 8: /* EIght */
	case 9: /* nInE */
		count = 2;
		break;
	case 2: /* twO */
	case 6: /* sIx */
		count = 1;
		break;
	default: count = 0; break; /* Impossible case! */
    }
    return count;
}

unsigned int count_tens(unsigned int num)
{
    unsigned int tens, units;
    if(num < 10) return count_units(num);
    if(num < 20) { /* 10 to 19 */
	/* tEn: 1, ElEvEn: 3, twElvE: 2, thIrtEEn: 3, fOUrtEEn: 4, fIftEEn: 3, sIxtEEn: 3, sEvEntEEn: 4, EIghtEEn: 4, nInEtEEn: 4 */
	if(num == 10) return 1;
	if(num == 12) return 2;
	if(num == 11 || num == 13 || num == 15 || num == 16) return 3;
	if(num == 14 || num == 17 || num == 18 || num == 19) return 4;
    }

    /* twEnty: 1, thIrty: 1, fOrty: 1, fIfty: 1, sIxty: 1, sEvEnty: 2, EIghty: 2, nInEty: 2 */
    tens = num / 10;
    units = num % 10;
    if(tens >= 2 && tens <= 6) return 1 + count_units(units);
    if(tens > 6 && tens <= 9) return 2 + count_units(units);

    /* Should never reach here */
    return 0;
}

unsigned int count_hundreds(unsigned int num)
{
	return count_units(num/100) + ((num/100 > 0) ? /* hUndrEd */ 2 : 0) + count_tens(num % 100);
}

unsigned int count_millions(unsigned int num)
{
	return (num > 0) ? count_hundreds(num) + /* mIllIOn */ 3 : 0;
}

unsigned int count_thousands(unsigned int num)
{
	return (num > 0) ? count_hundreds(num) + /* thOUsAnd */ 3 : 0;
}

unsigned int count_vowels(unsigned long num) {
	unsigned int remaining, thousands, millions;
	/* 1 billion is a special case */
	if(num == 1000000000) return 5; /* OnE bIllIOn */

	/* Zero is a special case */
	if(num == 0) return 2; /* zErO */

	thousands = (num / 1000) % 1000;
	millions = (num / 1000000) % 1000000;
	remaining = num % 1000;

	//printf("millions = %u\tthousands = %u\thundreds = %u\ttens = %u\tunits = %u\n", millions, thousands, remaining/100, (remaining %100)/10, remaining%10);
	/* printf("Total count = %u\n", count_millions(millions) + count_thousands(thousands) + count_hundreds(hundreds)); */
	return count_millions(millions) + count_thousands(thousands) + count_hundreds(remaining);
}

/***********************************/
/*                3                */
/***********************************/
unsigned int count_ones(long num) {
	unsigned long n;
	unsigned int count;
	n = (unsigned long) num;
	count = 0;
	while(n != 0) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}


/***********************************/
/*                4                */
/***********************************/
unsigned char get_byte(unsigned long n, unsigned int byte_num)
{
	return (n >> (8 * (byte_num - 1))) & 0xff;
}

unsigned long swap_bytes(unsigned long n)
{
	unsigned char b1, b2, b3, b4, b5, b6, b7, b8;
	unsigned long res;
	b1 = get_byte(n, 1);
	b2 = get_byte(n, 2);
	b3 = get_byte(n, 3);
	b4 = get_byte(n, 4);
	b5 = get_byte(n, 5);
	b6 = get_byte(n, 6);
	b7 = get_byte(n, 7);
	b8 = get_byte(n, 8);
	res = b7;
	res = (res << 8) | b8;
	res = (res << 8) | b5;
	res = (res << 8) | b6;
	res = (res << 8) | b3;
	res = (res << 8) | b4;
	res = (res << 8) | b1;
	res = (res << 8) | b2;
	return res;
}

/***********************************/
/*                5                */
/***********************************/
long a4_minus_b4(int a, int b)
{
	return pow((double) a, 4) - pow((double) b, 4);
}

void sqrt(float f){
	printf("The square root of %f is %f\n", f, sqrt(f));
}
