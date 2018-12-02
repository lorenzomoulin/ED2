
enc:
	gcc -Wall key.c encrypt.c -o encrypt

bruteforce:
	gcc -Wall key.c subsets.c -o brute

dec:
	gcc -Wall key.c symbol_table.c -o decrypt -lm

clean:
	rm -f *.o a.out encrypt gmon.out prof
