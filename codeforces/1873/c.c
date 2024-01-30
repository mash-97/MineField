#include <stdio.h>

const int n=10;
char rings[10][11];



int totalPoint(int r)
{
    if(r>5)
        return 0;

    int rcount = 0;
    int x=r-1, y=n-r;

    for(int i=x+1; i<y; i++)
    {
        rcount += (rings[x][i]=='X');
        rcount += (rings[i][x]=='X');
        rcount += (rings[y][i]=='X');
        rcount += (rings[i][y]=='X');
    }
    rcount += (rings[x][y]=='X');
    rcount += (rings[y][x]=='X');
    rcount += (rings[y][y]=='X');
    rcount += (rings[x][x]=='X');

    return (rcount*r)+totalPoint(r+1);
}
//
//int totalPoint2(int R, int *N, int ***A)
//{
//    if(R>5)
//        return 0;
//
//    int rcount = 0;
//    int x=R-1, y=*N-R;
//
//    for(int i=x+1; i<y; i++)
//    {
//        rcount += (*((*A+x)+i)=='X'); //*((*A+x)+i)=='X'
//        rcount += (*((*A+i)+x)=='X');
//        rcount += (*((*A+y)+i)=='X');
//        rcount += (*((*A+i)+y)=='X');
//    }
//    rcount += (*((A*+x)+y))=='X');
//    rcount += (*((A*+y)+x)=='X');
//    rcount += (*((A*+y)+y)=='X');
//    rcount += (*((A*+x)+x)=='X');
//
//    return (rcount*R)+totalPoint(R+1, N, A);
//}

//int main()
//{
//    int t;
//    scanf("%d", &t);
//    while(t--)
//    {
//        int array[n][n];
//        int ai=0;
//        for(int i=0; i<n; i++)
//        {
//            scanf(" %[^\n]", rings[i]);
//            for(int j=0; j<n; j++)
//                array[ai][j] = rings[i][j];
//        }
//
//
//        printf("%d\n", totalPoint(1));
//        printf("\n%d\n", totalPoint2(1, &n, &array))
//    }
//    return 0;
//}

void mulValuesWith(int v, int s, int *A[][s])
{
    for(int i=0; i<s; i++)
    {
        for(int j=0; j<s; j++)
            *(*(*A+i)+j) *= v;
    }
}
int main()
{
    int l;
    scanf("%d", &l);

    int array[l][l];
    printf("%p(%d)\n", array, (int)sizeof(array));
    printf("rows addresses:\n");
    for(int i=0; i<l; i++)
        printf("%p(%d):&%p(%d)%c", array[i], (int)sizeof(array[i]), &array[i], (int)sizeof(&array[i]), '\n');
    printf("\n");

    for(int i=0; i<l; i++)
    {
        for(int j=0; j<l; j++)
            scanf("%d", &array[i][j]);
    }

    for(int i=0; i<l; i++)
    {
        for(int j=0; j<l; j++)
            printf("%d(%d):%p(%d) ", array[i][j], (int)sizeof(array[i][j]), &array[i][j], (int)sizeof(&array[i][j]));
        printf("\n");
    }

    mulValuesWith(5, l, &array);
    printf("\n");
    for(int i=0; i<l; i++)
    {
        printf("%p\t", array+i);
        for(int j=0; j<l; j++)
            printf("%d(%d):%p(%d) ", *(*(array+i)+j), (int)sizeof(*(*(array+i)+j)), (*(array+i)+j), (int)sizeof((*(array+i)+j)));
        printf("\n");
    }
}
