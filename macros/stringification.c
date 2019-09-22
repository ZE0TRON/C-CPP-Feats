struct command
{
  char *name;
  void (*function) ();
};

// struct command commands[] =
// {
//   { "quit", quit_command},
//   { "help", help_command},
// };
#define COMMAND(NAME)  { #NAME, NAME ## _command }

void quit_command();
void help_command();

struct command commands[] =
{
  COMMAND (quit),
  COMMAND (help)
};