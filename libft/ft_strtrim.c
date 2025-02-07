/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:03:01 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/22 16:03:03 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*toreturn;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_is_in_set(s1[end - 1], set))
		end--;
	toreturn = malloc((end - start + 1) * sizeof(char));
	if (!toreturn)
		return (NULL);
	ft_strlcpy(toreturn, &s1[start], end - start + 1);
	toreturn[end - start] = '\0';
	return (toreturn);
}

/*int	main(void)
{
	printf("%s\n", ft_strtrim("  --- Hola Mundo ---  ", " -"));
}*/
