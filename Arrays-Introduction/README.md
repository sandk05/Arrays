# Arrays Introduction

An array is a series of elements of the same type placed in contiguous memory locations that can be
individually referenced by adding an index to a unique identifier.
Declaration:

```
int arr[10]; //Declares an array named arr of size 10, i.e; you can store 10 integers.
```

Accessing elements of an array:

```
Indexing in arrays starts from 0.So the first element is stored at arr[0],the second element at arr[1]...arr[9]
```
You'll be given an array of **_N_** integers and you have to print the integers in the reverse order.

**Input Format**

The first line of the input contains **_N_** ,where  **_N_** is the number of integers.The next line contains **_N_** integers
separated by a space.

**Constraints**

- **1 <= N <= 1000**
- **1 <= A<sub>_i_</sub> <= 10000**, where A<sub>_i_</sub>  is the _i_<sup>_th_</sup> integer in the array.

**Output Format**

Print the **_N_** integers of the array in the reverse order in a single line separated by a space.

**Sample Input**

```
4
1 4 3 2
```
**Sample Output**

```
2 3 4 1
```

