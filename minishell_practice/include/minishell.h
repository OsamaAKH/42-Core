#ifndef MINISHELL_H
# define MINISHELL_H

// Mandatory Includes for Minishell
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
#include <limits.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
 

// ====================================================================
// 1. REDIRECTION STRUCTURES
// ====================================================================

// Enum for the four mandatory redirection types
typedef enum e_redir_type
{
    REDIR_IN,       // <
    REDIR_OUT,      // >
    REDIR_APPEND,   // >>
    REDIR_HEREDOC   // <<
} t_redir_type;

// Structure to hold a single redirection detail
typedef struct s_redir
{
    t_redir_type    type;       // The type of redirection
    char            *file;      // The target file path or the HEREDOC delimiter
    struct s_redir  *next;      // Pointer to the next redirection in the list
} t_redir;

// ====================================================================
// 2. COMMAND STRUCTURE (The core contract between Parser and Executor)
// ====================================================================

// Structure to hold a single command and its execution context
typedef struct s_command
{
    char            **args;         // Array of strings: command and its arguments (e.g., {"ls", "-l", NULL}).
    t_redir         *redirs;        // Linked list of all redirections for this command.
    int             is_builtin;     // Flag (0 or 1) to indicate if the command is a shell builtin.
    int             exit_status;    // Field to store the exit status of this specific command after execution.
    struct s_command *next;         // Pointer to the next command in the pipeline (for the '|' operator).
} t_command;

typedef struct s_env
{
	char	*key;
	char	*value;
	struct	s_env	*next;
}	t_env;

// In minishell.h

typedef struct s_data
{
    t_env           *env_list;      // The head of your custom environment linked list
    char            *user_input;    // The raw line read from readline
    int             last_exit_code; // The value of $?
    char            *working_dir;   // Current working directory (optional, but useful)
    // Add other necessary state here later (e.g., signal handlers, etc.)
} t_data;



#define CWD_BUFFER_SIZE 1024

// #builtins

int	my_pwd(t_command *cmd);
int builtin_env(t_command *cmd, t_data *data);
int	builtin_exit(t_command *cmd, t_data *data);


// #env
t_env	*init_env(char **envp);
char	*get_env_value(t_data *data, char *key);

//#utils
int	is_numeric(char *str);
void	free_env_list(t_env *head);
void	free_shell_data(t_data *data);

#endif
