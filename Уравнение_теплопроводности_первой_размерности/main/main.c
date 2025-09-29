#include <stdio.h>
#include <stdlib.h>

#define n 1000
#define N 100
#define del_t 0.001

int main(void)
{
    int a,b;
    double k,v_a,v_b;

    printf("Введите a : ");scanf("%d",&a);printf("\n");
    printf("Введите b : ");scanf("%d",&b);printf("\n");
    printf("Введите ко-т k : ");scanf("%lf",&k);printf("\n");
    printf("Введите гран. усл. v_a : ");scanf("%lf",&v_a);printf("\n");
    printf("Введите гран. усл. v_b : ");scanf("%lf",&v_b);printf("\n");

    double prev_T[N + 1],next_T[N + 1];
    double h = (double)(b - a)/ N;
    double temp = (k * del_t) / (h * h);
    for(int i = 0;i < N;i++)
        prev_T[i] = v_a;
    prev_T[N] = v_b;

    for(int w = 0;w < n;w++)
    {
        for(int j = 1;j < N;j++)
        {
            next_T[j] = prev_T[j] + temp * (prev_T[j + 1] - 2 * prev_T[j] + prev_T[j - 1]);
        }
        next_T[0] = v_a;next_T[N] = v_b;
        for(int j = 0;j < N + 1;j++)
        {
            prev_T[j] = next_T[j];
        }
    }
    FILE *file = fopen("output.txt","w");
    for(int i = 0;i < N + 1;i++)
    {
        printf("Значение температуры в точке Ti : %lf\n",next_T[i]);
        fprintf(file,"%lf ",next_T[i]);

    }

    fclose(file);
    return 0;
}
