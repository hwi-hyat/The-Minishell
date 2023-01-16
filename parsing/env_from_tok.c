/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_from_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:43:32 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:41:32 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*parse_env_from_tok_sub_question(t_parse_token *tok)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_p_itoa(get_exitcode());
	str2 = ft_p_substr(tok->string, 2, ft_p_strlen(tok->string));
	if (str1 == NULL || str2 == NULL)
		return (parse_safe_free_multi_str(str1, str2, NULL, NULL));
	str3 = ft_p_strjoin(str1, str2);
	parse_safe_free_multi_str(str1, str2, NULL, NULL);
	if (str3 == NULL)
		return (NULL);
	free(tok->string);
	tok->string = str3;
	return (NULL);
}

char	*parse_env_from_tok_sub_set_env_null(t_parse_token *tok, char *str)
{
	char	*str1;

	str1 = ft_p_strjoin("$", str);
	if (str1 == NULL)
		return ("");
	tok->is_null = TYPE_ARGV_NULL;
	tok->original_str = str1;
	return ("");
}

void	parse_env_from_tok_sub(t_parse_token *tok, int end)
{
	char	*str;
	char	*str2;
	char	*str3;

	str = tok->string;
	while (str[end] == '_' || (str[end] >= 'A' && str[end] <= 'Z') || (str[end]
			>= 'a' && str[end] <= 'z') || (str[end] >= '0' && str[end] <= '9'))
		end++;
	str2 = ft_p_substr(str, 1, end - 1);
	if (str2 == NULL)
		return ;
	str3 = ft_getenv(str2);
	if (str3 == NULL)
		str3 = parse_env_from_tok_sub_set_env_null(tok, str2);
	free(str2);
	str3 = ft_strdup(str3);
	if (str3 == NULL)
		return ;
	tok->string = str3;
	str3 = ft_p_substr(str, end, ft_p_strlen(str));
	add_token(&tok, 1, tok->token_type, str3);
	parse_safe_free_multi_str(str, str3, NULL, NULL);
	tok->token_type = TYPE_TOKEN_ARGV;
	if (tok->string[0] != '\0')
		parse_tokenize_space_single_tok(tok);
}

void	parse_env_from_tok(t_parse_token *tok)
{
	char			**split_str;
	t_parse_token	*next;
	int				index;

	split_str = ft_p_split_custom(tok->string, '$');
	if (split_str == NULL)
		return ;
	free (tok->string);
	tok->string = ft_p_strdup(split_str[0]);
	index = 0;
	while (split_str[++index] != NULL)
		add_token(&tok, index, tok->token_type, split_str[index]);
	parse_safe_free_two_d_char(split_str, -1);
	while (--index >= 0 && tok != NULL)
	{
		next = tok->next;
		if (tok->string[0] == '$' && (tok->string[1] == '_'
				|| (tok->string[1] >= 'A' && tok->string[1] <= 'Z')
				|| (tok->string[1] >= 'a' && tok->string[1] <= 'z')))
			parse_env_from_tok_sub(tok, 1);
		else if (tok->string[0] == '$' && tok->string[1] == '?')
			parse_env_from_tok_sub_question(tok);
		tok = next;
	}
}

void	env_from_tok(t_parse_token *tok_lst)
{
	t_parse_token	*next;

	while (tok_lst != NULL)
	{
		next = tok_lst->next;
		if (tok_lst->token_type == TYPE_TOKEN_CHUNK)
			parse_env_from_tok(tok_lst);
		tok_lst = next;
	}
}
