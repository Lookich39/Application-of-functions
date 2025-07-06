#include <stdio.h>
#include <locale.h>

int strl(int **arr, int m, int n, int k){
    int cnt=0;
    for(int i=0;i<m;i=i+1){
            for(int j=0;j<n;j=j+1){
                if ((arr[i][j]) < 0){
                    cnt = cnt + 1;
                }
            }
            if (cnt == k){
                for(int j=0;j<n;j=j+1){
                    if ((arr[i][j]) >= 0){
                        arr[i][j] = k;
                    }
                }
            }
        cnt = 0;
    }
    return arr;
}
void out(int **arr, int m, int n){
    for(int i=0;i<m;i=i+1){
            for(int j=0;j<n;j=j+1){
                    printf("%d ", arr[i][j]);
            }
            printf("\n");
    }
}

int main(void){
    setlocale(LC_ALL, "Rus");
    int **m2=NULL; /* динамический массив вещественных чисел */
    int i,j,count, k, z=0;
    int n; /* размер массива */
    int m; /* количество добавляемых элементов */
    puts("Введите размеры массива: ");
    scanf("%d %d", &n, &m);
    puts("Введите число k: ");
    scanf("%d", &k);
    /* Начало ввода массива */
    if ((m2=(float**)malloc(m*sizeof(float*)))!=NULL)
    {
        i=0;
        count=1;
        while(i<m)
        {
            if ((m2[i]=(float*)malloc(n*sizeof(float)))!=NULL)
            {
                for(j=0;j<n;j=j+1)
                {
                    scanf("%d", &m2[i][j]);
                }
                i=i+1;
                count=count+1;

            }
            else
            {
                i=m;
                printf("ERROR at string allocation!\n");
                for(i=0;i<count;i=i+1)
                {
                    if (m2[i]!=NULL)
                    {
                        free(m2[i]);
                        m2[i]=NULL;
                    }
                }
            }
        }
    }
    /* Конец ввода массива */
    printf("\n");
    strl(m2, m, n, k);
    puts("\nNew №1 array: ");
    out(m2, m, n);
    puts("\nNew №2 array: ");
    int sum=0, cnt=0;
    for(int i=0;i<m;i=i+1){
        for(int j=0;j<n;j=j+1){
            sum = sum + m2[i][j];
        }
        if (sum != 0){
            cnt = cnt + 1;
        }
        sum = 0;
    }
    int A[n][cnt];
    for(int i=0;i<m;i=i+1){
        for(int j=0;j<n;j=j+1){
            sum = sum + m2[i][j];
        }
        if (sum != 0){
            for(int j=0;j<n;j=j+1){
            A[j][z] = m2[i][j];
            }
            z = z + 1;
        }
        sum = 0;
    }
    for(int i=0;i<n;i=i+1){
            for(int j=0;j<cnt;j=j+1){
                printf("%d ", A[i][j]);
            }
            printf("\n");
    }
    /* Начало очистки памяти */
    for(i=0;i<m;i=i+1)
    {
        if (m2[i]!=NULL)
        {
            free(m2[i]);
            m2[i]=NULL;
        }
    }
    free(m2);
    m2=NULL;
    /* Конец очистки */
    return 0;
}
