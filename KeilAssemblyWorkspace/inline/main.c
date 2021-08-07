// ARM COMPILER VERSION 6
	/*
int getSum(int i, int j)
{
	int res=0;
	__asm
	(
	"ADD %[result], %[input_i], %[input_j] \t\n"
	:[result] "=&r" (res)
	:[input_i] "r" (i), [input_j] "r" (j)
	);
	
	return res;
}
*/
// ARM COMPILER VERSION 5
__inline int getSum(int a, int b)
{
	int sum;
	__asm{
		ADD sum, a, b
	}
	return sum;
}
int c=0;

int main(void)
{
	int d,e;
	d = 5;
	e = 4;
	while(1)
	{
		c=getSum(d,e);
	}
}
