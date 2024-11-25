#ifndef COLOR_HPP
# define COLOR_HPP

// thanks Jgreau for the header

# define END_ "\e[0m"

// format
# define BOLD_ "\e[1m"
# define DIM_ "\e[2m"
# define ITALIC_ "\e[3m"
# define UDLINE_ "\e[4m"
# define BLINK_ "\e[5m"
# define INVERT_ "\e[7m"
# define STRIKE_ "\e[9m"
# define UDLINE2_ "\e[21m"
# define OVLINE_ "\e[53m"

// text color
# define DEFLT_ "\e[39m"
# define BLACK_ "\e[30m"
# define RED_ "\e[31m"
# define GREEN_ "\e[32m"
# define YELLOW_ "\e[33m"
# define BLUE_ "\e[34m"
# define MAGENTA_ "\e[35m"
# define CYAN_ "\e[36m"
# define LGRAY_ "\e[37m"

// light text color
# define DGRAY_ "\e[90m"
# define LRED_ "\e[91m"
# define LGREEN_ "\e[92m"
# define LYELLOW_ "\e[93m"
# define LBLUE_ "\e[94m"
# define LMAGENTA_ "\e[95m"
# define LCYAN_ "\e[96m"
# define WHITE_ "\e[97m"


// light background color
# define DGRAYB_ "\e[100m"
# define LREDB_ "\e[101m"
# define LGREENB_ "\e[102m"
# define LYELLOWB_ "\e[103m"
# define LBLUEB_ "\e[104m"
# define LMAGENTAB_ "\e[105m"
# define LCYANB_ "\e[106m"
# define WHITEB_ "\e[107m"

# define RESET_ "\e[2K\r"

#endif