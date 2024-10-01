NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -g3


FT_PATH	=	.ft
FT_FILE	=	ft.a
FT_LIB	=	$(FT_PATH)/$(FT_FILE)


MLX_PATH	=	./minilibx-linux
MLX_FILE	=	libmlx.a
MLX_FLAGS   =   -lmlx -lX11 -lXext 




# Base compiled files
SRC_FOLDER	=    src/
SRC_FILES	=    so_long.c init_map.c check_map.c errors.c flood_fill.c img_draw.c moves.c
OBJS        =    $(SRC_FILES:%.c=$(SRC_FOLDER)%.o)


# Colors
DEFAULT        =    \033[0;39m
GREEN        =    \033[0;32m
YELLOW        =    \033[0;33m


# Compile part
$(SRC_FOLDER)%.o: $(SRC_FOLDER)%.c
	@echo "$(YELLOW)- Compiling $<$(DEFAULT)"
	@$(CC) $(FLAGS) -I$(SRC_FOLDER) -I$(FT_PATH) -I/usr/include -I$(MLX_PATH) -c $< -o $@ 

$(NAME):     $(OBJS)
	@make -C $(FT_PATH) --no-print-directory -s
	@make -C $(MLX_PATH) --no-print-directory -s
	@$(CC) $(FLAGS) $(OBJS) $(FT_LIB) -L$(MLX_PATH)  $(MLX_FLAGS) -o $(NAME) 
	@echo "$(GREEN)♫ $(NAME) compiled successfully! ♫$(DEFAULT)"

# Mandatory rules
all:        $(NAME)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(FT_PATH) --no-print-directory -s
	@make clean -C $(MLX_PATH) --no-print-directory -s
	@echo "$(GREEN)♫ $(NAME) cleaned successfully! ♫$(DEFAULT)"

fclean:        clean
	@rm -f $(NAME)
	@make fclean -C $(FT_PATH) --no-print-directory -s
	@echo "$(GREEN)♫ $(NAME) executable files cleaned! ♫$(DEFAULT)"

re:            fclean all
	@echo "$(GREEN)♫ $(NAME) recompiled successfully! ♫$(DEFAULT)"

.PHONY:        all clean fclean re