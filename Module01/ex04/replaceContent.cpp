/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceContent.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:39:17 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/27 15:42:30 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void replaceContent(std::ifstream& infile, std::ofstream& outfile, std::string& s1, std::string& s2)
{
    std::string line;
    while (std::getline(infile, line))
	{
        size_t temp = line.find(s1, 0);
        while (temp != std::string::npos)
		{
            outfile << line.substr(0, temp);
			line.erase(0, temp + s1.length());
            outfile << s2;
            temp = line.find(s1, 0);
		}
		if (!line.empty())
			outfile << line;
		if (!infile.eof())
			outfile << std::endl;
    }
}