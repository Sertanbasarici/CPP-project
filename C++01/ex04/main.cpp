/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:10:50 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/14 09:45:58 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

std::string	processTheLine(std::string line, std::string toFind, std::string toReplace)
{
	size_t		pos;
	std::string	result;

	pos = 0;
	while ((pos = line.find(toFind, pos)) != std::string::npos)
	{
		result = line.substr(0, pos);
		result += toReplace;
		result += line.substr(pos + toFind.length());
		line = result;
		pos += toReplace.length();
	}
	return (line);
}

int main(int argc, char *argv[])
{
	std::string		fileName;
	std::string		toFind;
	std::string		toReplace;
	std::fstream	inputFile;
	std::fstream	outputFile;
	std::string		line;

	if (argc == 4)
	{
		fileName = argv[1];
		toFind = argv[2];
		toReplace = argv[3];
		inputFile.open(argv[1], std::ios::in);
		if (inputFile.is_open())
		{
			outputFile.open((fileName + ".replace").c_str(), std::ios::out);
			while (getline(inputFile, line))
			{
				if (!inputFile.eof())
					line += "\n";
				line = processTheLine(line, toFind, toReplace);
				outputFile << line;
			}
		}
	}
	else
		std::cout <<"Invalid number of argument!!!"<< std::endl;
	return (0);
}