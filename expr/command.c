#define COMMAND(OPS) OP(Open) OP(Close) OP(Save) OP(Quit)
#define ENUM_NAME(name) cmd##name

enum Commands {
    COMMAND(ENUM_NAME)
};

#undef ENUM_NAME

#define COMMAND_OP(name) #name,
    const char* const commandNames[] = {
        COMMAND(COMMAND_OP)
    };
#undef COMMAND_OP