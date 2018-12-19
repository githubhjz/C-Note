#include "stdio.h"
#include "string.h"

/**
* \brief  check ip_addr string whether valid,v0.0.1
* \note   "stdlib.h"/"string.h"
* \param  ip string
* \retval 1=valid,0=invalid
*/
char ip_check(const char *ip_str)
{
	char prase_str[20],*ptr = NULL;
	char ip_arr[4][4],index = 0;
	char i = 0,j = 0;
	/***ip_str length check <=15 adn >=7 ***/
	if((strlen(ip_str) < 7) || (strlen(ip_str) > 15))
	{
		return 0;
	}

	/*** split ip_str to 4 segment ***/
	memset(prase_str,0,sizeof(prase_str));
	strcpy(prase_str,ip_str);
	
	ptr = strtok(prase_str, ".");
	while(ptr != NULL)
	{
		if(index >= 4)
			return 0;
		memset(ip_arr[index],0,sizeof(ip_arr[index]));
		strcpy(ip_arr[index++],ptr);

		ptr = strtok(NULL, ".");
	}
	
	if(index != 4)
		return 0;

	/*** str_num check ***/
	for(i=0;i<sizeof(ip_arr)/sizeof(ip_arr[0]);i++)
	{
		for(j=0;j<strlen(ip_arr[i]);j++)
		{
			if((ip_arr[i][j] < '0') || 	(ip_arr[i][j] > '9'))
				return 0;	
		}
	}

	/*** num check ***/
	for(i=0;i<sizeof(ip_arr)/sizeof(ip_arr[0]);i++)
	{
		int temp = atoi(ip_arr[i]);
		if((temp < 0) || (temp > 255))
			return 0;
	}
	
	/***check ok***/
	return 1;
}


