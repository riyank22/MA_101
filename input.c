void input()
{
    printf("Enter the row and column number of the chocolate you want to eat\n");
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
            printf("You have given an invalid input\n");
            printf("Please give a valid input\n");
            goto label;
        }
        if(x==0 && y==0)
        {
            printf("You can not select the poisoned chocolate\n");
            printf("Please Select other value\n");
            goto label;
        }
        if(*(p+(x)+n*(y))=='_')
        {
            printf("\n\n%c\n\n", *(p+x+n*y));
            printf("That chocolate has already been selected\n");
            printf("Please Select other value\n");
            goto label;
        }

    array_manipulator(); //calling for clearing the boxes
}