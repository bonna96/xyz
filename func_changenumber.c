void changenumber(int userIndex)
{
    if(userIndex >= 0 && userIndex <= MAX_USERS)
    {
        FILE *file = fopen(NUMBER_FILE, "r+");
        if(!file)
        {
            printf("Error opening users file.\n");
            return;
        }
        struct Persons user;
        int index = 0;
        while(fscanf(file, "%s %s %s %s %s", user.person_name, user.person_address, user.mobile_num, user.email_address,
                     user.relation) != EOF)
        {
            if(index == userIndex)
            {
                printf("\33[96mEnter new number: \33[0m");
                scanf("%s", user.mobile_num);
                fseek(file, index * (MAX_SIZE + MAX_SIZE + 1), SEEK_SET);
                /* This represents the number of bytes that the file pointer needs to be moved from the position
                 * specified by the location parameter. If the value of offset is positive, the file pointer will move forward in the file,
                 * and if it is negative, the file pointer will move backward from the given position.*/
                fprintf(file, "%s %s %s %s %s\n", user.person_name, user.person_address, user.mobile_num, user.email_address,
                        user.relation);
                fclose(file);
                printf("\33[93mNumber is changed successfully!\n\33[0m");
                return;
            }
            index++;
        }
        fclose(file);
        printf("Invalid user index.\n");
    }
    else
    {
        printf("Invalid user index.\n");
    }
}
