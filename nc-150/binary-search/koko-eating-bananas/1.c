/* You are given an integer array piles where piles[i] is the number of bananas
 * in the ith pile. You are also given an integer h, which represents the number
 * of hours you have to eat all the bananas.
 * You may decide your bananas-per-hour eating rate of k. Each hour, you may choose
 * a pile of bananas and eats k bananas from that pile. If the pile has less than k
 * bananas, you may finish eating the pile but you can not eat from another pile in
 * the same hour.
 * Return the minimum integer k such that you can eat all the bananas
 * within h hours.
 *
 * Example - Input: piles = [1,4,3,2], h = 9
 *           Output: 2
 *
 * This program solves the problem using brute force approach. 'k' is the speed of
 * eating the bananas. We calculate total time taken for each 'k' then increment 'k'
 * until a valid minimum eating speed is found.
 *
 * Time complexity -
 * O(m*n), where 'n' is the size of array piles and 'm' is the max number of bananas
 * in a pile. This is true because 'k' moves from 1 to 'm' and each time the array
 * of piles is iterated.
 *
 * Space complexity -
 * O(1)
 *
 * */

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
