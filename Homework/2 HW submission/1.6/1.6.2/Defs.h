//Define two macros, MAX2(x, y), MAX3(x, y, z). The former returns the max of x, y. The later returns the max of x, y, and z
// Deinfe Defs_H if not exists
#ifndef Defs_H
#define Defs_H

#define MAX2(x, y) (x > y ? x : y) //Define MAX2 to compare x, y. Out put is the greater of the two
//Define MAX3 to find the greatest among x, y, z. Use MAX2 to find the max of x and y, then compare to z.
#define MAX3(x, y, z) (MAX2(x, y) > z ? MAX2(x, y) : z) 

#endif