#include <stdio.h>

void	number_name(int num)
{
if (num == 1)
	write(1, 'one', 3);
if (num == 2)
	write(1, 'two', 3);
if (num == 3)
	write(1, 'three', 5);
if (num == 4)
	write(1, 'four', 4);
if (num == 5)
	write(1, 'five', 4);
if (num == 6)
	write(1, 'six', 3);
if (num == 7)
	write(1, 'seven', 5);
if (num == 8)
	write(1, 'eight', 5);
if (num == 9)
	write(1, 'nine', 4);
}

void	pos_num(int num)
{
	if (num == 3)
	write(1, 'hundred', 7);
if (num == 4)
	write(1, 'thousand', 8);
if (num == 5)
	write(1, 'thousand', 8);
if (num == 5)
	write(1, 'millon', 5);
}

int counter(int num)
{
	int res_num;
	int num_name;

	res_num = 0;
	while ( num < 10)
	{
		number_name = num % 10;
		res_num++;
		num / 10;
	}
	number_name(int num_name);
	pos_num(int res_num);
}

/*
int main() {
    int number = 10345;
    int digit;

    printf("Número original: %d\n", number);
    printf("Dígitos del número:\n");

    while (number > 0) {
        digit = number % 10;
        printf("%d\n", digit);
        number = number / 10;
    }

    return 0;
}
*/
int len_count (int num)
{	int len;

	len = 0;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return(len);
}

int main ()
{
	int len;
	len = len_count(num);
	array = (int) malloc(len * sizeof(int));

	while (len > i)
	{
		array [i] = num%10;
	}

}
