#include "assist_func.h"

std::string StrToBin(const std::string& str) {
	int len = str.length();
	std::string res = "";
	for (int i = 0; i < len; i++) {
		char ch = str[i];
		for (int j = 7; j >= 0; j--) {
			res += std::to_string((ch >> j) & 1);
		}
	}
	return res;
}

std::string BinToStr(const std::string& binary) {
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
	return res;
}

std::vector<std::string> ReadBinaryFileToString(const std::string& filename) {\
	std::vector<std::string>chunk;
	std::ifstream file(filename, std::ios::binary);
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return chunk;
	}
	while (!file.eof()) {
		chunk.push_back(FileChunking(file));
	}
	file.close();
	return chunk;
}



std::string FileChunking(std::ifstream& file) {
	char buffer[BATCHSIZE];
	std::string res = "";
	file.read(buffer, BATCHSIZE);
	for (size_t i = 0; i < BATCHSIZE; i++) {
		res += StrToBin(std::to_string(buffer[i]));
	}
	return res;
}

void MessagePreProcessing(std::vector<std::string>& chunk) {
	for (int i = 0; i < chunk.size(); i++) {
		int len = chunk[i].length();
		int k = calculateK(len);
		chunk[i] += "1";
		for (; k > 0; k--) {
			chunk[i] += "0";
		}
		chunk[i] += intToBinary64(len);
	}

}

int calculateK(int l) {
	int k = (448 - (l + 1)) % 512;
	return k < 0 ? k + 512 : k;
}

std::string intToBinary64(int num) {
	std::string binary;
	for (int i = 63; i >= 0; --i) {
		binary += ((num >> i) & 1) ? '1' : '0';
	}
	return binary;
}