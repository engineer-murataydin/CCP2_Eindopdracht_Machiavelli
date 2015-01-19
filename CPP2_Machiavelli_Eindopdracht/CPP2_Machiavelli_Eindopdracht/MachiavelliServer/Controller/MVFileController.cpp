//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <locale>
#include <codecvt>
#include <fcntl.h>
#include <io.h>

//
#include "MVFileController.h"

//
using namespace std;
using std::cout;
using std::endl;

MVFileController::MVFileController() {}

MVFileController::~MVFileController() {}

vector<vector<string>> MVFileController::readInputFile(string filename)
{
	ifstream in(filename);
	if (in.fail())
	{
		cout << "File not found" << endl;
		return {};
	}
	vector<vector<string>> data;
	while (in.good())
	{
		data.push_back(csv_read_row(in, ';'));	
	}
	in.close();

	return data;
}

vector<string> MVFileController::csv_read_row(std::istream &in, char delimiter)
{
	std::stringstream ss;
	bool inquotes = false;
	std::vector<std::string> row;
	while (in.good())
	{
		char c = in.get();
		if (!inquotes && c == '"')
		{
			inquotes = true;
		}
		else if (inquotes && c == '"')
		{
			if (in.peek() == '"')
			{
				ss << (char)in.get();
			}
			else
			{
				inquotes = false;
			}
		}
		else if (!inquotes && c == delimiter)
		{
			row.push_back(ss.str());
			ss.str("");
		}
		else if (!inquotes && (c == '\r' || c == '\n'))
		{
			if (in.peek() == '\n') { in.get(); }
			row.push_back(ss.str());
			return row;
		}
		else
		{
			ss << c;
		}
	}
}
