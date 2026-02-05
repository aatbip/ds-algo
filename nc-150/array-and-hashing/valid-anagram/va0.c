/* Given two strings 's' and 't', return true if two strings are anagrams, otherwise return false.
 *
 * An anagram is a string that contains the exact same characters as another string, but the order
 * of the characters can be different.
 *
 * In this program, we will detect if two strings are anagrams using the sort and compare technique.
 * If two sorted strings are compared and found to be equal then they are anagram. The complexity
 * of this method is:
 * Time complexity - O(nlogn)
 * Space complexity - O(1)
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compFn(const void *a, const void *b) {
  char *s1 = (char *)a;
  char *s2 = (char *)b;
  return (*s1 > *s2) - (*s1 < *s2);
}

bool isAnagram(const char *s, const char *t) {
  if (strlen(s) != strlen(t)) {
    return false;
  }
  char *s1 = malloc(strlen(s) + 1);
  char *s2 = malloc(strlen(t) + 1);
  strcpy(s1, s);
  strcpy(s2, t);
  qsort(s1, strlen(s), sizeof(char), compFn);
  qsort(s2, strlen(s), sizeof(char), compFn);

  bool result = (strcmp(s1, s2) == 0);
  free(s1);
  free(s2);
  return result;
}

int main(void) {
  printf("%d\n", isAnagram("zabb", "babz"));
  return 0;
}
