#include <stdio.h>
#define MAX 100

int createSparseMatrix(int matrix[MAX][MAX], int rows, int cols, int sparse[MAX][3]) {
    int k = 1; 
    sparse[0][0] = rows;    
    sparse[0][1] = cols;   
    sparse[0][2] = 0;       

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;          
                sparse[k][1] = j;          
                sparse[k][2] = matrix[i][j]; 
                sparse[0][2]++;            
                k++;
            }
        }
    }
    return k; 
}

void displaySparseMatrix(int sparse[MAX][3]) {
    int nonZeroElements = sparse[0][2];

    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= nonZeroElements; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

void fastTransposeSparseMatrix(int original[MAX][3], int transpose[MAX][3]) {
    int rowTerms[MAX] = {0}, startingPos[MAX];
    int numRows = original[0][0]; 
    int numCols = original[0][1]; 
    int numNonZero = original[0][2]; 

    transpose[0][0] = numCols;  
    transpose[0][1] = numRows;  
    transpose[0][2] = numNonZero;

    for (int i = 1; i <= numNonZero; i++) {
        rowTerms[original[i][1]]++;
    }

    startingPos[0] = 1; 
    for (int i = 1; i < numCols; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    for (int i = 1; i <= numNonZero; i++) {
        int colIndex = original[i][1];         
        int position = startingPos[colIndex];   
        transpose[position][0] = original[i][1]; 
        transpose[position][1] = original[i][0]; 
        transpose[position][2] = original[i][2]; 
        startingPos[colIndex]++;                
    }
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX];
    int sparse[MAX][3], transpose[MAX][3];


    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int size = createSparseMatrix(matrix, rows, cols, sparse);

  
    printf("\nSparse Matrix:\n");
    displaySparseMatrix(sparse);

    fastTransposeSparseMatrix(sparse, transpose);

    printf("\nFast Transposed Sparse Matrix:\n");
    displaySparseMatrix(transpose);

    return 0;
}



 
//  0  0  0  0  3  0
//  0  0  9  0  4  0
//  0  8  0  0  0  7
//  2  0  0  0  0  0
//  0  0  0  0  0  0