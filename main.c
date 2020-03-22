/*
 *for leetcode 118 yanghuisanjiao 1
 *
*/
#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i = 0;
    int j = 0;
    int **new_array = NULL;

    if (numRows == 0) {
        *returnSize = 0;
        return NULL;
    }

    new_array = (int **)malloc(numRows * sizeof(int *));
    *returnColumnSizes = (int *)malloc(numRows * sizeof(int));
    *returnSize = numRows;
    for (i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        new_array[i] = (int *)malloc(sizeof(int) * (i + 1));
        for (j = 0; j < (*returnColumnSizes)[i]; j++) {
            if (j == 0 || j == (*returnColumnSizes)[i] - 1) {
                new_array[i][j] = 1;
                continue;
            }
            new_array[i][j] = new_array[i - 1][j - 1] + new_array[i - 1][j];
        }
    }

    return new_array;
}

int main()
{
    int ret = 0;
    int i = 0;
    int j = 0;
    int return_size = 0;
    int *returnColumnSizes = NULL;
    int **new_array = NULL;

    new_array = generate(10, &return_size, &returnColumnSizes);

    for (i = 0; i < return_size; i++) {
        for (j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", new_array[i][j]);
        }
        printf("\n");
    }

    free(returnColumnSizes);
    for (i = 0; i < return_size; i++) {
        free(new_array[i]);
    }

    return ret;
}

