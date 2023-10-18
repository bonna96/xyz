void deletenumber()
{
    struct Persons user;
    char numb[MAX_SIZE];
    FILE *file = fopen(NUMBER_FILE, "r");
    if (!file) {
        printf("Error opening users file.\n");
        //return 0;
    }
    FILE *file2= fopen(TEMPOR,"w");
    if (!file2) {
        printf("Error opening users file.\n");
        fclose(file);
        //return 0;
    }

    printf("\33[91mEnter the number you want to delete\n\33[0m");
    scanf("%s",numb);
    while(fscanf(file, "%s %s %s %s %s", user.person_name, user.person_address, user.mobile_num, user.email_address,
              user.relation) != EOF){
        if (feof(file)) {
            continue;
        }
        if(strcmp(numb,user.mobile_num)==0){
            continue;
        }
        fprintf(file2,"%s %s %s %s %s\n", user.person_name, user.person_address, user.mobile_num, user.email_address,
                user.relation);
    }
    fclose(file);
    fclose(file2);
    remove(NUMBER_FILE);
    rename(TEMPOR,NUMBER_FILE);
    file=fopen(NUMBER_FILE,"r");
    if (!file) {
        printf("Error opening users file.\n");
        //return 0;
    }
    printf("\33[93m\nRecords after deletion\n\33[0m");
    while(fscanf(file, "%s %s %s %s %s", user.person_name, user.person_address, user.mobile_num, user.email_address,
              user.relation) != EOF){
        if(feof(file)){
            continue;
        }
        printf("\33[92m\nWelcome\33[0m \33[94m%s\33[0m \33[92m!\33[0m\n", user.person_name);
        printf("\33[92mAddress: \33[94m%s\33[0m\n", user.person_address);
        printf("\33[92mNumber: \33[94m%s\33[0m\n", user.mobile_num);
        printf("\33[92mEmail: \33[94m%s\33[0m\n", user.email_address);
        printf("\33[92mRelation: \33[94m%s\n\n\33[0m", user.relation);
    }
    fclose(file);
    return 0;
}
