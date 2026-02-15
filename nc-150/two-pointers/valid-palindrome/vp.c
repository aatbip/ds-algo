/* Given a string s, return true if it is a palindrome, otherwise return false.
 * A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all
 * non-alphanumeric characters.
 * Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).
 * Example - Input: s = "Was it a car or a cat I saw?"
 *           Output: true
 *
 * */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(char *str) {
  int i = 0, j = strlen(str) - 1;
  while (i < j) {
    while (i < j && isalnum((unsigned char)str[i]) == 0)
      i++;
    while (i < j && isalnum((unsigned char)str[j]) == 0)
      j--;
    if (tolower((unsigned char)str[i]) != tolower((unsigned char)str[j]))
      return false;
    i++;
    j--;
  }
  return true;
}

int main(void) {
  char *str = "Was it a car or a cat I saw?";
  printf("%d\n", isPalindrome(str));

  return 0;
}
