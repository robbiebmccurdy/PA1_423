README for Programming Assignment #1

Name: Robert McCurdy
Class: CSCI 423

Files Included: 

PA1_423_PartA.c (Part A)
PA1_423_PartB.c (Part B)

Part A - 

This program reads from an input.txt file and then writes the data from
that into an output file.

To call this program, type the following in the terminal: 

gcc PA1_423_PartA.c -o PA1PartA

./PA1PartA input.txt output.txt

Part B -

An expansion on Part A. This program will take the input.txt file, sort the
numbers from that file, and then put it into the output.txt file.

To call this program, type the following in the terminal: 

gcc PA1_423_PartB.c -o PA1PartB

./PA1PartB input.txt output.txt

The sorting method used for Part B was selection sort. This program also uses
dynamic memory, so theortically the size of the file should not matter.
