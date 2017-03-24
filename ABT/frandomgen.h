#ifndef INCLUDED_STDIO
#include<stdio.h>
#endif
#ifndef INCLUDED_STDLIB
#include <stdlib.h>
#endif
#ifndef INCLUDED_MATH
#include <math.h>
#endif
#ifndef INCLUDED_TIME
#include <time.h>
#endif

#define SORT_TEST_LIMIT		100		
#define SORT_TEST_MIN		10
#define SORT_SIZE_LIMIT		100
#define SORT_RANGE_LIMIT	2000
#define SORT_RANGE_MIN		10

#define SEARCH_TEST_LIMIT	1000		
#define SEARCH_TEST_MIN		10
#define SEARCH_SIZE_LIMIT	100
#define SEARCH_RANGE_LIMIT	2000
#define SEARCH_RANGE_MIN	10
#define SEARCH_QUERY_LIMIT	100
#define SEARCH_QUERY_MIN	5

#define DISK_TEST_LIMIT		100		
#define DISK_TEST_MIN		10
#define DISK_CYLINDER_LIMIT	2000
#define DISK_CYLINDER_MIN	100
#define DISK_REQUEST_LIMIT	100

void frandomgen_sort(const char*);
void frandomgen_search(const char*);
void frandomgen_disk(const char* filepath);

void frandomgen_main(int op)
{
	switch(op)
	{
		case 0: frandomgen_sort("sorting_input_#.txt");
		break;
		case 1: frandomgen_search("searching_input_#.txt");
		break;
		case 2: frandomgen_disk("diskscheduling_input_#.txt");
		break;
		default:break;
	}
}

void frandomgen_sort(const char* filepath)
{
	FILE *fpout=fopen(filepath,"w");
	if(fpout==NULL)
	{
		printf("File couldn't be written!\n");
		fclose(fpout);
		return;
	}
	int c,t,n,num,max;
	time_t tmr;
	srand((unsigned) time(&tmr));
	t=rand()%SORT_TEST_LIMIT+SORT_TEST_MIN;
	fprintf(fpout,"%d\n",t);
	while(t--)
	{
		n=rand()%SORT_SIZE_LIMIT+1;
		max=rand()%SORT_RANGE_LIMIT+SORT_RANGE_MIN;
		fprintf(fpout,"%d\n",n);
		for(c = 1; c <= n; c++)
		{
			num = rand()%(2*max)-max;
			fprintf(fpout,"%d ",num);
		}
		fprintf(fpout,"\n\n");
	}
	fclose(fpout);
	fileread_sort(filepath);
}

void frandomgen_search(const char* filepath)
{
	FILE *fpout=fopen(filepath,"w");
	if(fpout==NULL)
	{
		printf("File couldn't be written!\n");
		fclose(fpout);
		return;
	}
	int c,t,n,q,num,max;
	time_t tmr;
	srand((unsigned) time(&tmr));	
	t=rand()%SEARCH_TEST_LIMIT+SEARCH_TEST_MIN;
	fprintf(fpout,"%d\n",t);

	while(t--)
	{
		n=rand()%SEARCH_SIZE_LIMIT+1;
		max=rand()%SEARCH_RANGE_LIMIT+SEARCH_RANGE_MIN;
		q=rand()%SEARCH_QUERY_LIMIT+SEARCH_QUERY_MIN;
		fprintf(fpout,"%d %d\n",n,q);
		for(c = 1; c <= n; c++)
		{
			num = rand()%(2*max)-max;
			fprintf(fpout,"%d ",num);
		}
		fprintf(fpout,"\n");
		for(c = 1; c <= q; c++)
		{
			num = rand()%(2*(max+5000))-(max+5000);
			fprintf(fpout,"%d ",num);
		}
		fprintf(fpout,"\n\n");
	}
	fclose(fpout);
	printf("done generating file\n");
	fileread_search(filepath);
}

void frandomgen_disk(const char* filepath)
{
	FILE *fpout=fopen(filepath,"w");
	if(fpout==NULL)
	{
		printf("File couldn't be written!\n");
		fclose(fpout);
		return;
	}
	int c,t,m,n,num,start;
	time_t tmr;
	srand((unsigned) time(&tmr));	
	t=rand()%DISK_TEST_LIMIT+DISK_TEST_MIN;
	fprintf(fpout,"%d\n",t);
	while(t--)
	{
		n=rand()%DISK_REQUEST_LIMIT+1;
		m=rand()%DISK_CYLINDER_LIMIT+DISK_CYLINDER_MIN;
		start=rand()%m;
		fprintf(fpout,"%d %d %d\n",m,n,start);
		for(c = 1; c <= n; c++)
		{
			num = rand()%m;
			fprintf(fpout,"%d ",num);
		}
		fprintf(fpout,"\n\n");
	}
	fclose(fpout);
	fileread_disk(filepath);
}

