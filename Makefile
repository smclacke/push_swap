# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: smclacke <smclacke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/25 19:56:56 by smclacke      #+#    #+#                  #
#    Updated: 2024/05/01 12:41:48 by smclacke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS			= checker


MAKEFLAGS		= --no-print-directory
CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -g -fsanitize=address
CC				= gcc

INCLUDES		= -Iinclude -Iinclude/libft/src
BONUS_INC		= -Iinclude/push_swap.h -Iinclude/checker.h

SRCS			=	push_swap.c		\
					push.c			\
					swap.c			\
					rotate.c		\
					rev_rotate.c	\
					init.c			\
					sort.c			\
					sort_utils.c	\
					utils.c

SRC_DIR			= src
SRC				= $(addprefix $(SRC_DIR)/, $(SRCS))

BONUS_SRCS		=	checker.c		\
					init.c			\
					push.c			\
					rev_rotate.c	\
					rotate.c		\
					swap.c			\
					utils.c

BONUS_SRC_DIR	= checking
BONUS_SRC		= $(addprefix $(BONUS_SRC_DIR)/, $(BONUS_SRCS))

OBJ_DIR			= obj
OBJ				= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

BONUS_OBJ_DIR	= bonus_obj
BONUS_OBJ		= $(addprefix $(BONUS_OBJ_DIR)/, $(notdir $(BONUS_SRCS:.c=.o)))

## Colours ##
RESET		:= \033[0m
RED			:= \033[1;91m
GREEN		:= \033[1;92m
YELLOW		:= \033[1;93m
BLUE		:= \033[1;94m
PURPLE		:= \033[1;95m
CYAN		:= \033[1;96m
WHITE		:= \033[1;97m
BLACK		:= \033[1;90m

all		: libft $(NAME)

bonus	: libft $(NAME) $(BONUS)

libft	:
	@ make -C include/libft

$(NAME)	: $(OBJ)
	@ echo "${PURPLE} >>> push_swap compiling...${RESET}"
	@ $(CC) $^ $(CFLAGS) $(INCLUDES) include/libft/libft.a -o $(NAME)
	@ echo "${GREEN} ---> push_swap Made!${RESET}"

$(BONUS): $(BONUS_OBJ)
	@ $(CC) $^ $(CFLAGS) $(BONUS_INC) $(INCLUDES) include/libft/libft.a -o $(BONUS)
	@ echo "${RED}Checker in check${RESET}"

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@ mkdir -p $(OBJ_DIR)	
	@ $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o:$(BONUS_SRC_DIR)/%.c
	@ mkdir -p $(BONUS_OBJ_DIR)
	@ $(CC) $(CFLAGS) $(INLCUDES) $(BONUS_INC) -c $< -o $@

clean	:
	@ rm -rf $(OBJ_DIR)
	@ rm -rf $(BONUS_OBJ_DIR)

fclean	: clean
	@ make $(MAKEFLAGS) -C include/libft fclean
	@ rm -f $(NAME)
	@ rm -f $(BONUS)
	@ echo "${PURPLE} // push_swap fCleaned!${RESET}"

re		: fclean all

.PHONY: all clean fclean re libft bonus
