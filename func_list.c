void list_number()
{
    struct Persons user;
    FILE *file = fopen(NUMBER_FILE, "r");
    if (!file) {
        printf("Error opening users file.\n");
       // return 0;
    }

    while(fscanf(file, "%s %s %s %s %s", user.person_name, user.person_address, user.mobile_num, user.email_address,
              user.relation) != EOF){
        if(feof(file)){
            continue;
        }
        printf("\33[92m\nName: \33[94m%s\33[0m \n\33[0m", user.person_name);
        printf("\33[92mAddress: \33[94m%s\33[0m\n\33[0m", user.person_address);
        printf("\33[92mNumber: \33[94m%s\33[0m\n\33[0m", user.mobile_num);
        printf("\33[92mEmail: \33[94m%s\33[0m\n\33[0m", user.email_address);
        printf("\33[92mRelation: \33[94m%s\33[0m\n\n\33[0m", user.relation);
    }
    fclose(file);
}
