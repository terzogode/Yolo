/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:47:48 by mbrighi           #+#    #+#             */
/*   Updated: 2024/11/22 13:48:12 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	f;

	f = 0;
	while (s[f] != '\0')
		f++;
	while (f >= 0)
	{
		if (s[f] == (char)c)
			return ((char *)&s[f]);
		f--;
	}
	if (s[f] == (char)c)
		return ((char *)&s[f]);
	return (NULL);
}
/* int main (void)
{
	const char	s[] = "Please kill me";
	int			c = 'o';

	char *k = ft_strrchr(s, c);

	printf("la prima occorrenza di %c in e' a %s\n", c, k);
} */
