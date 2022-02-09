/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:26:34 by letumany          #+#    #+#             */
/*   Updated: 2022/02/09 10:26:51 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<signal.h>
# include<unistd.h>
# include <stdlib.h>

typedef struct data
{
	int	count;
	int	bit;
}			t_data;

char		*ft_itoa(int n);

#endif