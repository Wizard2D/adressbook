#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
int main()
{
    std::cout << "Do you wanna add to an existing address book(1), Create a new address book(2) or display an existing address book(3)";
	std::string sroption;
	std::getline(std::cin, sroption);
	int option = std::stoi(sroption);
	if (option == 1) {  
		std::cout << "Choose an address book: \n";
		for (auto file : std::filesystem::directory_iterator("")) {
			if (file.path().extension() == ".abd") {
				std::cout << file.path().filename();
			}
		}
		std::string chs;
		std::getline(std::cin, chs);
		if (fs::exists(chs)) {
			std::ofstream fl = std::ofstream();
			fl.open(chs, std::ios_base::app);
			std::cout << "How many addresses will you add?";
			int aCount;
			std::cin >> aCount;
			for (int v = 0; v < aCount + 1; v++) {
				std::cout << "Enter the person's name and telephone number: ";
				std::string nnpn = "";
				std::getline(std::cin, nnpn);
				fl << nnpn+" ";
			}
			fl.close();
		}
	}
	if (option == 2) {
		std::cout << "Enter Address Book Name: \n";
		std::string bname;
		std::getline(std::cin, bname);
		std::string fullPath = bname;
		std::ofstream file = std::ofstream(fullPath+".abd");
		std::cout << "How many addresses will this book contain?: \n";
		int addressCount;
		std::cin >> addressCount;
		for (int i = 0; i < addressCount+1; i++) {
			std::cout << "Enter the name and phone number of the person: \n";
			std::string name;
			std::getline(std::cin, name);
			file << name+" ";
		}
	}
	if(option == 3){
		std::cout << "Choose an address book: \n";
		for (auto file : std::filesystem::directory_iterator("")) {
			if (file.path().extension() == ".abd") {
				std::cout << file.path().filename();
			}
		}
		std::string chs;
		std::getline(std::cin, chs);
		if (fs::exists(chs)) {
			std::ifstream fl = std::ifstream();
			fl.open(chs);
			std::string fileContent;
			while (std::getline(fl, fileContent)) {
				std::cout << fileContent;
			}
			fl.close();
		}
	}
}
