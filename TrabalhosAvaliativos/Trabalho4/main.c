/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int ** ret = (int **)malloc(sizeof(int *));
    int retSize = 0;
    *ret = (int*) malloc(sizeof(int)*2);
    ret[0][0] = intervals[0][0];
    ret[0][1] = intervals[0][1];

    for(int i = 1; i <= intervalsSize; i++){
        for(int j = 0; j < retSize; j++){
            if(intervals[i][0] > ret[j][1]){
                retSize++;
                ret = realloc(ret, sizeof(int *)*retSize+1);
                ret[retSize] = (int*) malloc(sizeof(int)*2);
                ret[retSize][0] = intervals[i][0];
                ret[retSize][1] = intervals[i][1];
            }
            else{

            }
        }
    }
    return ret;
}

//Eu faria a continuação desse programa, usando o else para alterar os limites que ja adicionei; depois outro loop no retorno para retirar repetidos até não sobrar;
