# Prime-Calculator

This program is written in C which is an implementation of Sieve of Eratosthenes algorithm to find the largest prime number & also print the count within the given range. This project has two different source codes (sieve.c & segemented_sieve.c) which are two different approaches of this algorithm & have different output performance.

## Running the program
	To run this program, open any of the two source codes in any IDE with gcc compiler. Change the defined constant
	(line-7) as per your choice of input range within which you want to check the largest prime number & run the
	program. The time taken to calculate and print the output will depend on the range of input provided by the user.
	
## Features
		I have implemented the aforesaid algorithm alongwith some personal modifications so as to reduce the
	soutput time to every millisecond. 
	The first approach (sieve.c) uses the normal approach of the algorithm and it is capable to calculate prime numbers
	up to 1.3 billion and this approach is faster than the other one. But, it takes a lot more memory compared to
	segmented_sieve approach. The segemented_sieve approach consumes much less memory and it can calculate even up to
	more than 2 billion. It is bit slower than the first approach.
	
## Comparison
	 sieve.c
		Calculated number - 1299999983 (check screenshots)
		Time taken - 27.672s 
	 segemented_sieve.c
		1. Calculated number - 1299999983
		   Time taken - 34.907s
		   
		2. Calculated number - 1999999973
		   Time taken - 54.924s

		
	