/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:57:36 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/21 13:10:05 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main()
{
	char	*message;

	//server start
	server();
	//client strat
	client();
}
