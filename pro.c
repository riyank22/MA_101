#include <stdio.h>
#include <stdbool.h>

int m,n,i,j,x,y; //m,n board dimensions i,j for indexing, x,y user input 
char *p; //pointer
void array_manipulator(); //for clearing boxes
void gameon(); //game event handler

bool player=0;

int main(void)
{   printf("Enter dimensions: ");
    scanf("%d %d", &m, &n);

    char arr[m][n];

    p=&arr[0][0];

    for(i=0;i<m;i++) //assigning array the default look
    {
        for(j=0;j<n;j++)
        {
            *(p+i*n+j)=219;
        }
    }

    printf("Enter Coords:");
    scanf("%d %d", &x, &y); //taking input

    array_manipulator(x,y); //calling for clearing the boxes

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c ",*(p+i*n+j));
        }
        printf("\n");
    } //printing the result

    /*while(*(p+1)=="_"&&*(p+n+1)=='_')
    {
        gameon();
    }*/
}

void gameon()
{
    while(*(p))
    display();
    input();
    array_manipulator();
}

void array_manipulator()
{
    for(i=y-1;i<m && *(p+n*(i+1)+j)!='_';i++)
    {
        for(j=x-1;j<n && *(p+n*i+j+1)!='_';j++)
        {
            *(p+i*n+j)='_';
        }
    }
}