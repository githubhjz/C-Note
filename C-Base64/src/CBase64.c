/**
 *  Copyright (c) 2015, Everhigh Tech. Ltd. Co.
 *  		All rights reserved
 */

/**
 * \addtogroup Base64
 * @{
 */

/**
 * \file		  CBase64.c
 * \brief		  Base64 decode/encode
 *
 * \author		zhjxy <zhanghuijun@everhigh.com.cn>
 * \version	    V0.0.1
 * \date		2018-9-21
 * \license
 *------------------------------------------------------------------*
 *	Change History :
 *  <Date>     | <Version> | <Author>      | <Description>          *
 *------------------------------------------------------------------*
 *  2018/09/21 | 0.0.1   | zhjxy       | Create file            *
 */
#include <stdlib.h>
#include <string.h>
#include "CBase64.h"

static const char encode_base64_table[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char decode_base64_table[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,62,0,0,0,63,52,53,54,55,56,57,58,59,60,61,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,0,0,0,0,0,0,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
/**
 * \brief  					
 * \param  
 * \param	  
 * \return dst size
 */
int Base64Encode(const unsigned char *src,unsigned int src_len,unsigned char *dst)
{
    long len = 0;
    int i,j;
 
	//计算经过base64编码后的字符串长度
    if(src_len % 3 == 0)
        len=src_len/3*4;
    else
        len=(src_len/3+1)*4;
 
    dst[len]='\0';
 
	//以3个8位字符为一组进行编码
    for(i=0,j=0;i<len-2;j+=3,i+=4)
    {
        dst[i] = encode_base64_table[src[j]>>2]; //取出第一个字符的前6位并找出对应的结果字符
        dst[i+1] = encode_base64_table[(src[j]&0x3)<<4 | (src[j+1]>>4)]; //将第一个字符的后位与第二个字符的前4位进行组合并找到对应的结果字符
        dst[i+2] = encode_base64_table[(src[j+1]&0xf)<<2 | (src[j+2]>>6)]; //将第二个字符的后4位与第三个字符的前2位组合并找出对应的结果字符
        dst[i+3] = encode_base64_table[src[j+2]&0x3f]; //取出第三个字符的后6位并找出结果字符
    }
 
    switch(src_len % 3)
    {
        case 1:
            dst[i-2]='=';
            dst[i-1]='=';
            break;
        case 2:
            dst[i-1]='=';
            break;
    }
 
    return len;
}
/**
 * \brief  					
 * \param  
 * \param	  
 * \return dst size
 */
int Base64Decode(const unsigned char *src,unsigned char *dst)
{
	//根据base64表，以字符找到对应的十进制数据
    long len;
    long dst_len,src_len;
    unsigned char *res;
    int i,j;
	
	//计算解码的字符串长度
    len = strlen(src);

	//判断编码后的字符串后是否有=
    if(strstr(src,"=="))
        dst_len = len/4*3-2;
    else if(strstr(src,"="))
        dst_len = len/4*3-1;
    else
        dst_len = len/4;

	//以4个字符为一位进行解码
    for(i=0,j=0;i < len-2;j+=3,i+=4)
    {
        dst[j]=((unsigned char)decode_base64_table[src[i]])<<2 | (((unsigned char)decode_base64_table[src[i+1]])>>4); //取出第一个字符对应base64表的十进制数的前6位与第二个字符对应base64表的十进的
        dst[j+1]=(((unsigned char)decode_base64_table[src[i+1]])<<4) | (((unsigned char)decode_base64_table[src[i+2]])>>2); //取出第二个字符对应base64表的十进制数的后4位与第三个字符对应bas464表的
        dst[j+2]=(((unsigned char)decode_base64_table[src[i+2]])<<6) | ((unsigned char)decode_base64_table[src[i+3]]); //取出第三个字符对应base64表的十进制数的后2位与第4个字符进行组合
	}
	return dst_len;
}

/** @} */

