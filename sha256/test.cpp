#include "assist_func.h"

int main() {
	std::string filename = "[M-TEAM]BANK-168.torrent";
	std::vector<std::string>temp = ReadBinaryFileToString(filename);
	MessagePreProcessing(temp);
	std::cout << "";
	system("pause");
	return 0;
}