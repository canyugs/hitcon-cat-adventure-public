#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int fd = open("story.txt", O_RDONLY);
    if (fd == -1){
        printf("The story.txt file missing, please contact the admin.");
        return 0;
    }
    char story[10000];
    read(fd, story, 10000); 
    

    int fd2 = open("menu.txt", O_RDONLY);
    if (fd2 == -1){
        printf("The menu.txt file missing, please contact the admin.");
        return 0;
    }
    char menu[10000];
    read(fd2, menu, 10000); 
    
    
    int fd3 = open("password.txt", O_RDONLY);
    if (fd3 == -1){
        printf("The password.txt file missing, please contact the admin.");
        return 0;
    }
    char password[10000];
    read(fd3, password, 10000); 


    int money = 100, choice = 0;
    while(1){
        printf("\n%s\n", menu);
        printf("You have %d dollars. What do you want to do?\n> ", money);
        if (scanf("%d", &choice) != 1) {
            return 1;
        }
        if(choice == 1) {
            if (money >= 15) {
                money -= 15;
                printf("Here you are.\n%s\n", story);
            }
            else {
                printf("You don't have enough money.\n");
                continue;
            }
        }
        else if(choice == 2) {
            if (money >= 9999) {
                money -= 9999;
                printf("Here you are.\n%s\n", password);
            }
            else {
                printf("You don't have enough money.\n");
                continue;
            }
        }
        else if(choice == 3) {
            int donation = 0;
            printf("How much do you want to donate?\n");
            scanf("%d", &donation);
            if(money < donation) {
                printf("You don't have enough money.\n");
                continue;
            }
            else {
                printf("Thanks for your donation.\n");
                money -= donation;
            }
        }
        else if(choice == 4) {
            printf("Bye~\n");
            return 0;
        }
        else {
            printf("Please input a valid choice!\n");
        }
    }
}
