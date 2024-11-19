#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isRepeating(char* temp, char** Words, int x, int* freq)
{
	for(int i=0;i<x;i++)
		if(strcmp(Words[i],temp)==0)
		{
			freq[i]++;
			return 1;
		}
	return 0;
}
int main()
{
	char* str;
	str=(char*)malloc(100*sizeof(char));
	printf("Enter the string: ");
	scanf("\n%[^\n]s",str);
	char* temp;
	temp=(char*)malloc(50*sizeof(char));
	int l=0,x=0;
	char** Words;
	Words=(char**)malloc(20*sizeof(char*));
	for(int i=0;i<20;i++)
		Words[i]=(char*)malloc(50*sizeof(char));
	int* freq;
	freq=(int*)malloc(20*sizeof(int));
	for(int i=0;i<20;i++)
		freq[i]=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]==' ')
		{
			temp[l]='\0';
			if(!isRepeating(temp,Words,x,freq))
			{
				strcpy(Words[x],temp);
				freq[x]++;
				x++;
			}
			l=0;
			temp[l]='\0';
		}
		else
			temp[l++]=str[i];
	}
	temp[l]='\0';
	if(!isRepeating(temp,Words,x,freq))
	{	
		strcpy(Words[x],temp);
		freq[x]++;
		x++;
	}
	free(temp);
	printf("Non-repeating words are: ");
	for(int i=0;i<x;i++)
		if(freq[i]==1)
			printf("%s ",Words[i]);
	return 0;
}