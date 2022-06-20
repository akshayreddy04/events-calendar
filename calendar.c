#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"calendar.h"

int calendar();
int addevents();    
int viewevents();
int home();
int back();

//declared structure to store details given by the user and to store information from the file

struct eventinfo{
    int date,month,year;
    char name[100],summary[200];
};

int main()
{
    int num;
    printf("--------------------------------------------------------------------------");
    printf("\n\n1.View calendar\n\n\n\n2.Add event\n\n\n\n3.View events");
    printf("\n\n--------------------------------------------------------------------------");
    printf("\n\n\n\nenter the num: ");
    scanf("%d",&num);
    switch(num){
        case 1:
        system("clear");
        calendar();
        break;
        case 2:
        system("clear");
        addevents();
        case 3:
        system("clear");
        viewevents();
    }
    printf("\n");
    return 0;
}
//calendar function which prints the calendar asked the by the user

int calendar(){
    int month=0,year=0,date=0,line=0,startingday,j;
    char *months[]={"january","february","march","april","may","june","july","june","agust","september","october","november","december"};

    //it is the no of the days of the month (ex:jan=31,feb=28)

    int daysofmonth[]={31,28,31,30,31,30,31,30,31,30,31,30,31};
    printf("--------------------------------------------------------------");
    printf("\n\nenter the year: ");
    scanf("%d",&year);
    printf("\n\n\n\nenter the month: ");
    scanf("%d",&month);

    //verifying whether the user entered a suitable value

    if(month==0||year==0){
        system("clear");
        printf("enter the suitable value");
    }else{
    system("clear");
    printf("----------------------------------%s--------------------------------",months[month-1]);
    printf("\n  sun  mon  tue  wed  thu  fri  sat\n");

    //this happenes if the user entered year is a leap year 

    if((year%4==0&&year%100!=0)||year%400==0){
        daysofmonth[1]=29;
    }

    //this function helps us to find the starting day of the month 
    startingday=fstartingday(month,year);
    for(j=1;j<startingday;j++){
        printf("     ");
        line=startingday;
    }
    for(date=1;date<=daysofmonth[month-1];date++){
        printf("%5d",date);
        line++;
        if(line>7){
            printf("\n\n");
            line=1;
        }
    }
    }
  home();
    return 0;
}
int addevents(){

    //information user entered is saved in struct and copied into the file

    struct eventinfo addingevent;
    addingevent.date=0;
    addingevent.month=0;
    addingevent.year=0;
    FILE *infile;
    fflush(stdin);
    printf("name of the event: ");
    scanf("%[^\n]s",addingevent.name);
    printf("enter the date(dd/mm/yyyy): ");
    scanf("%d/%d/%d",&addingevent.date,&addingevent.month,&addingevent.year);
    fflush(stdin);
    printf("summary: ");
    scanf("%[^\n]s",addingevent.summary);
    if(addingevent.date==0||addingevent.month==0||addingevent.year==0){
        printf("enter the suitable value");
    }
    else{
    infile=fopen("events.dat","a");
    fwrite(&addingevent, sizeof(struct eventinfo), 1, infile);
    fclose(infile);
    }
   home();
    return 0;
}
int viewevents(){

    //the data stored in the file is copied into struct and displayed based on the user requirement

    struct eventinfo viewingevent[100];
    //sno denotes serial number
    int noofevents=0,date=0,month=0,year=0,view,j,sno=1;
    FILE *outfile;
    outfile=fopen("events.dat","r");
    while(fread(&viewingevent[noofevents], sizeof(struct eventinfo), 1, outfile)){
        noofevents++;
    }
    fclose(outfile);
    printf("\n-----------------------------------------------------------");
    printf("\n\n1.view all events");
    printf("\n\n2.view events by reference of date");
    printf("\n\n3.view events by reference of month");
    printf("\n\n4.view events by reference of year");
    printf("\n\n5.view events by reference of date(dd/mm/yyyy): ");
    printf("\n\n6.back");
    printf("\n-----------------------------------------------------------");
    printf("\nenter the num: ");
    scanf("%d",&view);
    switch (view){
        case 1:
        system("clear");
        for(j=0;j<noofevents;j++){
             printf("\n%d.%d/%d/%d\n  %s\n  %s\n",sno,viewingevent[j].date,viewingevent[j].month,viewingevent[j].year,viewingevent[j].name,viewingevent[j].summary);
             sno++;
        }
        back();
        break;
        case 2:
        system("clear");
        printf("enter the date: ");
        scanf("%d",&date);
        for(j=0;j<noofevents;j++){
             if(date==viewingevent[j].date){
                 printf("\n%d.%d/%d/%d\n  %s\n  %s\n",sno,viewingevent[j].date,viewingevent[j].month,viewingevent[j].year,viewingevent[j].name,viewingevent[j].summary);
                sno++;
            } 
        }
        back();
        break;
        case 3:
        system("clear");
        printf("enter the month: ");
        scanf("%d",&month);
        for(j=0;j<noofevents;j++){
             if(month==viewingevent[j].month){
                 printf("\n%d.%d/%d/%d\n  %s\n  %s\n",sno,viewingevent[j].date,viewingevent[j].month,viewingevent[j].year,viewingevent[j].name,viewingevent[j].summary);
                sno++;
            }
        }
        back();
        break;
        case 4:
        system("clear");
        printf("enter the year: ");
        scanf("%d",&year);
        for(j=0;j<noofevents;j++){
             if(year==viewingevent[j].year){
                  printf("\n%d.%d/%d/%d\n  %s\n  %s\n",sno,viewingevent[j].date,viewingevent[j].month,viewingevent[j].year,viewingevent[j].name,viewingevent[j].summary);
                  sno++;
            }
        }
        back();
        break;
        case 5:
        system("clear");
        printf("\n5.enter the date(dd/mm/yyyy): ");
        scanf("%d/%d/%d",&date,&month,&year);
        for(j=0;j<noofevents;j++){
         if(date!=0&&month!=0&&year!=0){
             if(date==viewingevent[j].date&&month==viewingevent[j].month&&year==viewingevent[j].year){
                  printf("\n%d.%d/%d/%d\n  %s\n  %s\n",sno,viewingevent[j].date,viewingevent[j].month,viewingevent[j].year,viewingevent[j].name,viewingevent[j].summary);
                  sno++;
            }
         }
        else{
            
            printf("enter the suitable value");
            break;
        } 
    }
       back();
        break;
   
    case 6:
    system("clear");
    main();
    break;
    }
    return 0;
}
    int home(){
         int choice;
    printf("\n\n----------------------------------------");
     printf("\nenter\n1.exit program\n2.back: ");
    printf("\n----------------------------------------");
    scanf("%d",&choice);
    if(choice==2){
        system("clear");
        main();
    }
    
   
 return 0;      
}
int back(){
        int choice;
        printf("\n\n----------------------------------------");
        printf("\nenter\n1.exit program\n2.back: ");
        printf("\n----------------------------------------");
        scanf("%d",&choice);
        if(choice==2){
        system("clear");
        viewevents();
        }
    return 0;
}


