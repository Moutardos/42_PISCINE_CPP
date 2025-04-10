#include "FileManip.hpp"

FileManip::FileManip (std::string fname) : _fname(fname) {

	this->_file.open(this->_fname.c_str());
}

FileManip::FileManip (void) {}

FileManip::~FileManip (void) {

	this->_file.close();
}

void	FileManip::open (std::string fname) {

	this->_file.open(fname.c_str());
	this->_fname = fname;
}

bool	FileManip::is_open (void) {

	return (this->_file.is_open());
}

bool	FileManip::replace (std::string str1, std::string str2) {

	std::ofstream	fileReplace;
	std::string		newText;
	std::string		line;
	size_t			pos = 0;

	fileReplace.open((this->_fname + ".replace").c_str());
	if (!this->is_open() || !fileReplace.is_open())
		return (false);
	while (std::getline(this->_file, line))
	{
		newText += line;
		newText += '\n';
	}
	newText.substr(0, newText.length() - 1);
	if (str1 != "")
	{
		do
		{
			pos = newText.find(str1, pos);
			if (pos != std::string::npos)
			{
				newText.erase(pos, str1.length());
				newText.insert(pos, str2);
				pos += str2.length();
			}
		} while (pos != std::string::npos && pos < newText.length());
	}
	fileReplace << newText;
	fileReplace.close();
	return (true);
}