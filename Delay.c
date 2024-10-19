

void Delay(unsigned int x)	//@12.000MHz
{
	while(x)
	{
	unsigned char data i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	x--;
	}
	
}
