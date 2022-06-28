/* A program to take input from user as roll no. and DOB and display his/her result (for 60 students )*/

#include<stdio.h>
#include<stdlib.h>

struct DOB                          //declaring structure for taking date of birth
{
 int day;
 int month;
 int year;
};

struct marks                        //declaring structure for taking marks of different subjects
{
 int csb;
 int hmb;
 int cyl;
 int meb;
 int mel;
 int mal;
 int mep;
 int eap;
};


struct student                      //declaring structure for storing student's information
{
 char name[80];
 long roll_no;
 struct DOB d[60];
 char college_name[80];
 struct marks t[60],p[60];
};


int main()
{
 int i;
 long roll;                         //declaring roll as long data type for taking input
 int b,c,e;
 struct student s[60];              //structure variable is declared for 60 students
 FILE *fptr;
 fptr=fopen("PROJECT_CSB.txt","r"); //opening file for reading information
 if(fptr==NULL)                     //if compiler is unable to open file due to error , this message will be shown
 {
     printf("Unable to open file.\n");
     exit(1);
 }
 else                               //when file is opened
 {
  for(i=0;i<60;i++)                 //loop will help to store same type of information
  {
   fgets(s[i].name,100,fptr);
   fscanf(fptr,"%ld",&s[i].roll_no);
   fscanf(fptr,"%d",&s[i].d[i].day);
   fscanf(fptr,"%d",&s[i].d[i].month);
   fscanf(fptr,"%d",&s[i].d[i].year);
   fscanf(fptr,"%d",&s[i].t[i].csb);
   fscanf(fptr,"%d",&s[i].p[i].csb);
   fscanf(fptr,"%d",&s[i].t[i].hmb);
   fscanf(fptr,"%d",&s[i].p[i].hmb);
   fscanf(fptr,"%d",&s[i].t[i].cyl);
   fscanf(fptr,"%d",&s[i].p[i].cyl);
   fscanf(fptr,"%d",&s[i].t[i].meb);
   fscanf(fptr,"%d",&s[i].p[i].meb);
   fscanf(fptr,"%d",&s[i].t[i].mel);
   fscanf(fptr,"%d",&s[i].t[i].mal);
   fscanf(fptr,"%d",&s[i].p[i].mep);
   fscanf(fptr,"%d",&s[i].p[i].eap);
  }
 }
 fclose(fptr);
// taking roll number and date of birth as an input
 printf("					National Institute Of Technology , Delhi\n");
 printf("						  End-Semester Results\n\n\n");
 printf("					Enter your roll no. 	     : ");
 scanf("%ld",&roll);
 printf("				Enter your date of birth(dd mm yyyy) : ");
 scanf("%d%d%d",&b,&c,&e);
 for(i=0;i<60 && roll!=s[i].roll_no;i++);    //loop will check presence of input roll number in file
 if(i==60)                                   //if roll number not found then we will show bad input
 printf("\n\n						Bad Credentials!!\n");
 else                                        //if roll number found , we will check date of birth entered by user
 {
  if(b==s[i].d[i].day && c==s[i].d[i].month && e==s[i].d[i].year)
    //displaying the result to student including details
  {
   printf("\n\n							NATIONAL INSTITUTE OF TECHNOLOGY , DELHI\n");
   printf("					    		   (Computer Science and Engineering)\n\n\n");
   printf(" 		Name of the student : %s\n",s[i].name);
   printf(" 		Roll Number         : %ld\n\n",s[i].roll_no);
   printf(" 		Date of birth       : %d-%d-%d\n\n",s[i].d[i].day,s[i].d[i].month,s[i].d[i].year);
   printf("	Year : 1st				Semester : Delayed-Autumn				Session : 2020-2021\n\n");
   printf("								   END SEMESTER RESULTS\n\n");
   printf("	S.No.		Subjects							Marks(Out of 100)\n\n");
   printf("								Credits		Theory			Practical\n\n");
   printf("	 1.    Problem Solving And Computer Programming            4		  %d                       %d\n",s[i].t[i].csb,s[i].p[i].csb);
   printf("			   [CSB 101]\n");
   printf("	 2.            Human Values And Ethics			   4		  %d			   %d\n",s[i].t[i].hmb,s[i].p[i].hmb);
   printf("			   [HMB 101]\n");
   printf("	 3.      Chemistry Structures And Reactivity		   6		  %d			   %d\n",s[i].t[i].cyl,s[i].p[i].cyl);
   printf("			   [CYL 100]\n");
   printf("	 4.            Engineering Visualization		   4		  %d			   %d\n",s[i].t[i].meb,s[i].p[i].meb);
   printf("			   [MEB 100]\n");
   printf("	 5.               Advanced Calculus			   4		  %d\n",s[i].t[i].mal);
   printf("			   [MAL 101]\n");
   printf("	 6.              Engineering Mechanics			   3		  %d\n",s[i].t[i].mel);
   printf("			   [MEL 102]\n");
   printf("	 7.   Product Design And Realization Laboratory I	   1					   %d\n",s[i].p[i].mep);
   printf("			   [MEP 103]\n");
   printf("	 8.            Extra - Academic Activity		   1			 		   %d\n",s[i].p[i].eap);
   printf("			   [EAP 101]\n\n");
  //Only if student scored more than 40 marks in each subject , he/she will be considered as pass
   if(s[i].t[i].csb>=40 && s[i].p[i].csb>=40 && s[i].t[i].hmb>=40 && s[i].p[i].hmb>=40 && s[i].t[i].cyl>=40 && s[i].p[i].cyl>=40 && s[i].t[i].meb>=40 && s[i].p[i].meb>=40 && s[i].t[i].mel>=40 && s[i].t[i].mal>=40 && s[i].p[i].mep>=40 && s[i].p[i].eap>=40 )
   printf("								   OVERALL RESULT : PASS!!\n");
   //otherwise fail
   else
   printf("								   OVERALL RESULT : FAIL!!\n");
  }
  else
  printf("\n\n						Bad Credentials!!\n");
 }
}
