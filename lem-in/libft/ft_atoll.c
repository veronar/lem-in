/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:27:34 by vesingh           #+#    #+#             */
/*   Updated: 2019/08/20 13:02:51 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_atoll: converts string to 'long long'.
** we can then use this to check if the given number is within the int range.
** long long range: [−9223,372,036,854,775,807 to +9,223,372,036,854,775,807]
** int range: [-2,147,483,648, to 2,147,483,647]
*/

long long	ft_atoll(char *str)
{
	long long	i;
	long long	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
