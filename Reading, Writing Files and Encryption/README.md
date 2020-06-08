This C program has 2 parts: Reading and Writing Files, and Encryption 

Part 1: Reading and Writing Complete Files 
The first part of the program is to write a program to read the complete contents of a file to a string. This code will be used in subsequent coding problems. You will need 3 functions: main(), read_file() and write_file(). The main function contains the driver code. The read_file() function reads the complete contents of a file to a string. The write_file() writes the complete contents of a string to a file. The read_file() will require:

Open the file for reading Calculating the size of a file
Allocating memory to read the file to a string Rewinding the file to the beginning
Reading the files contents to the allocated string Close the file
There are a few ways to calculate the length of a file. Beware that some of these methods actually get the last position of the input buffer, which may not be the file length for very large files. I suggest using getc(file) until EOF is read with a counter. getc() reads one char at a time from a data stream. EOF will be read at the end of the text file. The malloc() and free() functions are used to dynamically allocate memory. For int n, char *string = (char*) malloc(n) will allocate n bytes to string, and free(string) deallocates the memory, freeing it for other work. The rewind(file) function returns the file pointer to the beginning of the file. You can use getc() or fgets() to read the file into the string. Writing the file will require:

Open the file for writing Write the string to file Close the file

The main function should free() allocated memory before returning. 
 
Part 2: One Time Pad Encryption 
One Time Pad (OTP) encryption, when implemented properly, cannot be hacked by cryptanalysis. This method uses the clear text (message to be encrypted), a random key of characters (the same size of the clear text) and the exclusive OR (XOR) operator. The table below contains the truth tables for bitwise operators. These operators work bit-by-bit on C data.

AND (&)	0	1		OR (|)	0	1		XOR (^)	0	1
0	0	0		0	0	1		0	0	1
1	0	1		1	1	1		1	1	0

The table below shows the result of encrypting the clear text A with the random key * using the bit-by- bit XOR bitwise operator. Each bit position in A is XORed with its respective bit in *, producing cipher text k.

	char	int	hex	bin
Clear text	A	65	41	01000001
				XOR
Rand key	*	42	2A	00101010
Cipher text	k	107	6B	01101011

The clear text can be recovered from the cipher text by using the cipher key and the XOR operator as shown in the table below.

	char	int	hex	bin
Cipher text	k	107	6B	01101011
				XOR
Rand key	*	42	2A	00101010
Clear text	A	65	41	01000001

There is an article about OTP at: https://en.wikipedia.org/wiki/One-time_pad
This project will require the use of the read_file() and write_file() from Part 1 and the following functions:
1.	main function with a menu including 3 choices: encrypt file, decrypt file and exit program.
2.	make_rand_key(length of key, key) generates a fixed length string of random chars.
3.	encrypt(clear file, key file, cipher file) generates a random key using make_rand_key(), perform the clear text XOR ket text, byte-by-byte, to produce the cipher text string and write both the random key and cipher text strings to file.
4.	decrypt(key file, cipher file, clear file) uses the cipher text XOR random key to recover the original
 
clear text and writes the clear text to a file (make sure to use a different file name than the original file so you can compare the results)
Modify the read_file() and write_file() functions to also accept an integer argument representing a fixed number of bytes to be read or written. This is to specify the number of bytes to be read from the cipher file, which may contain the EOF character, or write to the cipher text file, which may contain null chars. This is necessary because the cipher may contain both EOF and \0 characters. This will be explained further below. Sample function calls to read_file() and write_file():

1.	read_file(0, clear_file); // Read in a file with of unknown length, getting the length from the file read. clear_file is a string containing the path to the clear text file. This function returns a char array created with memory allocation.
2.	read_file(len, clear_file); // Where len > zero, reads len chars from a file. clear_file is a string containing the path to the clear text file. This function returns a char array created with memory allocation.
3.	write_file(0, key, key_file); // Writes a string to file until the \0 char is reached. key is the string of random chars and key_file is a string containing the path of the text file.
4.	write_file(len, cipher, cipher_file); // Where len > zero, writes len chars to a file. cipher is the cipher string of chars and cipher_file is a string containing the path of the text file.
The menu in main() should look like:
Encrypt a file: 1 Decrypt a file: 2 Exit:	3
Enter a choice:

The make_rand_key() accepts the length of the random key char array and a pointer to this array. This function uses the srand(time(NULL)) function to seed the rand() function and the rand() function to get random chars. The rand() function accepts no argument and returns an integer value between 0 and RAND_MAX (32,767 on most Intel-based computers). The return from rand must be scaled between 0 and 255 and explicitly castes as a char before being added to the char array. The EOF (integer value of -1) must not be selected as one of the chars in the array so it can be read back from a file during the decrypt operation. If EOF is detected as a random char, subtract 1 from the value to make it -2. It may also be a good idea to replace any null (integer value 0). This may interfere with writing to file and should be replaced with 1. A sample function call to make_rand_key is:
 
make_rand_key(len, key); // Where len > zero, generates and returns a random key of len chars.

The encrypt() function accepts the clear text, random key and cipher text file names as arguments. It reads the clear text files, generates a random key, performs XOR on clear text and random key, producing the cipher text, and writes the cipher text to file. When using malloc(), make sure to add 1 to the length of the string for the null char. Also, make sure to free() any allocated memory before the function returns. Sample function call for encrypt():

encrypt(clear_file, key_file, cipher_file); // Where the three arguments are strings containing filenames.

The decrypt() function accepts the random key, cipher text and cipher text file names as arguments. It reads the random key and cipher text files. Read the random key first using read_file and either getc (in a loop) or fgets to read the cipher text file due to the possibility of a stray EOF in the cipher file. Sample function for decrypt():

decrypt(key_file, cipher_file, message_file); // Where the three arguments are strings containing filenames.
Note: You must check if memory is successfully allocated and that files are opened successfully before using pointers to these objects. If a memory allocation or file open is unsuccessful, the pointer will be NULL. If a NULL pointer is found, you should provide an appropriate error message and terminate the program. You can test that the open file check works by passing a filename that does not exist.
