#include <stdio.h>

#define  PI	3.14

#define M	(2+3)

//请定义一个宏，宏名自定义，宏体为一年的秒数（不考虑特殊年份）

#define SEC_YEAR1	(60*60*24*365)
#define SEC_YEAR2	(60LL*60LL*24LL*365LL)


int main()
{

	printf("%d\n",M*M);

	return 0;
}


