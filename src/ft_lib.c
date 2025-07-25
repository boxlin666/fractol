/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:12:52 by helin             #+#    #+#             */
/*   Updated: 2025/07/14 14:35:41 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	parse_fraction(const char *str, int *i)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			fraction += (str[*i] - '0') / divisor;
			divisor *= 10.0;
			(*i)++;
		}
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	fraction = parse_fraction(str, &i);
	return (sign * (result + fraction));
}
