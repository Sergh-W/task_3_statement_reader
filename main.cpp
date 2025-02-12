#include <iostream>
#include <fstream>
#include <string>

int main ()
{
    int cash = 0, sum = 0, max = 0;
    std::string name, fName, surname, fSurname, date, fDate, filePath;

    std::ifstream list;
    std::cout << "Enter the path to the statement\n"
                 "you want to open (Example: C:\\...\\text.txt):" << std::endl;
    std::cin >> filePath;
    list.open(filePath);

    if (!list.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
    }
    else
    {
        while (!list.eof())
        {
            list >> name;
            list >> surname;
            list >> cash;
            list >> date;

            sum += cash;

            if (max < cash)
            {
                max = cash;
                fName = name;
                fSurname = surname;
                fDate = date;
            }
        }
    }

    std::cout << "According to the statement, total paid: " << sum << std::endl;
    std::cout << "Maximum amount paid: " << max << std::endl;
    std::cout << "Recipient: " << fName << " " << fSurname << std::endl;
    std::cout << "Date: " << fDate << std::endl;

    list.close();
}
