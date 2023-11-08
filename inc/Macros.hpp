// Macros

// Client status options
#define PRE_REGISTER 1
#define REGISTERED 2

// Reply Codes
#define ERR_SERVERFULL 403
#define ERR_NEEDMOREPARAMS 461
#define ERR_ALREADYREGISTRED 462

// Commands implemented
#define JOIN 1
#define CAP 2
#define PASS 3
#define NICK 4
#define USER 5
#define PRIVMSG 6
#define KICK 7
#define INVITE 8
#define TOPIC 9
#define MODE 10

// Connection configurations
#define MAX_NB_CLIENTS 2
#define SECONDS_BETWEEN_LISTEN 1
#define BUFFER_SIZE 4096
#define MAX_PORT 65535
