#include "stdio.h"
#include "stdint.h"
#include "CBase64.h"

int main(void)
{
	char input_str[10]="s";
	char encode_base64_str[10], encode_base64_len = 0;
	char decode_base64_str[10],decode_base64_len = 0;
	int i=0,bin_size=7;

	printf("Base64 Test, Version:%s\n",CBASE64_VER);

	printf("\nstring base64 test*******************start***************\n");
	encode_base64_len = Base64Encode(input_str,strlen(input_str),encode_base64_str);
	decode_base64_len = Base64Decode(encode_base64_str,decode_base64_str);
	printf("input:%s endcode:%s decode:%s\n",input_str,encode_base64_str,decode_base64_str);
	printf("string base64 test*******************end***************\n");

	printf("\nbin base64 test*******************start***************\n");
	memcpy(input_str,"\0\1\2\3\4\5\6\7\0",bin_size);
	encode_base64_len = Base64Encode(input_str,bin_size,encode_base64_str);
	decode_base64_len = Base64Decode(encode_base64_str,decode_base64_str);
	printf("input hex:");
	for(i=0;i<bin_size;i++)
		printf("%02x ",input_str[i]);
	printf("\nendcode:%s\n",encode_base64_str);
	printf("decode hex:");
	for(i=0;i<bin_size;i++)
		printf("%02x ",input_str[i]);
	printf("\n");
	printf("bin base64 test*******************end***************\n");

	return 0;
}
