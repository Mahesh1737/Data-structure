#include <stdio.h>
#include <conio.h>

void main(){
    int rows, spcount, cols, i, j, count, t=0, l, a[10][10], s[10][10], st[10][10];

    printf("Enter the no of rows :");
    scanf("%d",&rows);
    printf("Enter the no of cols :");
    scanf("%d",&cols);

    printf("Enter the matrix elements : \n");
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            printf("Enter the element at %d row and %d column : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("Original matrix : \n");
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }

    count=1;
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            if(a[i][j]!=0){
                s[count][0] = i;
                s[count][1] = j;
                s[count][2] = a[i][j];

                count++;

                if(j>t){
                    t=j;
                }
            }
        }
    }

    s[0][0] = rows;
    s[0][1] = cols;
    s[0][2] = count-1;

    printf("Sparse matrix \n");
    for (i=0;i<count;i++){
        printf("\n");
        for (j=0;j<3;j++){
            printf(" %d ",s[i][j]);
        }
    }
    printf("\n t: %d", t);

    spcount=1;
    l=count-1;

    for (i=0;i<=t;i++){
        count=1;
        for (j=0;j<l;j++){
            if(s[count][1] == i){
                st[count][1] = s[count][0];
                st[count][0] = s[count][1];
                st[count][2] = s[count][2];

                spcount++;
                count++;
            }
            else{
                count++;
            }
        }
    }

    st[0][0] = s[0][1];
    st[0][1] = s[0][0];
    st[0][2] = s[0][2];

    printf("\ntranspose of the sparse matrix : \n");

    for (i=0; i<spcount; i++){
        printf("\n");
        for (j=0;j<3;j++){
            printf(" %d ", st[i][j]);
        }
    }
    getch();

}

/*

output:-


Enter the no of rows :5
Enter the no of cols :6
Enter the matrix elements : 
Enter the element at 0 row and 0 column : 0
Enter the element at 0 row and 1 column : 0
Enter the element at 0 row and 2 column : 0
Enter the element at 0 row and 3 column : 0
Enter the element at 0 row and 4 column : 3
Enter the element at 0 row and 5 column : 0
Enter the element at 1 row and 0 column : 0
Enter the element at 1 row and 1 column : 0
Enter the element at 1 row and 2 column : 9
Enter the element at 1 row and 3 column : 0
Enter the element at 1 row and 4 column : 4
Enter the element at 1 row and 5 column : 0
Enter the element at 2 row and 0 column : 0
Enter the element at 2 row and 1 column : 8
Enter the element at 2 row and 2 column : 0
Enter the element at 2 row and 3 column : 0
Enter the element at 2 row and 4 column : 0
Enter the element at 2 row and 5 column : 7
Enter the element at 3 row and 0 column : 2
Enter the element at 3 row and 1 column : 0
Enter the element at 3 row and 2 column : 0
Enter the element at 3 row and 3 column : 0
Enter the element at 3 row and 4 column : 0
Enter the element at 3 row and 5 column : 0
Enter the element at 4 row and 0 column : 0
Enter the element at 4 row and 1 column : 0
Enter the element at 4 row and 2 column : 0
Enter the element at 4 row and 3 column : 0
Enter the element at 4 row and 4 column : 0
Enter the element at 4 row and 5 column : 0
Original matrix :
 0  0  0  0  3  0
 0  0  9  0  4  0
 0  8  0  0  0  7
 2  0  0  0  0  0
 0  0  0  0  0  0
Sparse matrix

 5  6  6
 0  4  3
 1  2  9
 1  4  4
 2  1  8
 2  5  7
 3  0  2
 t: 5
transpose of the sparse matrix :

 6  5  6
 4  0  3
 2  1  9
 4  1  4
 1  2  8
 5  2  7
 0  3  2

 */