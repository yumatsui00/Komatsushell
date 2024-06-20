/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:51:35 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/06/20 20:47:08 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_space_only(char *s)
{
	while (*s)
	{
		if (*s != ' ')
			return (0);
		s++;
	}
	return (1);
}

int	is_sankaku(char *item)
{
	if (!ft_strcmp(item, "<") || !ft_strcmp(item, ">") || !ft_strcmp(item, "<<")
		|| !ft_strcmp(item, ">>"))
		return (1);
	return (0);
}

int	check_semq_komatsu(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{

		i++;
	}
	return (0);
}

t_cmd	**lexer(char *before_line, char **ep)
{
	char	**line;
	t_cmd	**ret;

	if (!ft_strcmp(before_line, "") || is_space_only(before_line))
		return (free(before_line), NULL);
	before_line = cut_in_main(before_line);
	if (!before_line)
		return (NULL);
	line = ft_split_for_lexer(before_line);
	free(before_line);
	if (!line || !*line)
		return (NULL);
	line = expand_ep_main(line, ep);
	if (!line)
		return (NULL);
	if (cut_or_read(line))
		return (free_double_ptr(line), (NULL));
	if (find_syntax_error(line))
		return (NULL);
	line = rearranges_main(line);
	if (!line)
		return (free_double_ptr(line), (NULL));
	line = union_friends(line);
	ret = make_cmd_line(line);
	return (ret);
}

// int	main(int ac, char **av, char **ep)
// {
// 	t_cmd	**ret;

// 	ret = lexer(av[1], ep);
// 	printf("完璧じゃ！！\n");
// 	debug_cmd(ret);
// 	// if (ret)
// 	// {
// 	// 	for (int i = 0; ret[i] != NULL; i++)
// 	// 		printf("ret[%d]: %s\n", i, ret[i]);
// 	// }
// 	return (0);
// }
