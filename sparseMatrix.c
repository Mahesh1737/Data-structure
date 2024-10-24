#include <stdio.h>

void main()
{
    int row, col, t = 1, i, j, a[10][10], new[10][3], no = 0;

    printf("Enter the no of rows: ");
    scanf("%d", &row);

    printf("Enter the no of cols: ");
    scanf("%d", &col);

    printf("Enter the matrix: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("First matrix: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
    
    //Counting the non-zero numbers
    for (i=0;i<row;i++)
    {
        for (j=0;j<col;j++){
            if(a[i][j]!=0){
                no=no+1;
            }
        }
    }
    new[0][0] = row;
    new[0][1] = col;
    new[0][2] = no;
   
    for (i=0;i<row;i++)
    {
        for (j=0;j<col;j++){
            if(a[i][j]!=0){
                new[t][0]=i;
                new[t][1]=j;
                new[t][2]=a[i][j];
                t++;
            }
        }
    }
    printf("New matrix :\n");

    for(i=0;i<no+1;i++){
        for(j=0;j<3;j++){
            printf(" %d ",new[i][j]);
        }
        printf("\n");
    }
}


// output :

// Enter the no of rows: 3
// Enter the no of cols: 3
// Enter the matrix: 
// 0 0 3
// 1 0 3
// 0 0 5
// First matrix: 
//  0  0  3 
//  1  0  3 
//  0  0  5 
// New matrix :
//  3  3  4 
//  0  2  3 
//  1  0  1 
//  1  2  3 
//  2  2  5 
