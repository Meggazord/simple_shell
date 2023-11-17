#include "shell.h"

int main(void)
{
    char input[MAX_INPUT];

    while (1)
    {
        prompt();
        get_input(input, sizeof(input));
        execute(input);
    }

    return (0);
}
