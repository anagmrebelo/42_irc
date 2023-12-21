#ifndef __CHANNEL_HPP__
#define __CHANNEL_HPP__

// Libraries
#include <iostream>
#include <map>

// Classes
#include "Client.hpp"

class Channel
{
public:
	// Constructors and Destructors
	Channel(std::string name, Client &founderClient, std::string key);
	~Channel(void);

	// Getters
	std::string const &getName() const;
	std::string const &getKey() const;
	std::string const &getTopic() const;
	std::map<std::string, Client *> const &getUsers() const;
	std::map<std::string, Client *> const &getOperators() const;
	std::map<std::string, Client *> const &getInvited() const;
	std::string getModes();
	bool getI(void);
	bool getT(void);
	bool getK(void);
	bool getO(void);
	bool getL(void);

	// Setters
	void addUser(Client *client);
	void addInvited(Client *client);
	void clearInvited();
	void removeUser(std::string nickName);
	void removeOperator(std::string nickName);
	void setTopic(std::string topic);
	void setI(bool mode);
	void setT(bool mode);
	void setK(bool mode);
	void setO(bool mode);
	void setL(bool mode);

	// Methods
	void sendMsg(std::string msg);
	void sendMessage(Client const *client, std::string const &msg);
	void addModes(std::string modes);
	void removeModes(std::string modes);
	bool isOperator(std::string nickName);
	bool isOnChannel(std::string nickName);

private:
	// Cannonical Form
	Channel(void);
	Channel(const Channel &src);
	Channel &operator=(const Channel &rhs);

	// Attributes
	std::string _name;
	std::string _topic;
	std::string _key;
	std::map<std::string, Client *> _users;
	std::map<std::string, Client *> _operators;
	std::map<std::string, Client *> _invited;
	int _userLimit;

	bool _i;
    bool _t;
    bool _k;
    bool _o;
    bool _l;
};

#endif
