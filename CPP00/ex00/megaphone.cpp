/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:14:25 by adi-nata          #+#    #+#             */
/*   Updated: 2023/10/27 18:53:09 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(int i = 1; i < ac; i++)
	{
		int len = strlen(av[i]);
		for(int j = 0; j < len; j++)
			std::cout << (char)std::toupper(av[i][j]);
		std::cout << (av[i + 1] ? ' ' : '\n');
	}
	return (0);
}
