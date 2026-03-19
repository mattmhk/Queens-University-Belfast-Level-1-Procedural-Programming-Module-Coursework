#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    printf("Enter a date (dd/mm/yyyy) : ");
    int day, month, year;
    char day_suffix[3]= {""};
    char month_name[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    scanf(" %d/%d/%d", &day, &month, &year);
    if((day==1)||(day==11)||(day==21)||(day==31)){
        strcpy(day_suffix, "st");
    }
    if((day==2)||(day==12)||(day==22)){
        strcpy(day_suffix, "nd");
    }
    if((day==3)||(day==13)||(day==23)){
        strcpy(day_suffix, "rd");
    }
    else{
        strcpy(day_suffix, "th");
    }

    printf("You entered the date: %d%s %s %d\n", day, day_suffix, month_name[month-1], year);

}