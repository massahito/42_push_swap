NAME	= push_swap

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

INCLUDE	= -I ./include

LIBFTDIR = libft

LIBFT	= $(LIBFTDIR)/libft.a

SRCS	= src/main.c \
		  src/mknode/heap_sort.c \
		  src/mknode/make_array.c \
		  src/mknode/make_array_utils.c \
		  src/mknode/make_nodes.c \
		  src/sort/push_swap.c \
		  src/sort/sort_operation.c \
		  src/sort/sort_under_6.c \
		  src/sort/sort_utils.c \

OBJS	= $(SRCS:.c=.o)

OBJDIR   = obj
OBJS  = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(INCLUDE) -o $(NAME) $^ $(CFLAGS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)
libft:
		$(MAKE) -C $(LIBFTDIR)

clean:
		$(MAKE) clean -C $(LIBFTDIR)
		$(RM) -r $(OBJDIR)

fclean: clean
		$(MAKE) fclean -C $(LIBFTDIR)
		$(RM) $(NAME)

re : fclean all

.PHONY:
		all clean fclean re
   
