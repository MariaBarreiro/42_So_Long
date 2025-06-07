# **************************************************************************** #
#                                    Config                                    #
# **************************************************************************** #

MAKE = make
SHELL = bash

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

NAME = so_long

# **************************************************************************** #
#                                    Paths                                     #
# **************************************************************************** #

MLX_PATH	  		= ./Libs/minilibx-linux/
MLX_NAME			  = libmlx_Linux.a
MLX					  	= $(MLX_PATH)$(MLX_NAME)

LIB_PATH	  		=	./Libs/42_Libft/
LIB_NAME  			= libft.a
LIB	   					= $(LIB_PATH)$(LIB_NAME)

PRINTF_PATH					= ./Libs/42_Libft/42_Ft_Printf/
PRINTF_NAME					= libftprintf.a
PRINTF							= $(PRINTF_PATH)$(PRINTF_NAME)

INC_PATH	  		= ./Includes/

SRC_PATH  			= ./Src/

SRC_FILES			  = init_game.c
SRC_FILES		  	+= main.c
SRC_FILES				+= die.c

MAP_SRC_PATH  	= $(SRC_PATH)Maps/

MAP_SRC_FILES	  = handle_map.c
MAP_SRC_FILES	  += validate_map.c
MAP_SRC_FILES	  += validate_map2.c

SRC						  = $(addprefix $(SRC_PATH), $(SRC_FILES))
SRC						  += $(addprefix $(MAP_SRC_PATH), $(MAP_SRC_FILES))

OBJS_DIR			  = Obj
OBJS				   	= $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRC))

# **************************************************************************** #
#                                   Compiler                                   #
# **************************************************************************** #

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g
MLXFLAGS				= -L $(MLX_PATH) -lm -lmlx -Ilmlx -lXext -lX11
INC             = -I $(INC_PATH)
INC						  += -I $(LIB_PATH)/42_Gnl/ 
INC							+= -I $(LIB_PATH)
INC							+= -I $(MLX_PATH)
INC							+= -I $(PRINTF_PATH)

# **************************************************************************** #
#                                   Commands                                   #
# **************************************************************************** #

RM              = rm -rf

# **************************************************************************** #
#                                    Rules                                     #
# **************************************************************************** #
 
all: depends $(NAME)

depends: 
	@$(MAKE) -C $(PRINTF_PATH)
	@$(MAKE) -C $(LIB_PATH)
	@$(MAKE) -C $(MLX_PATH)

$(OBJS_DIR):
	@mkdir -p Obj

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS) depends $(LIB) $(MLX)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIB) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@$(RM) $(NAME) $(OBJS_DIR)

re: fclean all
