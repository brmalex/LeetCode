//Bruno Martins Alexandre, AED1 Turma T1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix
{
    struct matrix *right;
    struct matrix *down;
    int line;
    int collumn;
    float info;
} Matrix;

Matrix *matrix_create(void);
//Matrix *matrix_create(unsigned int m);

void matrix_setelem(Matrix *m, int infoLine, int infoCollumn, float info);
void matrix_print(Matrix *m);
void matrix_destroy(Matrix *m);
Matrix *matrix_createHead(int line, int collumn);
float matrix_getelem(Matrix *m, int infoLine, int infoCollumn);
Matrix *matrix_add(Matrix *m, Matrix *n);
void clear(void);
Matrix *matrix_multiply(Matrix *m, Matrix *n);
Matrix *matrix_transpose(Matrix *m);

int main()
{
    Matrix *A = matrix_create();
    matrix_print(A);
    Matrix *B = matrix_create();
    matrix_print(B);
    Matrix *C = matrix_add(A, B);
    matrix_print(C);
    matrix_destroy(C);
    C = matrix_multiply(A, B);
    matrix_print(C);
    matrix_destroy(C);
    C = matrix_transpose(A);
    matrix_print(C);
    matrix_destroy(C);
    matrix_destroy(A);
    matrix_destroy(B);

    /*srand(time(NULL));
    Matrix *A = matrix_create(400);
    Matrix *B = matrix_create(400);
    Matrix *C = matrix_add(A, B);
    matrix_destroy(C);
    C = matrix_multiply(A, B);
    matrix_destroy(C);
    C = matrix_transpose(A);
    matrix_destroy(C);
    matrix_destroy(A);
    matrix_destroy(B);*/
     
    /*float a[400][400], b[400][400], c[400][400];
    for (int i = 0; i < 400; i++)
    {
        for (int j = 0; j < 400; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    for (int i = 0; i < 400; i++) 
    {
        for (int j = 0; j < 400; j++) 
        {
            c[i][j] = 0;
            for (int k = 0; k < 400; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < 400; ++i)
    {
        for (int j = 0; j < 400; ++j)
        {
            c[j][i] = a[i][j];
        }
    }*/
    
    return 0;
}

Matrix *matrix_create(void)
{
    int line, collumn, infoLine, infoCollumn;
    float info;
    Matrix *ret;
    printf("Numero de linhas e colunas, respectivamente:");
    if (!scanf("%d %d", &line, &collumn))
    {
        printf("Entrada invalida\n");
        return NULL;
    }
    clear();
    ret = matrix_createHead(line, collumn);
    printf("Triplas ou uma letra para sair:\n");
    while (scanf("%d %d %f", &infoLine, &infoCollumn, &info))
    {
        matrix_setelem(ret, infoLine, infoCollumn, info);
    }
    clear();
    return ret;
}

/*Matrix *matrix_create(unsigned int m)
{
    Matrix *ret;
    ret = matrix_createHead(m, m);
    for (int i = 0; i < m; i++)
    {
        matrix_setelem(ret, rand() % m, rand() % m, rand() % 10);
    }
    return ret;
}*/

Matrix *matrix_createHead(int line, int collumn)
{
    if (collumn < 0 || line < 0)
    {
        printf("Numero de colunas ou linhas invalidas");
        return NULL;
    }
    Matrix *ret;
    Matrix *aux;
    Matrix *temp;
    ret = (Matrix *)malloc(sizeof(Matrix));
    ret->down = ret;
    ret->right = ret;
    ret->collumn = -1;
    ret->line = -1;
    aux = ret;
    for (int i = 0; i < collumn; i++)
    {
        temp = (Matrix *)malloc(sizeof(Matrix));
        temp->collumn = i;
        temp->line = -1;
        temp->right = NULL;
        temp->down = temp;
        aux->right = temp;
        aux = temp;
    }
    temp->right = ret;
    aux = ret;
    for (int j = 0; j < line; j++)
    {
        temp = (Matrix *)malloc(sizeof(Matrix));
        temp->collumn = -1;
        temp->line = j;
        temp->right = temp;
        temp->down = NULL;
        aux->down = temp;
        aux = temp;
    }
    temp->down = ret;

    return ret;
}

void clear(void)
{
    while (getchar() != '\n')
        ;
}

void matrix_setelem(Matrix *m, int infoLine, int infoCollumn, float info)
{
    if (m != NULL)
    {
        Matrix *temp, *collumn, *line;
        collumn = m;
        line = m;
        if (info == 0)
        {
            return;
        }
        while (collumn->right->collumn != -1)
        {
            if (collumn->collumn == infoCollumn)
            {
                break;
            }
            collumn = collumn->right;
        }
        if (collumn->collumn != infoCollumn && collumn->right->collumn == -1)
        {
            printf("Posicao fora do tamanho da matrix\n");
            return;
        }
        while (collumn->down->line < infoLine && collumn->down->line != -1)
        {
            collumn = collumn->down;
        }

        while (line->down->line != -1)
        {
            if (line->line == infoLine)
            {
                break;
            }
            line = line->down;
        }
        if (line->line != infoLine && line->down->line == -1)
        {
            printf("Posicao fora do tamanho da matrix\n");
            return;
        }
        while (line->right->collumn < infoCollumn && line->right->collumn != -1)
        {
            line = line->right;
        }
        if (collumn->down->line == infoLine &&
            line->right->collumn == infoCollumn)
        {
            collumn->down->info = info;
        }
        else
        {
            temp = (Matrix *)malloc(sizeof(Matrix));
            temp->collumn = infoCollumn;
            temp->line = infoLine;
            temp->info = info;

            temp->down = collumn->down;
            collumn->down = temp;
            temp->right = line->right;
            line->right = temp;
        }
    }
}

