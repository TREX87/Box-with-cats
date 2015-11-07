#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <locale> //for "toupper" function

int main()
{
	int count = 0;
	std::string founded = "";
	std::string temp;
	std::stringstream iss;
	std::string word, yourWord, filename;
	int firstLine = 1;

	std::cout << "Enter the name of your file (with the file extention): ";
	std::cin >> filename;
	std::cout << "Enter the word that you are looking for: ";
	std::cin >> yourWord;

	std::ifstream file(filename);
	
	while (getline(file, temp)) //reads every line
	{
	
		iss.str(""); //clears content of stringstream for overwriting
		iss.clear(); //clears stream's error state in every iteration, otherwise no further reads will be attempted
		iss << temp;
	
		
		while (getline(iss, word, ' '))
		{
			count++;
			if (count > 10)
			{
				std::cout << std::endl;
				std::cout << " ";
				count = 1;
			}
			else if (firstLine == 1)
			{
				std::cout << std::endl;
				std::cout << "    ";
				firstLine++;
			}

			if (word.compare(yourWord) == 0)
			{
				founded += "!<";
				for (int i = 0; i < word.length(); i++)
					founded += (char)toupper(word[i]);
				founded += ">";
				std::cout << " " << founded << " ";
			}
			else
				std::cout << " " << word << " ";
		}
		founded = ""; //resets founded string
		//cout << endl;
		
		
		
	}
	std::cout << "\n\n";
	system("Pause");
	return 0;
}
