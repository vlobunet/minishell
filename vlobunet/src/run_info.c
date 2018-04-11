/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:21:51 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:21:52 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_logo(void)
{
	ft_putstr("\e[8;90;85;t");
	ft_putchar('\n');
	ft_putstr("\e[93m/* *****************************************************");
	ft_putstr("********************* */\e[0m\n\e[93m/*                       ");
	ft_putstr("                                                     */\e[0m\n");
	ft_putstr("\e[93m/*\e[0m                                                 ");
	ft_putstr("       \e[97m:::      ::::::::\e[0m\e[25m   \e[93m*/\e[0m\n");
	ft_putstr("\e[93m/*\e[0m   \e[34mMINISHELL      \e[39m                   ");
	ft_putstr("                  \e[97m:+:      :+:    :+:\e[92m\e[25m\e[93m ");
	ft_putstr(" */\e[0m\n\e[93m/*\e[0m                                       ");
	ft_putstr("             \e[97m+:+ +:+         +:+\e[92m\e[25m\e[93m     ");
	ft_putstr("*/\e[0m\n\e[93m/*\e[0m   \e[97mBy: vlobunet <marvin@42.fr>    ");
	ft_putstr(" \e[39m                \e[97m+#+  +:+       +#+\e[92m\e[25m   ");
	ft_putstr("    \e[93m*/\e[0m\n\e[93m/*\e[0m                              ");
	ft_putstr("                  \e[97m+#+#+#+#+#+    +#+\e[92m\e[25m        ");
	ft_putstr("  \e[93m*/\e[0m\n\e[93m/*\e[0m   \e[97mCreated: 2018/01/30 12:");
	ft_putstr("57:46 by \e[34mvlobunet\e[39m          \e[97m#+#    #+#\e[92m ");
	ft_putstr("\e[25m            \e[93m*/\e[0m\n\e[93m/*\e[0m   \e[97mUpdated");
	ft_putstr(": 2018/01/30 12:57:47 by \e[34mvlobunet\e[39m         \e[97m##");
	ft_putstr("#   ########.fr\e[92m\e[25m       \e[93m*/\e[0m\n\e[93m/*     ");
	ft_putstr("                                                              ");
	ft_putstr("         */\e[0m\n\e[93m/* ***********************************");
	ft_putstr("*************************************** */\e[0m\n");
	ft_putchar('\n');
}

void	print_info(void)
{
	ft_putstr("\n_____________________________________________________");
	ft_putstr("______________________________\n\n");
	ft_putstr("\e[97mThe project minishell is an obligatory part of the learn");
	ft_putstr("ing process in the process\nof training in the UNIT Factory on");
	ft_putstr("the topic UNIX\nIn the given project, the following function");
	ft_putstr("s were used:\n\n\t- cat: concatenate files and print onthe sta");
	ft_putstr("ndard output\n\t- env: print environment\n\t- setenv: change");
	ft_putstr(" or add an environment variable\n\t- unsetenv: delete environ");
	ft_putstr("ment variables\n\t- getenv: get environment variables\n\t- ec");
	ft_putstr("ho: display a line of text\n\t- pwd: return working director");
	ft_putstr("y name\n\t- cd: go to directory\n\t- clean: clear the termin");
	ft_putstr("al screen\n\t- man: format and display the manual pages\n\t");
	ft_putstr("- info: print Info documents\n\nIf you do not know how to use");
	ft_putstr(" the command, use man [command]\n\tAuthor: vlobunet\n\e[0m");
	ft_putstr("___________________________________________________________");
	ft_putstr("________________________\n\n");
}

void	run_info(void)
{
	ft_putstr("\033[0d\033[2J");
	print_logo();
	ft_putstr("\e[94m");
	ft_putstr("    __       __  __            __ ");
	ft_putendl("           __                  __  __");
	ft_putstr("   /  \\     /  |/  |          / ");
	ft_putendl(" |          /  |                /  |/  |");
	ft_putstr("   ##  \\   /## |##/  _______  ##");
	ft_putendl("/   _______ ## |____    ______  ## |## |");
	ft_putstr("   ###  \\ /### |/  |/       \\ /");
	ft_putendl("  | /       |##      \\  /      \\ ## |## |");
	ft_putstr("   ####  /#### |## |#######  |## ");
	ft_putendl("|/#######/ #######  |/######  |## |## |");
	ft_putstr("   ## ## ##/## |## |## |  ## |## ");
	ft_putendl("|##      \\ ## |  ## |##    ## |## |## |");
	ft_putstr("   ## |###/ ## |## |## |  ## |## ");
	ft_putendl("| ######  |## |  ## |########/ ## |## |");
	ft_putstr("   ## | #/  ## |## |## |  ## |## ");
	ft_putendl("|/     ##/ ## |  ## |##       |## |## |");
	ft_putstr("   ##/      ##/ ##/ ##/   ##/ ##/");
	ft_putendl(" #######/  ##/   ##/  #######/ ##/ ##/");
	ft_putstr(" \e[39m");
	print_info();
}
