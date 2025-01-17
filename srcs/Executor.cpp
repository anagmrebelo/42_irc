#include "Executor.hpp"

// Constructors
Executor::Executor(void) {}

Executor::Executor(Server *srv, Command *cmd) : _srv(srv), _cmd(cmd) {}

Executor::Executor(const Executor &src)
{
	(void)src;
	return;
}

// Destructors
Executor::~Executor(void)
{
	return;
}

// Assignation Overload
Executor &Executor::operator=(const Executor &rhs)
{
	(void)rhs;
	return *this;
}

// Getters
Server *const &Executor::getSrv() const
{
	return _srv;
}

// Methods
bool Executor::unregisteredClient(Client *client)
{
	if (client->getStatus() == PRE_REGISTER)
	{
		client->sendMsg(ERR_NOTREGISTERED(client->getUserName()));
		return true;
	}
	return false;
}

bool Executor::illegalParamNb(std::vector<std::string> params, Client *client, size_t min, size_t max)
{
	if (params.size() < min || params.size() > max)
	{
		client->sendMsg(ERR_NEEDMOREPARAMS(client->getUserName(), _cmd->getCommandStr()));
		return true;
	}
	return false;
}

void Executor::parseCommas(std::string param, std::vector<std::string> &vector)
{
	std::istringstream iss(param);
	std::string token;

	while (std::getline(iss, token, ','))
		vector.push_back(token);
}

std::string Executor::getCurrentTime()
{
	std::time_t now = std::time(NULL);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
	return std::string(buffer);
}

bool Executor::isInvalidChannel(std::string channelName, std::map<std::string, Channel *> channels, Client *client)
{
	if (channels.find(channelName) == channels.end())
	{
		client->sendMsg(ERR_NOSUCHCHANNEL(client->getUserName(), channelName));
		return true;
	}

	return false;
};
