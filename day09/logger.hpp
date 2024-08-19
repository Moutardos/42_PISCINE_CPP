#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include "color.hpp"

# define SET_LOGGER(x)

#  define LOGGER(s) do { \
	s << std::endl; \
} while (0) \

#  define LOG_ERROR(s) do { \
	LOGGER(std::cerr  << LREDB_ << BLACK_ << "ERROR:" << END_ << " " << s); \
} while (0) \

#  define LOG_WARNING(s) do { \
	LOGGER(std::cerr << LRED_ << "WARNING: " << END_ << s); \
} while (0) \

#  define LOG_INFO(s) do { \
	LOGGER(std::clog << LBLUE_ << "INFO: " << END_ << s); \
} while (0) \


# ifndef DEBUG

#  define LOG_DEBUG(s)
#  define LOG_TRACE(s)

# else
#  define LOG_DEBUG(s) do { \
	LOGGER(std::clog << LGREEN_ << "DEBUG: " << END_ << s); \
} while (0) \

#  define LOG_TRACE(s) do { \
	LOGGER(std::clog << "TRACE: " << s); \
} while (0) \

# endif

#endif