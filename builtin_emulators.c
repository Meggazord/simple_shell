#include "shell.h"

/**
 * _myexit - exits the shell
 * @information: Structure containing potential arguments.
 *  Return: exits with a given exit status
 *         (0) if information.argv[0] != "exit"
 */
int _myexit(info_t *information)
{
	int exitcheck;

	if (information->argv[1])
	{
		exitcheck = _erratoi(information->argv[1]);
		if (exitcheck == -1)
		{
			information->status = 2;
			print_error(information, "Illegal number: ");
			_eputs(information->argv[1]);
			_eputchar('\n');
			return (1);
		}
		information->err_num = _erratoi(information->argv[1]);
		return (-2);
	}
	information->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @information: Structure containing potential arguments.
 *  Return: Always 0
 */
int _mycd(info_t *information)
{
	char *s;
	char *dir;
	char buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!information->argv[1])
	{
		dir = _getenv(information, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(information, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(information->argv[1], "-") == 0)
	{
		if (!_getenv(information, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(information, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(information, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(information->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(information, "can't cd to ");
		_eputs(information->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(information, "OLDPWD", _getenv(information, "PWD="));
		_setenv(information, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @information: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myhelp(info_t *information)
{
	char **arg_array;

	arg_array = information->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

/**
 * _myhistory - displays the history list, one command by line
 * @information: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myhistory(info_t *information)
{
	print_list(information->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @information: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *information, char *str)
{
	char *p;
	char c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(information->alias),
		get_node_index(information->alias, node_starts_with(information->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @information: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *information, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(information, str));

	unset_alias(information, str);
	return (add_node_end(&(information->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL;
	char *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @information: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myalias(info_t *information)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (information->argc == 1)
	{
		node = information->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; information->argv[i]; i++)
	{
		p = _strchr(information->argv[i], '=');
		if (p)
			set_alias(information, information->argv[i]);
		else
			print_alias(node_starts_with(information->alias, information->argv[i], '='));
	}

	return (0);
}
