#include<stdio.h>
void system();
int n;
void glob()
{
    printf("Enter the size of grid\n");
    scanf("%d",&n);
}
char a[40][40];
void inp()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           a[i][j]='X';
        }
    }
}
void print()
{
    system("cls");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("   %c   ",a[i][j]);
        }
        printf("\n\n\n");
    }
}
int check()
{
    if(a[0][1]=='_'&&a[1][0]=='_'&&a[1][1]=='_')
    {
        return 1;
    }
    return -1;
}
int main()
{
    glob();
    inp();
    print();
    int player=1;   
    while(1)
    {
        if(player%2==0)
        {
            player=2;
        }
        else
        {
            player=1;
        }
        printf("Player %d please enter the row number and column number of the chocolate you want to eat\n",player);
        int i,j;
        label:
        scanf("%d%d",&i,&j);
        i=i-1;
        j=j-1;
        if(i==0 && j==0)
        {
            printf("You can not select the poisoned chocolate\n");
            printf("Please Select other value\n");
            goto label;
        }
        if(a[i][j]=='_')
        {
            printf("That chocolate has already been selected\n");
            printf("Please Select other value\n");
            goto label;
        }
        for(int k=i;k<n;k++)
        {
            for(int l=j;l<n;l++)
            {
                a[k][l]='_';
            }
        }
        print();
        int c=check();
        if(c==1)
        {
            printf("Player %d is the winner\n",player);
            break;
        }
        player++;
    }
    return(0);
}