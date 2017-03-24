#ifndef INCLUDED_STDIO
#include<stdio.h>
#endif
#define REQUEST_LIMIT	9000

int absolute(int a,int b)
{
	int c;
	c=a-b;
	if(c<0)
		return -c;
	else
		return c;
}

int CSCAN(int m,int n, int start, int* a)
{
	int i,j,x,pos,count;
	count=0;
	pos=0;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
	for(i=0;i<n;i++)
		if(a[i]<start)
			pos++;
	x=start;
	for(i=pos;i<n;i++)
	{
		count+=absolute(x,a[i]);
		x=a[i];
	}
	count+=absolute(m-1,x);
	x=0;
	for(i=0;i<pos;i++)
	{
		count+=absolute(x,a[i]);
		x=a[i];
	}
	return count;
}
int SCAN(int m,int n, int start, int* a)
{
	int i,j,x,pos,count;
	count=0;
	pos=0;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
	for(i=0;i<n;i++)
			if(a[i]<start)
			pos++;
	for(i=0;i<pos;i++)
		for(j=0;j<pos-i-1;j++)
			if(a[j]<a[j+1])
			{
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
	x=start;
	for(i=0;i<pos;i++)
	{
		count+=absolute(a[i],x);
		x=a[i];
	}
	count+=absolute(x,0);
	x=0;
	for(i=pos;i<n;i++)
	{
		count+=absolute(a[i],x);
		x=a[i];
	}
	return count;
}	

int FCFS(int m,int n, int start, int* a)
{
	int i,j,x=start,count=0;
	for(i=0;i<n;i++)
	{
		x-=a[i];
		if(x<0)
			x=-x;
		count+=x;
		x=a[i];
	}
	return count;
}

int SSTF(int m,int n, int start, int* a)
{
	int i,j,x=start,pos,min,count=0;
	for(i=0;i<n;i++)
	{
		min=absolute(a[i],x);
		pos=i;
		for(j=i;j<n;j++)
			if(min>absolute(x,a[j]))
			{
				pos=j;
				min=absolute(x,a[j]);
			}
		count+=absolute(x,a[pos]);
		x=a[pos];
		a[pos]=a[i];
		a[i]=x;
	}
	return count;
}

int LOOK(int m,int n, int start, int* a)
{
	int i,j,x,pos,count;
	count=0;
	pos=0;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
	for(i=0;i<n;i++)
		if(a[i]<start)
			pos++;
	for(i=0;i<pos;i++)
		for(j=0;j<pos-i-1;j++)
			if(a[j]<a[j+1])
			{
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
	x=start;
	for(i=0;i<pos;i++)
	{
		count+=absolute(a[i],x);
		x=a[i];
	}
	for(i=pos;i<n;i++)
	{
		count+=absolute(a[i],x);
		x=a[i];
	}
	return count;
}

int CLOOK(int m,int n, int start, int* a)
{
	int i,j,x,pos,count;
	count=0;
	pos=0;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
	for(i=0;i<n;i++)
		if(a[i]<start)
			pos++;
	x=start;
	for(i=pos;i<n;i++)
	{
		count+=absolute(x,a[i]);
		x=a[i];
	}
	for(i=0;i<pos;i++)
	{
		count+=absolute(x,a[i]);
		x=a[i];
	}
	return count;
}
