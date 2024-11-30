/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:35:30 by mbrighi           #+#    #+#             */
/*   Updated: 2024/11/29 15:37:00 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (*s != '\0')
	{
		s++;
		lenght++;
	}
	return (lenght);
}
/* int main (void)
{
	int b;

	char k[10] = "cicocico";
	b = ft_strlen(k);
	printf("%d\n", b);
	return (0);
} */