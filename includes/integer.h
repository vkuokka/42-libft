#ifndef INTEGER_H

# define INTEGER_H

int		ft_atoi(const char *str);
int		ft_count_digits(long long nbr);
char	*ft_ftoa(long double f, int pre);
char	*ft_itoa_base(unsigned long long value, int base);
char	*ft_itoa(long long n);

#endif