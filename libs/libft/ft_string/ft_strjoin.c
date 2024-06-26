/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:59:53 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/21 15:42:39 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Joins s1 and s2 into a new string. 
This function automatically allocates memory for the resulting joined string 
and, if memory allocation fails, this function will return NULL */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len;
	char	*str;

	len_s1 = ft_strlen(s1);
	len = ft_strlen(s2) + len_s1;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len + 1);
	return (str);
}

/* Joins s1 and s2 into a new string.
s1 is copied with at most s1_n chars, and s2 is copied with at most s2_n chars. 
If the specified s1_n and/or s2_n have a value of -1, then the default lengths 
of s1 and/or s2 will be used.
This function automatically allocates memory for the resulting joined string 
and, if memory allocation fails, this function will return NULL */
char	*ft_strljoin(char const *s1, long s1_n, char const *s2, long s2_n)
{
	long	len_s1;
	long	len_s2;
	long	len;
	char	*str;

	len_s1 = ft_strlen(s1);
	if (len_s1 > s1_n && s1_n != -1)
		len_s1 = s1_n;
	len_s2 = ft_strlen(s2);
	if (len_s2 > s2_n && s2_n != -1)
		len_s2 = s2_n;
	len = len_s1 + len_s2;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len + 1);
	return (str);
}
