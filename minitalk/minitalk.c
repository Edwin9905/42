/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:57:36 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/24 17:01:08 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(void)
{
	static int	i;
	static int	bit;
	static int	kill_count;

	i = 0;
	bit = 8;
	kill_count = 0;
	while (g_client_data.msg[i] != '\0')
	{
		while (--bit >= 0)
		{
			if ((g_client_data.msg[i] >> bit) & 1)
				kill(g_client_data.opponent_pid, SIGUSR1);
			else
				kill(g_client_data.opponent_pid, SIGUSR2);
			usleep(125);
			kill_count++;
		}
		bit = 8;
		i++;
	}
	ft_putnbr_fd(kill_count, 1);
	ft_putchar_fd('\n', 1);
	if (g_client_data.msg[i] == '\0')
	{
		while (bit-- > 0)
		{
			kill(g_client_data.opponent_pid, SIGUSR2);
			usleep(125);
		}
		pause();
	}
}

int	main(void)
{
	char	*message;

	//server start
	server();
	//client strat
	client();
}
