A program to accept a string from the keyboard, reverse the string, capitalize all alphabet chars in the string, print each char on its own line, print the number of alphabet chars capitalized and print the length of the string.  If the prompt and input string is:

Enter a string: Hello World!

The output should be:
!
D
L
R
O
W

O
L
L
E
H

The string is 12 chars and 8 chars were capitalized.

The challenge of this function is not using C library functions to get the length of a string, convert to upper case and test for lower case.  

1. Main function – calls other functions
2. Function to get the length of a string
3. Function to test if a char is lower case (Hint: for char c, c >= ‘a’ works)
4. Function to convert a lower case char to uppercase (Hint: Look at positions in ASCII table)
5. Function to get string from keyboard. Hint: scanf will not work for strings with spaces. Google gets() and make sure that the string is sufficiently large to contain reasonable size input.
6. Function to reverse string.
7. Function to capitalize all alpha chars and count number capitalized.
8. Function to print output.
