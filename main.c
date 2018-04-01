#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
int i;
int count1;
struct hotel
{
	int r[100],p[100],day[100],n,date[100],date1[100];
	char t[100],available[100];
	char name[100];
}h[100];
int count=0;
int add(int);
void menu();
void all_rooms(int);
int book(int,int);
void checkout(int,int);
int all_available_rooms(int);
void bill(int,int);
int main()
{
    count=add(count);
	menu();
}

void menu()
{
    Sleep(1000);
    int n;
	printf("\t\t MENU \n1.\t ALL ROOMS.\n2.\t AVAILABLE ROOMS.\n3.\t BOOK ROOM.\n4.\t CHECK OUT OF ROOM.\n5.\t ADD ROOM.\n");
	scanf("%d",&n);


	switch(n)
	{
	case 1:
		all_rooms(count);
		break;
       	case 2:
		count1=all_available_rooms(count);
		menu();
		break;
	case 3:
		count1=book(count,count1);
		break;
	case 4:
		checkout(count,count1);
		break;
	case 5:
        count=add(count);
		break;
	default :
		menu();
	}
}
// add a room by a manager
int add(int count)
{
	printf("enter number of rooms to be added::\n");
	scanf("%d",&h[1].n);
	for(int i=0;i<h[1].n;i++)
	{
	printf("enter the rooom no::\t");
	scanf("%d",&h[1].r[i]);
	printf("enter the type::\t A--AC\t,N--NON AC \t");
	scanf(" %c",&h[1].t[i]);
	printf("enter the price::\t");
	scanf("%d",&h[1].p[i]);
	printf("availability::\t Y--yes\t,N--no \t");
	scanf(" %c",&h[1].available[i]);
	++count;
	}
	printf("ADDED ROOM SUCCESSFULLY\n");
	printf("THE NUMBER OF TOTAL ROOMS IS  %d\n\n",count);
	return count;
	menu();
}
//for all rooms avaliable in hotel
void all_rooms(int count)
{
    system("cls");
	printf("\n No of rooms::%d\n\n",count);
	for(i=0;i<count;i++)
	{
	printf("\n %d ROOM NO:: %d\n TYPE:: %c \t PRICE %d per day::\n availability:: %c\n\n",i+1,h[1].r[i],h[1].t[i],h[1].p[i],h[1].available[i]);
	}
	menu();
}
// for all avaliable rooms in the hotel
int all_available_rooms(int count)
{
    system("cls");
    int count1=0;
    for(i=0;i<count;i++)
    {
  if(h[1].available[i]=='Y'||h[1].available[i]=='y')
  {
      ++count1;
	printf("rooom no::\t%d\n",h[1].r[i]);
	printf("type::\t%c\n",h[1].t[i]);
	printf("price::\t%d\n",h[1].p[i]);
	printf("availability::\t%c\n",h[1].available[i]);
  }
    }
    return count1;
    menu();
}

int book(int count,int count1)
{
    system("cls");
    char t1,t2;
    printf("enter the type of room required ::\t");
    scanf(" %c",&t1);
    for(i=0;i<count;i++)
    {
        if((h[1].available[i]=='Y'||h[1].available[i]=='y')&&h[1].t[i]==t1)
        {
            printf("do you want to book\t Y--yes,N--NO\t");
            scanf(" %c",&t2);
            if(t2=='Y')
            {
                h[1].available[i]='N';
                printf("enter the date(DATE) of booking::\n ");//for taking date and counting amount total
                scanf("%d",&h[1].date[i]);
                printf("enter the name of the customer::\t");
                scanf(" %s",&h[i].name);
                count1--;
                printf("COMFIRM THE NAME OF THE CUSTOMER::\t%s\n",h[i].name);
                menu();
            }
            else
                menu();
        }
    }
    return count1;
}

void checkout(int count,int count1)
{
    system("cls");
    char cust[100];
    char t1;
    printf("do you want to checkout::\t");
    scanf(" %c",&t1);
    if(t1=='y'||t1=='Y')
    {
        printf("ENTER THE NAME OF THE CUSTOMER::");
        scanf(" %s",&cust);
        for(i=0;i<count;i++)
        {
        if(strcmp(cust,h[i].name)==0)
        {
            bill(count,i);
            count1++;
            printf("THANK YOU\t\n\n");
            menu();
        }
        }
    }
    else
    {
        menu();
    }
}

void bill(int count,int i)
{
    printf("enter the date of checkout of the same month of booking::\n in format dd");//for counting checkout date and getting amount
    scanf("%d",&h[1].date1[i]);
    int amount=0;
    h[1].available[i]='Y';
    amount=(h[1].date1[i]-h[1].date[i])*h[1].p[i];
    printf("the bill totaled is ::\t%d\n\n",amount);
}
