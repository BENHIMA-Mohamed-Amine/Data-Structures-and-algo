void imageCreation(int*** A, int M, int N, int O) {
    if(A == NULL)
        printf("A is null\n");
    A = (int***)malloc(M * sizeof(int**));
    if(A != NULL)
        printf("A is not null\n");

    if (A == NULL){
        fprintf(stderr, "Out of memory");
        exit(0);
    }

    for (int i = 0; i < M; i++){
        A[i] = (int**)malloc(N * sizeof(int*));

        if (A[i] == NULL){
            fprintf(stderr, "Out of memory");
            exit(0);
        }
        else{
            printf("A is not null again\n");
        }

        for (int j = 0; j < N; j++){
            A[i][j] = (int*)malloc(O * sizeof(int));
            if (A[i][j] == NULL){
                fprintf(stderr, "Out of memory");
                exit(0);
            }
            else{
            printf("A is not null again again\n");
            }
        }
    }
    printf("A alloucated success\n");





    // *image = (float**)malloc(w * sizeof(float*));
    // if (*image == NULL) {
    //     fprintf(stderr, "Out of memory");
    //     exit(0);
    // }

    // for (int i = 0; i < w; i++) {
    //     (*image)[i] = (float*)malloc(h * r * sizeof(float));
    //     if ((*image)[i] == NULL) {
    //         fprintf(stderr, "Out of memory");
    //         exit(0);
    //     }
    // }

    // printf("Image created successfully!\n");
}
