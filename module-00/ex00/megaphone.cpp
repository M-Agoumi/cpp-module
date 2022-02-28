//
// Created by magoumi on 12/2/2021.
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
