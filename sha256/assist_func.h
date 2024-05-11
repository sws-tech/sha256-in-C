#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "const.h"

std::string StrToBin(const std::string&);
std::string BinToStr(const std::string&);

std::vector<std::string> ReadBinaryFileToString(const std::string&);

std::string FileChunking(std::ifstream&);

int calculateK(int l);
std::string intToBinary64(int num);

void MessagePreProcessing(std::vector<std::string>& chunk);