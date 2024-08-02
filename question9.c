/*Q9. WAP in C to calculate the difference in no. of days between two
dates.(Dates are entered in as a single string, eg: “08-11-2021,15-01-1932”)*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int d_d,m_m,y_y;//d_d stores day,m_m stores month,y_y stores year.

void converter(char date[],int l){
	int i,j=0,k=0,r=0;
	char d[2];
	char m[2];
	char y[4];
	
	for(i=0;i<2;i++){
		d[r++]=date[i];
	}
	d_d=atoi(d);
	for(i=3;i<5;i++){
		m[j++]=date[i];
	}
		m_m=atoi(m);
		
	for(i=6;i<l;i++){
		y[k++]=date[i];
	}  
		y_y=atoi(y);
}
//function one

int days_in_same_year(int d1,int d2, int m1, int m2, int y1)
{
    int i=0, days=0;

for(i=m1+1;i<m2;i++)
{
    if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
    days=days+31;
    
    else if (i==4 || i==6 || i==9 || i==11)
    days=days+30;
    
    else if(i==2)
    {
        if((y1%4==0 && y1%100!=0)|| (y1%400==0))
        days=days+29;
        else
        days=days+28;
    }
}

if( m1==1 || m1==3 || m1==5 || m1==7 || m1==8 || m1==10 || m1==12)
days=31-d1+d2+days;

else if( m1==4 || m1==6 || m1==9 || m1==11)
days=30-d1+d2+days;

else if ( m1==2)
{
    if ((y1%4==0 && y1%100!=0) || (y1%400==0))
    days=29-d1+d2+days;
    else
    days=28-d1+d2+days;
} 

 return days;
 
} 

//function 2 
int days_in_between_years( int y1 , int y2)
{
    int i=0,days=0;
    
    if(y1+1==y2)
    {return 0;}
    
    else if(y1+1<y2)
  {
    for(i=y1+1;i<y2;i++)
    {
        if((i%4==0 && i%100!=0) || (i%400==0))
        days=days+366;
        
        else 
        days=days+365;
    }
  }
    
    return days;
}

//function 3
 int days_in_that_year(int d1, int m1, int y1)
 {
     int i=0, days=0;
     
     for(i=m1+1;i<=12;i++)
     {
         if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
         days=31+days;
         
         else if (i==4 || i==6 || i==9 || i==11)
         days=30+days;
          
         else if(i==2)
         {
             if((y1%4==0 && y1%100!=0) || (y1%400==0))
             days=29+days;
             else 
             days=28+days;
         }
     }
     
     if(m1==1 || m1==3 || m1==5 || m1==7 || m1==8 || m1==10 || m1==12)
     days=31-d1+days;
     
     else if(m1==4 || m1==6 || m1==9 || m1==11)
     days=30-d1+days;
     
     else if(m1==2)
     {
       if((y1%4==0 && y1%100!=0) || (y1%400==0)) 
       days=29-d1+days;
       else
       days=28-d1+days;
     }
     return days;
 }

//function 4
int days_in_succeeding_year(int d2, int m2, int y2)
{
    int i=0, days=0;
    
    for(i=1;i<m2;i++)
    {
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
        days= days+31;
        
        else if (i==4 || i==6 || i==9 || i==10)
        days = days+30;
        
        else if (i==2)
        {
            if((y2%4==0 && y2%100!=0) || (y2%400==0))
            days=days+29;
            
            else 
            days=days+28;
        }
    }
    
    if(i=m2)
    days=days+d2;
    
    return days;
}
int main(){
	char date1[10];
	char date2[10];
	int len1;
	int len2;
	int d1,d2,m1,m2,y1,y2,days1=0,days2=0,days3=0,days4=0,days_total=0;;
	printf("MARIYA USMAN     21BCS058\n");
	printf("Enter first date: ");
	scanf("%[^\n]s",date1);
	
	fflush (stdin);
	printf("Enter second date: ");
	scanf("%[^\n]s",date2);
	
	//function to extract from string into integer
	len1=strlen(date1);
	len2=strlen(date2);
	
	converter(date1,len1);
	d1=d_d;m1=m_m;y1=y_y;
	converter(date2,len2);
	d2=d_d;m2=m_m;y2=y_y;
	
	
	if(y1==y2)
    {
        days1=days_in_same_year( d1, d2, m1, m2, y1);
        printf(" DAYS = %d " ,days1);
    }
    
    else if (y2!=y1 && y2>y1)
    {
        days2=days_in_between_years(y1,y2);
        days3=days_in_that_year(d1,m1,y1);
        days4=days_in_succeeding_year(d2,m2,y2);
        days_total=days2+days3+days4;
        
        printf("DAYS = %d ", days_total);
    }
    

	return 0;
}