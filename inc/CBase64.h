/**
 *  Copyright (c) 2015, Everhigh Tech. Ltd. Co.
 *  		All rights reserved
 */

/** 
 * \addtogroup CLibrary
 * @{
 */

/**
 * \defgroup Base64 decode/encode
 * @{
 */
 
/**
 * \file		  CBase64.h
 * \brief		  Base64 decode/encode
 *
 * \author		zhjxy <zhanghuijun@everhigh.com.cn>
 * \version	  V0.0.1
 * \date		  2018-9-21
 * \license	
 *------------------------------------------------------------------*
 *	Change History :
 *  <Date>     | <Version> | <Author>      | <Description>          *
 *------------------------------------------------------------------*
 *  2018/09/21 | 1.0.0.0   | zhjxy       | Create file            *
 */
#ifndef _CBase64_H_
#define _CBase64_H_

#define CBASE64_VER "0.0.2"
#include "CBase64CFG.h"


int Base64Encode(const unsigned char *src,unsigned int src_len,unsigned char *dst);
int Base64Decode(const unsigned char *src,unsigned char *dst);




#endif /* _CBase64_H_ */
/** @} */
/** @} */

