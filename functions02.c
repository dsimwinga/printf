#include "main.h"

/**
*print_pointer - Prints the value of a pointer variable
*@types: List a of arguments
*@buffer: Buffer array to handle print
*@flags:  Calculates active flags
*@width: get width
*@precision: Precision specification
*@size: Size specifier
*Return: Number of chars printed.
*/

int print_pointer(va_list types, char buffer[],

	int flags, int width, int precision, int size)

{
	char extra_c = 0, padd = ' ';

	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */

	unsigned long num_addrs;

	char map_to[] = "0123456789abcdef";

	void *addrs = va_arg(types, void *);


	UNUSED(width);

	UNUSED(size);


	if (addrs == NULL)

		return (write(1, "(nil)", 5));


	buffer[BUFF_SIZE - 1] = '\0';

	UNUSED(precision);


	num_addrs = (unsigned long)addrs;


	while (num_addrs > 0)

	{

		buffer[ind--] = map_to[num_addrs % 16];

		num_addrs /= 16;

		length++;

	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))

		padd = '0';

	if (flags & F_PLUS)

		extra_c = '+', length++;

	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/

	return (write_pointer(buffer, ind, length,

		width, flags, padd, extra_c, padd_start));
}
/**
*print_non_printable - Prints ascii codes in hexa of non printable chars
*@types: Lista of arguments
*@buffer: Buffer array to handle print
*@flags:  Calculates active flags
*@width: get width
*@precision: Precision specification
*@size: Size specifier
*Return: Number of chars printed
*/

int print_non_printable(va_list types, char buffer[],

	int flags, int width, int precision, int size)

{
	int t = 0, offset = 0;

	char *str = va_arg(types, char *);


	UNUSED(flags);

	UNUSED(width);

	UNUSED(precision);

	UNUSED(size);


	if (str == NULL)

		return (write(1, "(null)", 6));

	while (str[t] != '\0')

	{
		if (is_printable(str[t]))

			buffer[t + offset] = str[t];
		else

			offset += append_hexa_code(str[t], buffer, t + offset);

		t++;
	}

	buffer[t + offset] = '\0';


	return (write(1, buffer, t + offset));
}
/**
*print_reverse - Prints reverse string.
*@types: Lista of arguments
*@buffer: Buffer array to handle print
*@flags:  Calculates active flags
*@width: get width
*@precision: Precision specification
*@size: Size specifier
*Return: Numbers of chars printed
*/

int print_reverse(va_list types, char buffer[],

	int flags, int width, int precision, int size)

{
	char *str;

	int t, count = 0;


	UNUSED(buffer);

	UNUSED(flags);

	UNUSED(width);

	UNUSED(size);


	str = va_arg(types, char *);


	if (str == NULL)

	{
		UNUSED(precision);


		str = ")Null(";

	}

	for (t = 0; str[t]; t++)

		;

	for (t = t - 1; t >= 0; t--)

	{
		char z = str[t];


		write(1, &z, 1);

		count++;
	}
	return (count);
}

/**
*print_rot13string - Print a string in rot13.
*@types: Lista of arguments
*@buffer: Buffer array to handle print
*@flags:  Calculates active flags
*@width: get width
*@precision: Precision specification
*@size: Size specifier
*Return: Numbers of chars printed
*/

int print_rot13string(va_list types, char buffer[],

	int flags, int width, int precision, int size)

{
	char x;

	char *str;

	unsigned int t, j;

	int count = 0;

	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";


	str = va_arg(types, char *);

	UNUSED(buffer);

	UNUSED(flags);

	UNUSED(width);

	UNUSED(precision);

	UNUSED(size);


	if (str == NULL)

		str = "(AHYY)";

	for (t = 0; str[t]; t++)

	{

		for (j = 0; in[j]; j++)

		{

			if (in[j] == str[i])

			{
				x = out[j];

				write(1, &x, 1);

				count++;

				break;

			}
		}

		if (!in[j])

		{
			x = str[t];

			write(1, &x, 1);

			count++;
		}
	}

	return (count);
}
