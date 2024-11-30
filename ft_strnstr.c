/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:08:58 by mbrighi           #+#    #+#             */
/*   Updated: 2024/11/29 19:00:13 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	l = 0;
	if (little[l] == '\0')
		return ((char *)&big[b]);
	while (big[b] != '\0')
	{
		l = 0;
		while (big[b + l] == little[l] && (b + l) < len && little[l] != '\0')
			l++;
		if (little[l] == '\0')
			return ((char *)&big[b]);
		b++;
	}
	return (NULL);
}
/* int	main(void)
{
	const char	laido[] = "Voglio morire";
	const char	lurido[] = "h";
	size_t		len;
	char *j;
	
	len = 10;
	j = ft_strnstr(laido, lurido, len);

	printf("La sottostringa trovata è: %s\n", j);
} */