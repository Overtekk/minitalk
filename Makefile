# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roandrie <roandrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 11:05:05 by roandrie          #+#    #+#              #
#    Updated: 2026/01/20 11:43:10 by roandrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT		=	client
NAME_SERVER		=	server

CC				=	cc
CFLAGS			=	-g -Wall -Werror -Wextra

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

INCLUDE			=	-I$(LIBFT_PATH)/include

SRCS_DIR		=	sources
OBJ_DIR			=	obj

FILES_CLIENT	=	client.c
FILES_SERVER	=	server.c

OBJS_CLIENT		=	$(addprefix $(OBJ_DIR)/, $(FILES_CLIENT:.c=.o))
OBJS_SERVER		=	$(addprefix $(OBJ_DIR)/, $(FILES_SERVER:.c=.o))

## COLORS ##

BLUE			:=	\033[96m
GREEN			:=	\033[32m
MAGENTA			:=	\033[38;5;206m
BOLD			:=	\033[1m
RESET			:=	\033[0m
BRED			:=	\e[1;31m

## RULES ##

.PHONY:			all clean fclean re
.SILENT:

all:			$(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
				@echo "$(MAGENTA)>>>$(RESET)"
				@echo "	$(BRED)STARTING CREATING $(BOLD)libft.a$(RESET)"
				@echo "$(MAGENTA)>>>$(RESET)"
				@make -C $(LIBFT_PATH) --no-print-directory

$(NAME_SERVER):	$(LIBFT) $(OBJS_SERVER)
				@echo "$(BLUE)Linking $(NAME_SERVER)...$(RESET)"
				$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)
				@echo "$(MAGENTA)-----------------------------------------------$(RESET)"
				@echo "    $(BLUE)YOU CAN NOW USE $(BOLD)\"./$(NAME_SERVER)\"$(RESET)"
				@echo "$(MAGENTA)-----------------------------------------------$(RESET)"

$(NAME_CLIENT): $(LIBFT) $(OBJS_CLIENT)
				@echo "$(BLUE)Linking $(NAME_CLIENT)...$(RESET)"
				$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
				@echo "$(MAGENTA)-----------------------------------------------$(RESET)"
				@echo "    $(BLUE)YOU CAN NOW USE $(BOLD)\"./$(NAME_CLIENT) [PID] [MSG]\"$(RESET)"
				@echo "$(MAGENTA)-----------------------------------------------$(RESET)"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
				mkdir -p $(dir $@)
				@if [ ! -f $(OBJ_DIR)/.header_shown ]; then \
				echo "$(MAGENTA)>>>$(RESET)"; \
				echo "  $(BRED)STARTING COMPILATION$(RESET)"; \
				echo "$(MAGENTA)>>>$(RESET)"; \
				touch $(OBJ_DIR)/.header_shown; \
				fi
				@echo "$(BLUE)$(BOLD)[Compiled] ✅ $(GREEN)\"$^\"$(RESET)"
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
				rm -rf $(OBJ_DIR)
				@make -C $(LIBFT_PATH) clean --no-print-directory
				@echo "$(BLUE) $(BOLD)$(OBJ_DIR) $(RESET)$(BLUE)have been deleted 🗑️$(RESET)"

fclean:         clean
				@make -C $(LIBFT_PATH) fclean --no-print-directory
				rm -f $(NAME_CLIENT) $(NAME_SERVER)
				@echo "$(BLUE) $(BOLD)Executables $(RESET)$(BLUE)have been cleaned 🗑️$(RESET)"

re:             fclean all
