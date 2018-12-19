#include "stdio.h"
#include "stdint.h"
#include "ip_check.h"

int main(void)
{
	//char test[3][10];
	//printf("%ld %ld\n",sizeof(test),sizeof(test[0]));
	char test_ip1[] = "192.168.0.1";
	char test_ip2[] = "192.168.1";
	char test_ip3[] = "192.168.a.1";
	char test_ip4[] = "192.168.0.1.0";

	printf("ip:(%s) \tcheck:%d\n",test_ip1,ip_check(test_ip1));
	printf("ip:(%s) \tcheck:%d\n",test_ip2,ip_check(test_ip2));
	printf("ip:(%s) \tcheck:%d\n",test_ip3,ip_check(test_ip3));
	printf("ip:(%s) \tcheck:%d\n",test_ip4,ip_check(test_ip4));

	return 0;
}
