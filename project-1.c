#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int option;
    printf("Do you want a particular day(if s enter 1) or month(if s enter 2):");
    scanf("%d",&option);
    while(1)
    {
        if(option==1)
        {
            int d,m,y;
            printf("enter date,month,year(dd mm yyyy format):");
            scanf("%d%d%d",&d,&m,&y);
            findday(d,m,y);
            return 0;
            break;
        }
        else if(option==2)
        {
            int year,mont;
            printf("Enter month and year(dd yyyy format):");
            scanf("%d %d",&mont,&year);
            printCalender(mont,year);
            return 0;
            break;
        }
        else
        {
            printf("Enter correct Date");
            continue;
        }
    }
}
int findday(int date,int month,int year)
{
    int day,yr,yd;
    yr=year%100;
    yd=year/100;
    day=1.25*yr+findmonth(month,year)+date-2*(yd%4);
    day=day%7;
    switch(day)
    {
        case 0:
        {
            printf("it's Saturday");
            break;
        }
        case 1:
        {
            printf("it's Sunday");
            break;
        }
        case 2:
        {
            printf("it's Monday");
            break;
        }
        case 3:
        {
            printf("it's Tuesday");
            break;
        }
        case 4:
        {
            printf("it's Wednesday");
            break;
        }
        case 5:
        {
            printf("it's Thursday");
            break;
        }
        case 6:
        {
            printf("it's Friday");
            break;
        }
        default:
        {
            printf("enter correct date");
            
        }
    }
    return 0;
}
int findmonth(int month_s,int years)
{
    int fmonth,leapyear;
    if((years%100==0)&&(years%400!=0))
    leapyear=0;
    else if(years%4==0)
    leapyear=1;
    else
    leapyear=0;
    fmonth=3+(2-leapyear)*((month_s+2)/(2*month_s))+(5*month_s+month_s/9)/2;
    fmonth=fmonth%7;
    return fmonth;
}
int dayNumber(int day,int month,int year)
{
    static int t[]={0,3,2,5,0,3,5,1,4,6,2,4};
    year-=month<3;
    return (year+year/4-year/100+year/400+t[month-1]+day)%7;
}
char* getMonthName(int monthNumber)
{
    char* month;
    switch(monthNumber)
    {
        case 1:
          month="January";
          break;
        case 2:
          month="February";
          break;
        case 3:
          month="March";
          break;
        case 4:
          month="April";
          break;
        case 5:
          month="May";
          break;
        case 6:
          month="June";
          break;
        case 7:
          month="July";
          break;
        case 8:
          month="August";
          break;
        case 9:
          month="September";
          break;
        case 10:
          month="October";
          break;
        case 11:
          month="November";
          break;
        case 12:
          month="December";
          break;
    }
    return month;
}
int numberOfDays(int monthNumber,int year)
{
    if(monthNumber==1)
      return(31);
    if(monthNumber==2)
    {
        if(year%400==0||(year%4==0&&year%100!=0))
          return (29);
        else
          return (28);
    }
    if(monthNumber==3)
      return (31);
    if(monthNumber==4)
      return (30);
    if(monthNumber==5)
      return (31);
    if(monthNumber==6)
      return (30);
    if(monthNumber==7)
      return (31);
    if(monthNumber==8)
      return (31);
    if(monthNumber==9)
      return (30);
    if(monthNumber==10)
      return (31);
    if(monthNumber==11)
      return (30);
    if(monthNumber==12)
      return (31);
}
void printCalender(int Months,int year)
{
    printf("     Calender - %d-%d\n",Months,year);
    int days;
    int current=dayNumber(1,Months,year);
    days=numberOfDays(Months,year);
    printf("\n --------------%s-----------------\n",getMonthName(Months));
    printf(" Sun   Mon  Tue  Wed  Thu  Fri  Sat\n");
    int k;
    for(k=0;k<current;k++)
        printf("     ");
    for(int j=1;j<=days;j++)
    {
        printf("%5d",j);
        if(++k>6)
        {
            k=0;
            printf("\n");
        }
    }
    if(k)
      printf("\n");
    current=k;
    return;
}