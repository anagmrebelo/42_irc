#ifndef __CHANNEL_HPP__
#define __CHANNEL_HPP__

// Libraries
#include <map>

// Classes
#include "Client.hpp"

class Channel
{
public:
	// Constructors and Destructors
	~Channel(void);

private:
	// Cannonical Form
	Channel(void);
	Channel(const Channel &src);
	Channel &operator=(const Channel &rhs);

	// Attributes
	std::map<std::string, Client *> _users;
	std::map<std::string, Client *> _operators;
	int _userLimit;
};

#endif
