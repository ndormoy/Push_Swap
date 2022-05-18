CC =		gcc
NAME =		push_swap
BONUSNAME =	checker
SRCS_NAME =	algo/ft_comb_a.c \
			algo/ft_comb_b.c \
			algo/ft_process.c \
			algo/ft_process_a.c \
			algo/ft_process_b.c \
			algo/ft_sort.c \
			algo/push_swap.c \
			args/convert_args.c \
			args/ft_check_args.c \
			args/ft_check_args2.c \
			operations/ft_operation.c \
			operations/ft_operation2.c \
			operations/ft_operation3.c \
			opti/ft_optimise.c \
			opti/ft_optimise2.c \
			utils/ft_all_sorted.c \
			utils/ft_atoi.c \
			utils/ft_atoll.c \
			utils/ft_calloc.c \
			utils/ft_error.c \
			utils/ft_is_space.c \
			utils/ft_isdigit.c \
			utils/ft_list_utils_sort.c \
			utils/ft_list_utils.c \
			utils/ft_list_utils2.c \
			utils/ft_list_utils3.c \
			utils/ft_median.c \
			utils/ft_memset.c \
			utils/ft_print_list.c \
			utils/ft_putstr.c \
			utils/ft_split.c \
			utils/ft_strlen.c \
			utils/ft_strcmp.c \
			gnl/get_next_line_utils.c \
			gnl/get_next_line.c

SRCS =		$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
SRCS_PATH =	srcs
INC_NAME =	ft_push_swap.h
INC =		$(addprefix $(INC_PATH)/, $(INC_NAME))
INC_PATH =	includes
RM =		rm -rf
OBJ =		$(SRCS:.c=.o)
CFLAG =		-Wall -Wextra -Werror
INCFLAGS =	-I$(INC_PATH)

SRCBONAME =	checker/checker.c \
			checker/checker2.c \
			gnl/get_next_line_utils.c \
			gnl/get_next_line.c \
			utils/ft_all_sorted.c \
			utils/ft_atoi.c \
			utils/ft_atoll.c \
			utils/ft_calloc.c \
			utils/ft_error.c \
			utils/ft_is_space.c \
			utils/ft_isdigit.c \
			utils/ft_list_utils_sort.c \
			utils/ft_list_utils.c \
			utils/ft_list_utils2.c \
			utils/ft_list_utils3.c \
			utils/ft_median.c \
			utils/ft_memset.c \
			utils/ft_print_list.c \
			utils/ft_putstr.c \
			utils/ft_split.c \
			utils/ft_strlen.c \
			utils/ft_strcmp.c \
			args/convert_args.c \
			args/ft_check_args.c \
			args/ft_check_args2.c \
			operations/ft_operation.c \
			operations/ft_operation2.c \
			operations/ft_operation3.c

BON_SRCS =	$(addprefix $(SRCS_PATH)/, $(SRCBONAME))
INCBONAME =	checker.h
INCBON =	$(addprefix $(INC_PATH)/, $(INCBONAME))
BON_OBJ =	$(BON_SRCS:.c=.o)

all :		 $(NAME) $(BONUSNAME)

%.o : %.c
			$(CC) $(CFLAG) $(INCFLAGS) -c $< -o $@

$(NAME) : 	$(OBJ) $(INC)
			$(CC) -o $@ $(OBJ)

$(BONUSNAME) :	$(BON_OBJ) $(INCBON)
			$(CC) -o $@ $(BON_OBJ)

clean :
			$(RM) $(OBJ) $(BON_OBJ)

fclean :	clean
			$(RM) $(NAME) $(BONUSNAME) 

re : 		fclean all

.PHONY : 	all clean fclean re
