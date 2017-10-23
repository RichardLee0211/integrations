#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char const *argv[]) {

  unsigned long num = 0x12345678deadbeef;
  int n = isFib(num);
  printf("%lu %s", num, n > 0 ? " is fibonacci #" : " isn't a fibonacci.\n");
  if (n > 0){
    printf("%d\n", n);
  } else{
    printf("\n");
  }

  printf("Ooops");
	printf("count_vowels(0) = %u\n", count_vowels(0));
	printf("count_vowels(994223116) = %u\n", count_vowels(994223116));
  printf("%lx -> %lx\n", num, swap_bytes(num));
	printf("count_ones(%lx) = %u\n", num, count_ones(num));
  printf("a4_minus_b4(int %x, int %x) = %ld", 0xdead, 0xbeef, a4_minus_b4(0xdead,0xbeef));
  return 0;
}
