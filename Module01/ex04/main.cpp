/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:43:38 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/27 15:41:30 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char *av[])
{
    if (ac != 4)
	{
        std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }
	std::string filename = av[1];
	std::ifstream infile(filename.c_str(), std::ifstream::in);
    if (!infile)
	{
        std::cout << "Error: Unable to open input file." << std::endl;
        return (0);
    }
    std::ofstream outfile(filename.append(".replace").c_str(), std::ofstream::trunc);
    if (!outfile)
	{
        std::cerr << "Error: Unable to open or create file." << std::endl;
        return (0);
    }
	std::string s1 = av[2];
    std::string s2 = av[3];
    replaceContent(infile, outfile, s1, s2);

    return 0;
}
