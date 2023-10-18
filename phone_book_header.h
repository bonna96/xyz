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
