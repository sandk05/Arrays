# Print all paths from top left to bottom right in a matrix with eight moves allowed

The algorithm is a simple recursive algorithm, from each cell first print all paths by going down and then print all paths by going up then print all paths by going up then print all paths by going right. Do this recursively for each cell encountered. There we will use visited matrix for it will not repeat the same path which already traversed.

**Input :**  

```mathematica
1 2 3 
4 5 6
```
**Output :**  
```mathematica
Paths are
Size is 12 -> 1 2 3 6
Size is 14 -> 1 2 5 6
Size is 16 -> 1 4 5 6
Size is 21 -> 1 4 5 2 3 6

Shortest Path is
Size is 12 -> 1 2 3 6
```
**Input :**

```mathematica
1 2 3
4 5 6
7 8 9
```
**Output :**

```mathematica
Paths are
Size is 21 -> 1 2 3 6 9
Size is 23 -> 1 2 5 6 9
Size is 25 -> 1 2 5 8 9
Size is 25 -> 1 4 5 6 9
Size is 27 -> 1 4 5 8 9
Size is 29 -> 1 4 7 8 9
Size is 30 -> 1 4 5 2 3 6 9
Size is 34 -> 1 2 3 6 5 8 9
Size is 36 -> 1 2 5 4 7 8 9
Size is 40 -> 1 4 7 8 5 6 9
Size is 45 -> 1 2 3 6 5 4 7 8 9
Size is 45 -> 1 4 7 8 5 2 3 6 9

Shortest Path is
Size is 21 -> 1 2 3 6 9
```