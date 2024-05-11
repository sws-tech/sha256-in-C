#include "assist_func.h"

std::string StrToBin(std::string str) {
	int len = str.length();
	std::string res = "";
	for (int i = 0; i < len; i++) {
		char ch = str[i];
		for (int j = 7; j >= 0; j--) {
			res += std::to_string((ch >> j) & 1);
		}
	}
	std::cout << res << std::endl;
	return res;
}

std::string BinToStr(std::string binary) {
	int len = binary.length();
	std::string res;
	for (int i = 0; i < len/8; i++) {
		char temp = 0;
		for (int j = 0; j < 8; j++) {
			temp = (temp << 1) + int(binary[i * 8 + j]);
			//temp = (temp << 1) + binary[i * 8 + j] - '0';
			//一个尝试分支
		}
		res += std::to_string(temp);
	}
	std::cout << res << std::endl;
	return res;
}

