1 Huffman Codes:
A Huffman code can be used to compress a file. It replaces fixed-size, one-byte characters by variable-
length codes (strings of bits). The codes for the most frequently used characters will be shorter than
8 bits, those for unusual characters will be longer. No codes are generated for characters that are not
used. The input file is read twice, once to generate the code, then again to encode the file. This is an
effective compression method for all ASCII text files, because the ASCII code uses only 7 bits and the
Huffman Code uses all 8 bits in a byte.
Coding this multi-step algorithm will be your work for the next month. In the process, you will
use several major data structures and produce a bit-oriented output file. The UML diagram below
shows the overall architecture of the completed project. The green and yellow parts will be created in
Program 5.

2 Goals of Program 5
1. To use a command-line argument for main(), the name of the file to be compressed.
2. To write the first two phases of a file compression program that we be further developed in
programs 6 and 7.
3. To use characters as subscripts for an array.
4. To implement / adapt the heap algorithms.
   
2.1 The main Program
The main program. In main():
1. Call banner()
2. Then pick up the name of the input file from the command line. Call the Huffman constructor
with this file name as its parameter.
3. Call Huffman::compress().
4. Call bye() and end execution.

2.2 P5 Phase 1: The Initial Tally
In this phase, you will count the number of times each character appears in a text file. Debug this
before you start Phase 2.
pair<char,
string>
map
HuffCode
BOFstream
Huffman (Controller)
- int[] tallyTable
- HuffHeap hp
- ifstream plaintext
- HuffTree ht
- HuffCode hc
- BOFstream compressed
Huffman, the Controller Class. Declare a class named Huffman. It will be instantiated by main
and will, in turn, instantiate and run all other parts of the application. Data members for P5 are:
1. tally, an array of 256 integers for counting occurrences of the 256 possible ASCII characters.
2. An ifstream for the input file.
3. A counter for the number of input characters
Function members for this phase include:
1. A constructor with one string parameter. Open and verify the file named by the parameter.
2. A print function that prints the final contents of the tally array and the number of characters in
the file. This function is for debugging. It is not part of the compression algorithm. Code will
be added to this function in later assignments.
3. A private worker function named doTally().
(a) Read the input file one character at a time, in a way that does not skip whitespace.
(b) Use the character code to subscript the tally array, and add 1 to the appropriate array slot.
(c) When eof is found, make your input file so that it is ready to read again by seeking to 0
bytes from the beginning of the file: streamName.seekg (0, is.beg);
4. A public worker function named compress. This is the primary function that implements the
application. It will be called from main and it calls all other major functions. At this time
implement the following:
(a) Call doTally(). When it returns, print the results of the tally, including the number of
characters in the input file.
(b) Call the Heap constructor with a pointer to the tally array as its parameter.
(c) Call heapify(); it must return a Node* (alias Tree) that is the root of a HuffTree.
(d) When heapify() returns, call Heap::print().
(e) Calls on other phases of the program will be added here, as the project develops.

Sample data. Below is a text that will be used to illustrate all phases of this process. Please note
that this IS NOT the required input file to be used for submission of your project.
Morals rule everything! (Or is it money?)
The non-zero results of tallying our text are shown below in ASCII sequence order:

! ( ) ? ’ ’ M O a e g h i l m n o r s t u v y
1 1 1 1 6 1 1 1 4 1 1 3 2 1 2 2 4 2 2 1 1 2
