void addmobile()
{
    FILE *file = fopen(NUMBER_FILE,"a");//declare a file in append (a) mode
    if (!file)
    {
        printf("Error opening users file.\n");
        return;
    }
    struct Persons newperson;
    printf("\33[92mEnter your nick name.\n\33[0m");
    scanf("%s",newperson.person_name);
    printf("\33[92mEnter your address.\n\33[0m");
    scanf("%s",newperson.person_address);
    printf("\33[92mEnter your mobile number.\n\33[0m");
    scanf("%s",newperson.mobile_num);
    printf("\33[92mEnter your email address.\n\33[0m");
    scanf("%s",newperson.email_address);
    printf("\33[92mRelation: \n\33[0m");
    scanf("%s",newperson.relation);

    fprintf(file, "%s %s %s %s %s\n", newperson.person_name, newperson.person_address, newperson.mobile_num, newperson.email_address, newperson.relation);
    fclose(file);
    printf("\33[94mNumber is added successfully!\n\33[0m");
}
