#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>

void array_manipulator(); //for clearing boxes
void gameon(); //game event handler
void input();
void check();
void display();
bool turn();

int m,n,i,j,x,y; //m,n board dimensions i,j for indexing, x,y user input 
char *p; //pointer
bool player=0;

int main(void)
{   printf("Enter dimensions (r,c): ");
    scanf("%d %d", &n, &m);

    char arr[m][n];

    p=&arr[0][0];

    for(i=0;i<m;i++) //assigning array the default look
    {
        for(j=0;j<n;j++)
        {
            *(p+i*n+j)=219;
        }
    }

    system("cls");

    gameon();

    display();

    printf("\n\nPlayer %d has lost the game.", player+1);
    
    
}

void gameon()
{
    while(*(p+1)!='_'||*(p+n)!='_')
    {
        display();
        player=turn();
        check();
        system("cls");
    }
}

bool turn()
{
    if(player)
    {
        printf("\n\nPlayer 2's turn:\n");
        return(0);
    }

    else
    {
        printf("\n\nPlayer 1's turn:\n");
        return(1);
    }
}

void input()
{
    printf("\nEnter the coordinates of the chocolate square you want to eat (r,c): ");
    scanf("%d %d",&x, &y);
}

void check()
{
    label:
    input();

    x--;
    y--;

        if(x>m || y>n || x<0 || y<0)
        {
            printf("\n\nYou have given an invalid input.\n");
            printf("Please give a valid input: \n");
            goto label;
        }
        if(x==0 && y==0)
        {
            printf("\n\nYou can not select the poisoned chocolate\n");
            printf("\nPlease Select other value\n");
            goto label;
        }
        if(*(p+y+n*x)=='_')
        {
            printf("\n\nThat chocolate has already been selected\n");
            printf("\nPlease Select other value\n");
            goto label;
        }

    array_manipulator(); //calling for clearing the boxes
}

void array_manipulator()
{
    for(i=x;i<m;i++)
    {
        for(j=y;j<n;j++)
        {
            *(p+i*n+j)='_';
        }
    }
}

void display()
{
    printf("\n");

    // Print the column numbers
    printf("C->");
    for (int j = 0; j < n; j++)
    {
        printf(" %2d  ", j+1);
    }
    printf("\n\n");

    // Print the rows
    for (int i = 0; i < m; i++)
    {
        printf("%2d ", i+1);
        for (int j = 0; j < n; j++)
        {
            printf("  %c  ", *(p+i*n+j));
        }
        printf("%2d ", i+1);
        printf("\n\n");
    }

    printf("   ");
    for (int j = 0; j < n; j++)
    {
        printf(" %2d  ", j+1);
    }
}