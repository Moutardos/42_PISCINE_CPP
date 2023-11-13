#ifndef FILEMANIP_H
# define FILEMANIP_H

# include <iostream>
# include <fstream>
# include <string>

class FileManip {

public :
	FileManip	(std::string fname);
	FileManip	(void);
	~FileManip	(void);

	void	open (std::string fname);
	bool	is_open (void);
	bool	replace (std::string str1, std::string str2);

private :
	std::string		_fname;
	std::fstream 	_file;

};

#endif