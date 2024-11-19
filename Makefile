# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 14:02:05 by edetoh            #+#    #+#              #
#    Updated: 2024/11/04 17:41:51 by edetoh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# =============================== VARIABLES =================================== #

# Nom de la librairie finale
NAME		= pipex.a

# Répertoires
INCLUDE		= include
LIBFT		= 42_libft-mylibft
SRC_DIR		= src/

# Commandes de compilation et d'archivage
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar rcs

# ================================ COULEURS =================================== #

# Codes couleurs pour le retour d'information dans le terminal
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# =============================== SOURCES ===================================== #

# Liste des fichiers source pour ft_printf
SRC_FILES	=

# Définition des fichiers source et objets
SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(SRC_DIR), $(addsuffix .o, $(SRC_FILES)))

# ============================== REGLES PRINCIPALES ========================== #

# Règle principale de compilation
all:		$(NAME)

# Création de la librairie libftprintf.a
$(NAME):	$(OBJ)
			@echo "$(YELLOW)>>> Compilation de libft <<<$(DEF_COLOR)"
			make -C $(LIBFT)
			cp $(LIBFT)/libft.a .
			mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)>>> libftprintf.a créé avec succès <<<$(DEF_COLOR)"

# Compilation des objets pour ft_printf
$(SRC_DIR)%.o: $(SRC_DIR)%.c
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


# ================================== CLEAN ==================================== #

# Nettoyage des objets de ft_printf et de libft
clean:
			$(RM) -rf $(SRC_DIR)*.o
			make clean -C $(LIBFT)
			@echo "$(BLUE)>>> ft_printf object files cleaned! <<<$(DEF_COLOR)"

# Nettoyage complet, incluant la suppression des librairies
fclean:		clean
			$(RM) -f $(NAME)
			$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)>>> ft_printf et libft executables cleaned! <<<$(DEF_COLOR)"

# ================================= REBUILD =================================== #

# Recompilation complète
re:			fclean all
			@echo "$(GREEN)>>> Cleaned and rebuilt everything for ft_printf! <<<$(DEF_COLOR)"

# ================================ PHONY ====================================== #

# Indication des règles qui ne correspondent pas à des fichiers
.PHONY:		all clean fclean re