void matrix_print(Matrix *m)
{
    if (m != NULL)
    {
        m = m->down;
        while (m->line != -1)
        {
            m = m->right;
            while (m->collumn != -1)
            {
                printf("%.2f ", m->info);
                m = m->right;
            }
            if (m->right->collumn != -1)
            {
                printf("\n");
            }
            m = m->down;
        }
    }
}

void matrix_destroy(Matrix *m)
{
    if (m != NULL)
    {
        if (m->right->collumn != -1)
        {
            matrix_destroy(m->right);
        }
        if (m->down->line != -1 && m->collumn == -1)
        {
            matrix_destroy(m->down);
        }
        free(m);
    }
}

float matrix_getelem(Matrix *m, int infoLine, int infoCollumn)
{
    if (m == NULL)
    {
        printf("Matrix invalida");
        return 0;
    }
    for (int i = 0; i <= infoCollumn; i++)
    {
        if (m->collumn == infoCollumn)
        {
            break;
        }
        m = m->right;
    }
    if (m->collumn != infoCollumn)
    {
        return 0.0;
    }
    for (int i = 0; i <= infoLine; i++)
    {
        if (m->line == infoLine)
        {
            break;
        }
        m = m->down;
    }
    if (m->line != infoLine)
    {
        return 0.0;
    }
    return m->info;
}

Matrix *matrix_add(Matrix *m, Matrix *n)
{
    if (m == NULL || n == NULL)
    {
        printf("Matrix invalida\n");
        return NULL;
    }
    Matrix *ret;
    int collumn, line;
    while (m->right->collumn != -1 || n->right->collumn != -1)
    {
        if (m->right->collumn != -1)
        {
            m = m->right;
        }
        if (n->right->collumn != -1)
        {
            n = n->right;
        }
    }
    if (m->collumn != n->collumn)
    {
        printf("Nao e possivel somar\n");
        return NULL;
    }
    else
    {
        collumn = n->collumn + 1;
    }
    m = m->right;
    n = n->right;
    while (m->down->line != -1 || n->down->line != -1)
    {
        if (m->down->line != -1)
        {
            m = m->down;
        }
        if (n->down->line != -1)
        {
            n = n->down;
        }
    }
    if (m->line != n->line)
    {
        printf("Nao e possivel somar\n");
        return NULL;
    }
    else
    {
        line = n->line + 1;
    }
    ret = matrix_createHead(line, collumn);
    m = m->down;
    n = n->down;

    float temp;
    m = m->down;
    while (m->line != -1)
    {
        m = m->right;
        while (m->collumn != -1)
        {
            matrix_setelem(ret, m->line, m->collumn, m->info);
            m = m->right;
        }
        m = m->down;
    }
    n = n->down;
    while (n->line != -1)
    {
        n = n->right;
        while (n->collumn != -1)
        {
            temp = matrix_getelem(ret, n->line, n->collumn);
            matrix_setelem(ret, n->line, n->collumn, n->info + temp);
            n = n->right;
        }
        n = n->down;
    }
    return ret;
}

Matrix *matrix_multiply(Matrix *m, Matrix *n)
{
    if (m == NULL || n == NULL)
    {
        printf("Matrix invalida\n");
        return NULL;
    }
    int collumn, line, temp, cont;
    Matrix *ret;
    while (m->right->collumn != -1)
    {
        m = m->right;
    }
    collumn = m->collumn + 1;
    m = m->right;
    while (n->down->line != -1)
    {
        n = n->down;
    }
    line = n->line + 1;
    n = n->down;

    if (collumn != line)
    {
        printf("Multiplicao nao e possivel\n");
        return NULL;
    }
    else
    {
        cont = collumn;
        while (n->right->collumn != -1)
        {
            n = n->right;
        }
        collumn = n->collumn + 1;
        n = n->right;
        while (m->down->line != -1)
        {
            m = m->down;
        }
        line = m->line + 1;
        m = m->down;
        ret = matrix_createHead(line, collumn);
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < collumn; j++)
            {
                temp = 0;
                for (int k = 0; k < cont; k++)
                {
                    temp = matrix_getelem(m, i, k) * matrix_getelem(n, k, j) + temp;
                }
                matrix_setelem(ret, i, j, temp);
            }
        }
        return ret;
    }
}

Matrix *matrix_transpose(Matrix *m)
{
    if (m == NULL)
    {
        printf("Matrix invalida\n");
        return NULL;
    }
    Matrix *ret;
    int collumn, line, temp;
    while (m->right->collumn != -1)
    {
        m = m->right;
    }
    collumn = m->collumn + 1;
    m = m->right;
    while (m->down->line != -1)
    {
        m = m->down;
    }
    line = m->line + 1;
    m = m->down;
    ret = matrix_createHead(collumn, line);
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < collumn; j++)
        {
            temp = matrix_getelem(m, i, j);
            matrix_setelem(ret, j, i, temp);
        }
    }
    return ret;
}
