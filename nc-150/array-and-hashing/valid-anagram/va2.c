/* Given two strings 's' and 't', return true if two strings are anagrams, otherwise return false.
 *
 * This program solves the problem using array based hash table.
 * Time complexity - O(n)
 * Space complexity - O(1)
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(const char *s, const char *t) {
  size_t len = strlen(s);
  if (len != strlen(t)) {
    return false;
  }
  int c[26] = {0}; // array of size 26 (total number of alphabets) initialized to 0
  for (int i = 0; i < len; i++) {
    c[s[i] - 'a']++;
    c[t[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++) {
    if (c[i] != 0) {
      return false;
    }
  }
  return true;
}

int main(void) {
  printf("%d\n", isAnagram("tytz", "oytt"));
  return 0;
}
