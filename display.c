void print_display(int m, int n, int *board, int *chomped_blocks, int num_chomped_blocks) {
    printf("\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int chomped = 0;
            for (int k = 0; k < num_chomped_blocks; k++) {
                if (*(chomped_blocks + 2*k) == i && *(chomped_blocks + 2*k + 1) == j) {
                    chomped = 1;
                    break;
                }
            }
            if (chomped) {
                printf("   ");
            } else if (*(board + i*n + j) == 0) {
                printf(" * ");
            } else {
                printf(" o ");
            }
        }
        printf("\n");
    }
    printf("\n");
}