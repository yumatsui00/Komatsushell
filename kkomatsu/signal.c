#include "minishell.h"

void sig_int_input(int signum)
{
    // ft_putstr_fd("\b\b  \b\n", STDERR);
    ft_putstr_fd("\n", STDERR);
    ft_putstr_fd(MINISHELL, STDERR);
}

void sig_quit_input(int signum)
{
    ft_putstr_fd("\b\b  \b\b", STDERR);
}