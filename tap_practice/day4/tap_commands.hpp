#pragma once
#include <unistd.h>
#include <string>

// COMMANDS
// ESTO ES UNA MIERDA, MEJOR CON ENUMS
// #define CONNECT			"CONNECT"
// #define LOOK			"LOOK"
// #define MOVE			"MOVE"
// #define QUIT			"QUIT"
// #define CHAT			"CHAT"
// #define WHO				"WHO"
// #define GROUP_CREATE	"GROUP CREATE"
// #define GROUP_INVITE	"GROUP INVITE"
// #define GROUP_JOIN		"GROUP JOIN"
// #define GROUP_LEAVE		"GROUP LEAVE"
// #define TAKE			"TAKE"
// #define DROP			"DROP"
// #define INVENTORY		"INVENTORY"
// #define TALK			"TALK"
// #define ATTACK			"ATTACK"
// #define STATUS			"STATUS"
// #define QUEST			"QUEST"
// #define QUESTS			"QUESTS"
enum class Command
{
	CONNECT,
	LOOK,
	MOVE,
	QUIT,
	CHAT,
	WHO,
	GROUP_CREATE,
	GROUP_INVITE,
	GROUP_JOIN,
	GROUP_LEAVE,
	TAKE,
	DROP,
	INVENTORY,
	TALK,
	ATTACK,
	STATUS,
	QUEST,
	QUESTS,
	// TODO
};

// OWN COMMANDS
#define DEFEND			"DEFEND"
#define FLEE			"FLEE"
#define USE_ITEM		"USE_ITEM"

// RESPONSES
#define OK		"OK"
#define ERR		"ERR"

// EVENTS -------------------------------------------------
// EVENT SYSTEM (All events will start with this keyword)
#define EVT		"EVT"

enum class Event
{
	// TODO
};

// ROOM EVENTS
#define ROOM_PRESENCE_ENTER	"ROOM PRESENCE ENTER"
#define ROOM_PRESENCE_LEAVE	"ROOM PRESENCE LEAVE"
#define ROOM_CHAT			"ROOM CHAT"

// GLOBAL EVENTS
#define GLOBAL_CHAT	"GLOBAL CHAT"

// GROUP EVENTS
#define GROUP_INVITE	"GROUP_INVITE"
#define GROUP_JOIN		"GROUP_JOIN"
#define GROUP_LEAVE		"GROUP_LEAVE"
#define GROUP_CHAT		"GROUP_CHAT"

// STATS EVENTS
#define STATS			"STATS"

// --------------------------------------------------------

// ERRORS
// #define NAME_IN_USE		"Requested username already taken"
enum class Error
{
	NAME_IN_USE,
	NO_EXIT,
	// TODO
};

// RULES (NOT NECESSARY)
// #define MAX_NAME_LEN		25
// #define MAX_MSG_LEN		1024

// const char	*err_name_in_use(void);
// const char	*err_invalid_name(void);
// const char	*err_invalid_direction(void);
// const char	*err_item_not_found(void);
// const char	*err_item_not_in_inventory(void);
// const char	*err_npc_not_found(void);
// const char	*err_npc_not_hostile(void);
// const char	*err_no_quest_available(void);


const char	*command_to_string(Command command);
Command		str_to_command(const std::string& s);
// Command		str_to_command(std::string_view command_str);
/*
'string_view' permite recibir strings literales ("Como esto"),
y el contenido no podrá ser modificado.

- En caso de usar 'const std::string& str', se podría mandar una variable string,
  o hacer 'str_to_command(std::string("Hola"))', habría que castearlo.

- En caso de usar 'std::string_view str', se podría mandar una variable string,
  o hacer 'str_to_command("Hola")', el casteo es automático.
  Además, la variable no podrá ser modificada
*/

const char	*event_to_string(Event event);
Event		str_to_event(const std::string& s);

const char	*error_to_string(Error error);
Error		str_to_error(const std::string& s);
