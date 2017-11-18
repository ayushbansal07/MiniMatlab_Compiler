Specific cases of compiler:

Handling of matrices:
Every Matrix definition should be accompanied by [][] (Matrix m[x][y]). Here x and y should be integers and have initial values also (dynamic allocation not supported).
Matrix addition, subtraction and assignment is only possible when the dimension of all the involved matrices are same. Matrix Multiplication is possible only when dimension of 2 matrices is m*n & n*x (dimension of resultant matrix would be m*x). Matrix division and modulus is not supported. Only == and != operators are allowed as conditional operators for matrices, relational operators such as <, >, et.c are not supported for matrices. Matrix transpose is also supported as expected.

Bitwise Operators:
Bitwise operators (|,&,etc.) are only operable on Integer operands. Throws error in other cases. NOTE: matrix values (eg. A[1][2]) are double and hence bitwise operators don’t apply to them.

Implicit Boolean Conversions:
There is a provision to convert expressions which are of non-bool into bool type by converting them to condition as expression == 0.
