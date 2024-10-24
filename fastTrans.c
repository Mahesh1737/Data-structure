#include <stdio.h>

int main()
{
	int rows, spcount, cols, i, j, count, t=0, l, a[10][10], s[10][10], st[10][10], feqcnt[10], rowstpos[10], fast[10][10];

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
			}
		}
	}
	
	
    s[0][0] = rows;
    s[0][1] = cols;
    s[0][2] = count-1;
	
	printf("Sparse matrix : \n");
    for (i=0;i<count;i++){
        for (j=0;j<3;j++){
            printf(" %d ",s[i][j]);
        }
        printf("\n");
    }
    
    int total[a[0][1]], index[a[0][1]+1];
    for (i-0;i<a[0][1];i++){
    	total[i]=0;
	}
	
	for (i=1;i<=a[0][2];i++){
		col=a[i][1];
		total[col]++;
	}
	
	index[0]=1;
	for (i=1;i<=a[0][1];i++){
		index[i]=index[i-1]+total[i-1]
	}
	
	fast[0][0] = a[0][1];
	fast[0][1] = a[0][0];
    fast[0][2] = a[0][2];
    
    for (i=1;i<=a[0][2];i++){
    	cols = a[i][1];
    	
	}
    
    
}
