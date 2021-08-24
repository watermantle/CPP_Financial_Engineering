//	Header file contains two macro calls
//	PRINT1 will print the value of a
//	PRINT2 will print the value of b

#ifndef Defs_H	//	Check if Defs_h has been defined, if not define it.
#define Defs_H 
//	Define PRINT1 to print the variable a. We set type of a is int
#define PRINT1(a) printf("The value of a is %d\n", a)
//	Define PRINT2 to print the variable a and b. We set type of them is int
#define PRINT2(a, b) printf("The value of a is %d, b is %d\n", a, b)

#endif