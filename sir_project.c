#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#define MAX_USERS 50
#define MAX_SIZE 26
#define NUMBER_FILE "num.txt"
#define TEMPOR "tempr.txt"

struct Persons {
    char person_name[MAX_SIZE];
    char person_address[MAX_SIZE];
    char mobile_num[MAX_SIZE];
    char email_address[MAX_SIZE];
    char relation[MAX_SIZE];
};
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
int search_login() {
    char person[MAX_SIZE];
    char email[MAX_SIZE];

    printf("\33[92mEnter person's name.\n\33[0m");
    scanf("%s", person);
    printf("\33[92mEnter email address.\n\33[0m");
    scanf("%s", email);

    FILE *file = fopen(NUMBER_FILE, "r");
    if (!file) {
        printf("Error opening users file.\n");
        return -1;//error file if file exists then it will return NULL
    }
    struct Persons user;
    int index = 0;
    while (fscanf(file, "%s %s %s %s %s", user.person_name, user.person_address, user.mobile_num, user.email_address,
                  user.relation) != EOF)
    {
        if (strcmp(person, user.person_name) == 0 && strcmp(email, user.email_address) == 0) {
            printf("\33[93mWelcome\33[0m \33[95m%s\33[0m \33[93m!\n\33[0m", user.person_name);
            printf("\33[93mAddress: \33[95m%s\n\33[0m", user.person_address);
            printf("\33[93mNumber: \33[95m%s\n\33[0m", user.mobile_num);
            printf("\33[93mEmail: \33[95m%s\n\33[0m", user.email_address);
            printf("\33[93mRelation: \33[95m%s\n\n\33[0m", user.relation);
            fclose(file);
            printf("\33[93mLogin Index: \33[95m%d\33[0m", index);
            return index;//Return the index of the logged-in user
        }
        index++;
    }
    fclose(file);
    printf("Login failed. Invalid credentials.\n");
    return -1;


}
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
int main()
{

    int choice,userIndex = -1;
    do{
        printf("\33[96m \n\t\t****Phone Book****\n\n\n\33[0m");
        //system("cls");
        //system("COLOR 0A");
        printf("\33[93m \t\t|Menu|\n\33[0m");
        printf("\33[93m \t=====================\n\n\33[0m");
        printf("\33[95m [1] Add number\t\33[0m");
        printf("\33[95m \t[2] Search number\n\33[0m");
        printf("\33[95m [3] Change number\t\33[0m");
        printf("\33[95m[4] Exit\n\33[0m");
        printf("\33[95m [5] List\t\33[0m");
        printf("\33[95m \t\[6] Delete number\n\33[0m");
        printf("\33[92m \nEnter your choice.\33[0m");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addmobile();
                break;
            case 2:
                userIndex = search_login();
                break;
            case 3:
                changenumber(userIndex);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            case 6:
                deletenumber();
                break;
            case 5:
                list_number();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while(choice !=4);
    return 0;
}
//
// Created by suria on 9/4/23.
//
