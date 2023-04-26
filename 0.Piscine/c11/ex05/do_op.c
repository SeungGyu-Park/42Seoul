#include "ft_atoi.h"

char	is_valid_op(char *operator)
{
	char op;

	if (ft_strlen(operator) == 1)
	{
		op = operator[0];
		if (op == '+' || op == '-' || op == '/' || op == '*' || op == '%')
			return (op);
	}
	return (0);
}

void	calculate(int x, int y, char op)
{
	if (op == '-')
		ft_putnbr(x - y);
	else if (op == '+')
		ft_putnbr(x + y);
	else if (op == '*')
		ft_putnbr(x * y);
	else if (op == '/')
	{
		if (y == 0)
		{
			ft_putstr("Stop : division by zero\n");
			return ;
		}
		ft_putnbr(x / y);
	}
	else if (op == '%')
	{
		if (y == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return ;
		}
		ft_putnbr(x % y);
	}
	ft_putchar('\n');
}
int	main(int argc, char **argv)
{
	 int	x;
	 int	y;
	char	op;

	if (argc == 4)
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[3]);
		if (!(op == is_valid_op(argv[2]);
			ft_putchar('\n');
		else
			calculate(x, y, op);
	}
	return (0);
}
