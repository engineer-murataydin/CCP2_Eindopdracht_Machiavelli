#pragma once

//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>

//
#include "MVGameController.h"

//
using namespace std;

class MVFileController : public MVGameController
{
public:
	~MVFileController();
	static vector<vector<string>> readInputFile(string filename);
private:
	MVFileController();
	static vector<string> csv_read_row(istream &in, char delimiter);
};

