#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

int i,j,ch;
char fn[20],e,c;
FILE *fp1,*fp2,*fp;
void Create();
void Append();
void Copy();
void Delete();
void Display();
int main()

{
do {
system("cls");
printf("\n\t\t***** TEXT EDITOR *****");
printf("\n\n\tMENU:\n\t\n");
printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.COPY\n\t5.DELETE\n\t6.EXIT\n");
printf("\n\tEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
Create();
break;
case 2:
Display();
break;
case 3:
Append();
break;
case 4:
Copy();
break;
case 5:
Delete();
break;
case 6:
exit(0);
}
}while(1);
}
void Create()
{
fp1=fopen("temp.txt","w");
printf("\n\tEnter the text and press '.' to save\n\n\t");
while(1)
{
c=getchar();
fputc(c,fp1);
if(c == '.')
{
fclose(fp1);
break;
}
}}
 
void Display()
{
printf("\n\tEnter the file name: ");
scanf("%s",fn);
fp1=fopen(fn,"r");
if(fp1==NULL)
{
printf("\n\tFile not found!");
goto end1;
}
while(!feof(fp1))
{
c=getc(fp1);
printf("%c",c);
}
end1:
fclose(fp1);
printf("\n\n\tPress any key to continue\n");
getch();
}
void Copy()
{
printf("\n\tEnter the new filenameto copy:  ");
scanf("%s",fn);
fp1=fopen("temp.txt","r");
fp2=fopen(fn,"w");
while(!feof(fp1))
{
c=getc(fp1);
putc(c,fp2);
}
fclose(fp2);
}
 
void Delete()
{
printf("\n\tEnter the file name: ");
scanf("%s",fn);
fp1=fopen(fn,"r");
if(fp1==NULL)
{
printf("\n\tFile not found!");
goto end2;
}
fclose(fp1);
if(remove(fn)==0)
{
printf("\n\n\tFile has been deleted successfully!");
goto end2;
}
else
printf("\n\tError!\n");
end2: printf("\n\n\tPress any key to continue\n");
getch();
}
 
void Append()
{
printf("\n\tEnter the file name: ");
scanf("%s",fn);
fp1=fopen(fn,"r");
if(fp1==NULL)
{
printf("\n\tFile not found!");
fclose(fp1);
goto end3;
}
while(!feof(fp1))
{
c=getc(fp1);
printf("%c",c);
}
fclose(fp1);
printf("\n\tType the text and press Ctrl+S to append.\n");
fp1=fopen(fn,"a");
while(1)
{
c=getch();
if(c==19)
goto end3;
if(c==13)
{
c='\n';
printf("\n\t");
fputc(c,fp1);
}
else
{
printf("%c",c);
fputc(c,fp1);
}
}
end3: fclose(fp1);
 
getch();
}
