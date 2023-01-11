/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_syntax_err_tok.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:03:59 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/17 12:04:41 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/command_parse.h"

t_cmd_list	*handle_syntax_err_tok(t_parse_token *tok_lst)
{
	char		*str;
	int			err_code;
	t_cmd_list	*ret;
	t_cmd		*cmd;

	if (tok_lst == NULL)
		str = ft_p_strdup("");
	else
		str = ft_p_strdup(tok_lst->string);
	ret = create_empty_t_cmd_list();
	err_code = tok_lst->token_type;
	free_t_parse_token_list(tok_lst);
	if (str == NULL || ret == NULL)
		return (parse_safe_free_multi_str(str, ret, NULL, NULL));
	ret->status = err_code;
	cmd = add_empty_t_cmd_to_list(ret);
	if (cmd == NULL)
		return (parse_safe_free_multi_str(str, ret, NULL, NULL));
	cmd->exec_file_name = str;
	return (ret);
}
