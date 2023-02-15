#include <stdio.h>
#include <stdbool.h>

int m,n,i,j,x,y;;
char *p;
void array_manipulator();
void gameon();
bool player=0;

int main(void)
{   printf("Enter dimensions: ");
    scanf("%d %d", &m, &n);
    char arr[m][n];
    p=&arr[0][0];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            *(p+i*n+j)='*';
        }
    }


    printf("Enter Coords:");
    scanf("%d %d", &x, &y);

    array_manipulator(x,y);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c ",*(p+i*n+j));
        }
        printf("\n");
    }

    /*while(*(p+1)=="_"&&*(p+n+1)=='_')
    {
        gameon();
    }*/
}

void gameon()
{
    //input();
    //array_manipulator();
    //display();
}

void array_manipulator()
{
    for(i=y-1;i<m&&*(p+n*(i+1)+j)!='_';i++)
    {
        for(j=x-1;j<n&&*(p+n*i+j+1)!='_';j++)
        {
            *(p+i*n+j)='_';
        }
    }
}