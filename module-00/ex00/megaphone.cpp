/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:03:02 by magoumi           #+#    #+#             */
/*   Updated: 2022/02/28 19:03:03 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by magoumi on 22/2/2022.
//
#include <iostream>
#include <string>

std::string strToUpper(std::string str)
{
    int length = str.length();
    for(int i=0; i < length; i++)
        if (97 <= str[i] && str[i] <= 122)
            str[i] -= 32;

    return str;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    int i = 1;

    while (i < argc)
    {
		std::cout << strToUpper(argv[i]);
        i++;
    }
	std::cout << std::endl;

    return 0;
}
