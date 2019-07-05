# Problem Decription
Given a 2D array of distinct integers with n numbers, "compress" the array such that the resulting array's numbers are in the range `[1, n]` and their relative order is kept.

Relative order means that if a number at position (row1, col1) is smaller than a number at position (row2, col2) in the original array, it should still have that relationship in the resulting array.

## Example:
  Input:
  7 6
  4 9

  Output:
  3 2
  1 4

# Follow-up
Compress the array to make the numbers as small as possible as long as the relative order holds true for numbers in the same row and column.

## Example 1:
  Input:
  7 6
  4 9

  Output:
  2 1
  1 2

## Example 2:
  Input:
  25 74 54
  12 56 83

  Output:
  2 4 3
  1 2 4

## Example 3:
  Input:
  20 80 60 70
  11 90 22 44
  33 99 49 88

  Output:
  2 7 5 6
  1 8 2 3
  3 9 4 7
