# A+B for Polynomials
This time, you are supposed to find `A + B` where `A` and `B` are two polynomials.

## Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

    K N_1 a_{N1} N_2 a_{N2} ... N_K a_{NK}
where `K` is the number of nonzero terms in the polynomial, `N_i` and `a_{Ni} (i = 1, 2, ..., K)` are the exponents and coefficients, respectively. It is given that `1 <= K <= 10, 0 <= N_K < ... < N_2 < N_1 <= 1000`.

## Output Specification:
For each test case you should output the sum of `A` and `B` in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

## Sample Input:
    2 1 2.4 0 3.2
    2 2 1.5 1 0.5
## Sample Output:
    3 2 1.5 1 2.9 0 3.2