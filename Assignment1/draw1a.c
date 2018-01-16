/*
 * Name: Chuan Yang
 * ID:   1421992
 * CSID: chuan1
 * Lec Section: A1
 * LAB Seciton: D05
 * TA's Name: Juehui Fan
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char command [10][10] = {"Image", "lineTo", "End", "print", "draw", "translate", "child", "#"};
	char line[257];  	//record every line in the file
	int ans[10] = {0}; 	//the answer number of every command
	long int i = 0, k = 0;		//index in for loop
	
	fp = freopen(argv[1],"r",stdin);
	if (fp == NULL)		//
	{
	  printf	("Cannot open the input file %s!\n",argv[1]);
		return -1;
	}
	else
	{
		while(fgets(line,257,fp))	//input one line of a time
		{
			int len = 0;
			while (line[len]!=' ') 	//get the length of the first word of every line
				len++; 
			
			char str [10] = ""; 	//get the first word if every line
			for (i=0; i<len ;i++)
				str[i] = line[i];
			
			//printf ("%s\n",str);  for debugging
			
			//begin to record the number of every command
			if (!strcmp(str,"Image"))
				ans[0]++;
			if (!strcmp(str,"lineTo"))
				ans[1]++;
			if (!strcmp(str,"End"))
				ans[2]++;
			if (!strcmp(str,"print"))
				ans[3]++;
			if (!strcmp(str,"draw"))
				ans[4]++;
			if (!strcmp(str,"translate"))
				ans[5]++;
			if (!strcmp(str,"child"))
				ans[6]++;
			if (!strcmp(str,"#"))
				ans[7]++;
		}
	}
	
	//output for 4 situations because of the different ends
	for (i=0;i<8;i++)
	{
		if (i == 0)				
		{
		        printf("%s started on ",argv[0]);
			fflush (stdout);
			system("date\n");
			printf("inpufile: %s\n",argv[1]);
			
			printf("%d %s definition(s)\n",ans[i],command[i]);
		}
			if (i == 1)
			printf("%d %s command(s) within Figures\n",ans[i],command[i]);
		if (i == 7)
			printf("%d comment(s)\n",ans[i]);
		if (i!=0 && i!=1 && i!=7)
			printf("%d %s command(s)\n",ans[i],command[i]);
	}
	
	fclose (fp);
	return 0;
}
