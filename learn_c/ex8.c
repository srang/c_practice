#include <stdio.h>
int main(int argc, char* argv[])
{
  int areas[] = {10,12,13,14,20};
  char name[] = "Zed";
  char full_name[] = {
    'Z', 'e', 'd',
    ' ', 'A', '.', ' ',
    'S', 'h', 'a', 'w', '\0'
  };
  printf("The size of an int: %ld\n", sizeof(int));
  printf("The size of areas(int[]): %ld\n",
      sizeof(areas));
  printf("The number of ints in areas: %ls\n",
      sizeof(areas) / sizeof(int));
  printf("The first area is %d, the second %d.\n",
      areas[0], areas[1]);
  printf("The size f a char: %ld\n", sizeof(char));


  return 0;
}
