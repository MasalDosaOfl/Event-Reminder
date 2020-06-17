// Event Reminder
// C - Mini Project
// By Tharun - 19Z254
// Suriya - 19Z250
// Navaneeth - 19Z229
// Sanjai - 19Z242


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct event{
    char title[50];
    char desc[100];
    int hours;
    int mins;
    int day;
    int month;
    int year;
};


struct event eve;


void deleteEvents(char txt[50])
{
    char title[50], data[100];
    int flag = 0, i = 0;
    printf("\nEnter the Title of the Event you want to Modify: ");
    scanf("%s", &title);
    strcat(title, "\n");

    //Deleting the Event by copying the other Events into a new file
    FILE *fp, *temp;
    fp = fopen(txt, "r");
    temp = fopen("temp.txt", "w");
    while (!feof(fp))
    {
        fgets(data, 200, fp);
        if ((strcmp(title, data)) == 0 || i != 0)
        {
            flag = 1;
            i++;
            if (i == 8)
            {
                flag = 0;
                i = 0;
            }
        }
        if (flag == 0 && i == 0)
            fprintf(temp, "%s", data);
    }
    fclose(fp);
    fclose(temp);
    remove(txt);
    rename("temp.txt", txt);
}


void editEvents(char txt[50])
{
    deleteEvents(txt);
    system("cls");
    FILE *fp;
    fp = fopen(txt,"a+");
    //Getting Input
    printf("\t\tMODIFIED EVENT\n\nEnter a Title for the Event: ");
    scanf("%s", &eve.title);
    printf("\nEnter a short Description about the Event: ");
    scanf("%s", &eve.desc);
    printf("\nTime of the Event - Hours(hh): ");
    scanf("%d", &eve.hours);
    printf(" Minutes(mm): ");
    scanf("%d", &eve.mins);
    printf("\nDate of the Event - Date(dd): ");
    scanf("%d", &eve.day);
    printf(" Month(mm): ");
    scanf("%d",&eve.month);
    printf(" Year(YY): ");
    scanf("%d", &eve.year);

    // Writing Data into Files
    fputs(eve.title, fp);
    fputs("\n", fp);
    fputs(eve.desc, fp);
    fputs("\n", fp);
    fprintf(fp, "%d",eve.hours);
    fputs("\n", fp);
    fprintf(fp, "%d",eve.mins);
    fputs("\n", fp);
    fprintf(fp, "%d",eve.day);
    fputs("\n", fp);
    fprintf(fp, "%d",eve.month);
    fputs("\n", fp);
    fprintf(fp, "%d",eve.year);
    fputs("\n", fp);
    fclose(fp);
    return 0;
}


int exists(const char *txt)
{
    FILE *file;
    if((file = fopen(txt, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

void displayEvents(char txt[50])
{
    system("cls");
    FILE *fp;
    fp = fopen(txt, "a+");
    char line[200];
    while( fgets ( line, 200, fp ) != NULL)
    {
        char hours[5], mins[5], day[5], month[5], year[5];
        printf( "\nEvent Title: %s" , line ) ;
        fgets(line, 200, fp);
        printf("Event Description: %s", line);
        fscanf(fp, "%s", hours);
        fscanf(fp, "%s", mins);
        fscanf(fp, "%s", day);
        fscanf(fp, "%s", month);
        fscanf(fp, "%s", year);
        printf("Time of the Event: %s:%s", hours, mins);
        printf("\nDate of the Event: %s/ %s/ %s\n\n", day, month, year);
        fseek(fp, 2, SEEK_CUR);
    }
    fclose(fp);
}


void addEvent(char txt[])
{
    system("cls");
    FILE *fp;
    fp = fopen(txt,"a+");
    while(1)
    {
        //Getting Input
        printf("\t\tNEW EVENT\n\nEnter a Title for the Event: ");
        scanf("%s", &eve.title);
        printf("\nEnter a short Description about the Event: ");
        scanf("%s", &eve.desc);
        printf("\nTime of the Event - Hours(hh): ");
        scanf("%d", &eve.hours);
        printf(" Minutes(mm): ");
        scanf("%d", &eve.mins);
        printf("\nDate of the Event - Date(dd): ");
        scanf("%d", &eve.day);
        printf(" Month(mm): ");
        scanf("%d",&eve.month);
        printf(" Year(YY): ");
        scanf("%d", &eve.year);

        // Writing Data into Files
        fputs(eve.title, fp);
        fputs("\n", fp);
        fputs(eve.desc, fp);
        fputs("\n", fp);
        fprintf(fp, "%d",eve.hours);
        fputs("\n", fp);
        fprintf(fp, "%d",eve.mins);
        fputs("\n", fp);
        fprintf(fp, "%d",eve.day);
        fputs("\n", fp);
        fprintf(fp, "%d",eve.month);
        fputs("\n", fp);
        fprintf(fp, "%d",eve.year);
        fputs("\n", fp);
        printf("Would you like to add another Event? (Y / N): ");
        char ch = NULL;
        scanf("%c", &ch);
        if(ch != 'Y' && ch != 'y')
            break;
        else
            printf("\n");
    }
    fclose(fp);

}


int main()
{
    int n = 0;
    while(1)
    {
        printf("\n\t\tWELCOME TO THE REMINDER\n");
        printf("Choose any of the Choices below:\n");
        printf("1. Create\n");
        printf("2. Add\n");
        printf("3. Display/Edit\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &n);
        system("cls");
        switch(n)
        {
            case 1:
            {
                char str[20];
                while(1)
                {
                    printf("Please enter a User-name to create a file: ");
                    scanf("%s", &str);
                    strcat(str, ".txt");
                    if(exists(str))
                        printf("The user name has already been taken, try a different one.\n");
                    else
                    {
                        printf("You have successfully created a personal file %s to store your Events", str);
                        break;
                    }
                }
                addEvent(str);
                break;
            }

            case 2:
            {
                char str[20];
                while(1)
                {
                    printf("Please enter a User-name to create a file: ");
                    scanf("%s", &str);
                    strcat(str, ".txt");
                    if(exists(str))
                        break;
                    else
                    {
                        printf("Such a user doesn't exist, please a create a User before accessing your files.");
                        remove(str);
                    }
                }
                addEvent(str);
                break;
            }
            case 3:
            {
                char str[20];
                while(1)
                {
                    printf("Please enter the User-name: ");
                    scanf("%s", &str);
                    strcat(str, ".txt");
                    if(exists(str))
                        break;
                    else
                    {
                        printf("Such a user doesn't exist, please a create a User before accessing your files.");
                        remove(str);
                    }
                }
                displayEvents(str);
                editEvents(str);

                break;
            }
            case 4:
            {
                char str[20];
                while(1)
                {
                    printf("Please enter the User-name: ");
                    scanf("%s\n", &str);
                    strcat(str, ".txt");
                    if(exists(str))
                        break;
                    else
                    {
                        printf("Such a user doesn't exist, please a create a User before accessing your files.");
                        remove(str);
                    }
                }
                displayEvents(str);
                deleteEvents(str);

                break;
            }
            case 5:
            {
                exit(0);
            }
            default:
            {
                printf("Sorry but that's a non-existential choice.\n");
            }
        }
    }
}
