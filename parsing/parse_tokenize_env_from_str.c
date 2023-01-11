/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize_env_from_str.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:39:51 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/22 01:22:06 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"

char			*parse_env_from_str_sub(char *str, int end);
char			*parse_env_from_str_sub_question(char *str);

char	*parse_env_from_str(char *str)
{
	char	**split_str;
	char	*ret;
	char	*str_tmp;
	char	*str_tmp2;
	int		index;

	split_str = ft_p_split_custom(str, '$');
	if (split_str == NULL)
		return (str);
	index = -1;
	ret = ft_p_strdup("");
	while (split_str[++index] != NULL && ret != NULL)
	{
		str_tmp2 = ft_p_strdup(split_str[index]);
		if (str_tmp2[0] == '$')
			str_tmp2 = parse_env_from_str_sub(str_tmp2, 0);
		str_tmp = ret;
		ret = ft_p_strjoin(ret, str_tmp2);
		parse_safe_free_multi_str(str_tmp, str_tmp2, NULL, NULL);
	}
	parse_safe_free_two_d_char(split_str, -1);
	if (ret == NULL)
		return (str);
	free(str);
	return (ret);
}

char	*parse_env_from_str_sub(char *str, int end)
{
	char	*str2;
	char	*str3;

	if (str[++end] != '_' && !(str[end] >= 'A' && str[end] <= 'Z')
		&& !(str[end] >= 'a' && str[end] <= 'z'))
		return (parse_env_from_str_sub_question(str));
	while (str[end] == '_' || (str[end] >= 'A' && str[end] <= 'Z') || (str[end]
			>= 'a' && str[end] <= 'z') || (str[end] >= '0' && str[end] <= '9'))
		end++;
	str2 = ft_p_substr(str, 1, end - 1);
	if (str2 == NULL)
		return (str);
	str3 = ft_getenv(str2);
	free(str2);
	if (str3 == NULL)
		str3 = "";
	str2 = ft_substr(str, end, ft_strlen(str));
	str3 = ft_strjoin(str3, str2);
	parse_safe_free_multi_str(str2, NULL, NULL, NULL);
	if (str3 == NULL)
		return (str);
	free (str);
	return (str3);
}

char	*parse_env_from_str_sub_question(char *str)
{
	char	*str1;
	char	*str2;
	char	*str3;

	if (str[1] != '?')
		return (str);
	str1 = ft_p_itoa(get_exitcode());
	str2 = ft_p_substr(str, 2, ft_strlen(str));
	if (str1 == NULL || str2 == NULL)
	{
		parse_safe_free_multi_str(str1, str2, NULL, NULL);
		return (str);
	}
	str3 = ft_p_strjoin(str1, str2);
	parse_safe_free_multi_str(str1, str2, NULL, NULL);
	if (str3 == NULL)
		return (str);
	free(str);
	return (str3);
}
