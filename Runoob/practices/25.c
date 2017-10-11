// 求1! + 2! + 3! + ... + 20!的和

#include <stdio.h>

int main()
{
    int i;
    long long sum, mix;
    sum=0, mix=1;
    for(i = 1; i <= 20; i ++)
    {
        mix = mix * i;
		// printf("%lld\t%lld\n", mix, sum);
        sum = sum + mix;
    }
    printf("%lld\n", sum);

	return 0;
}
