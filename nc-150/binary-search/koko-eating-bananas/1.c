/*Brute force try*/
#include <limits.h>
#include <math.h>
#include <stdio.h>

int min_eating_speed(int *piles, int n, int h) {
  int k = 1;
  for (;;) {
    long long t = 0;
    for (int i = 0; i < n; i++) {
      t += ceil((double)piles[i] / k);
    }
    if (t <= h) {
      return k;
    }
    k += 1;
  }
}

int main(void) {
  int piles[] = {30, 11, 23, 4, 20};
  int n = 5;
  int h = 5; // max time in hour to finish all piles
  printf("%d\n", min_eating_speed(piles, n, h));
  return 0;
}
