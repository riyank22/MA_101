void display()
{
    printf("\n");

    // Print the column numbers
    printf("   ");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", j+1);
    }
    printf("\n");

    // Print the rows
    for (int i = 0; i < m; i++)
    {
        printf("%2d", i+1);
        for (int j = 0; j < n; j++)
        {
            printf(" %c", *(p+i*n+j));
        }
        printf("\n");
    }
}