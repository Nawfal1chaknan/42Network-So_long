NAME = so_long

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

LMLX = -lmlx -framework OpenGL -framework AppKit

PRINTF = ./ft_printf/libftprintf.a

GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

FILES = $(GNL) so_long.c set_map.c check_errors.c print_errors.c check_map.c move_wasd.c move_player.c utils.c

OBJS = $(FILES:.c=.o)

all : $(NAME)

$(PRINTF) :
	make -C ft_printf

$(NAME) : $(OBJS) $(PRINTF)
		@$(CC) $(CFLAGS) $(LMLX) $(OBJS) $(PRINTF)  -o $(NAME)


clean :
		@$(RM) $(OBJS) ./ft_printf/*.o ./ft_printf/libftprintf.a

fclean : clean
		@$(RM) $(NAME)

re : fclean all