SERVER			=		server
CLIENT			=		client
NAME			=		minitalk
CFLAGS			=		-Wall -Wextra -Werror
CC				=		gcc
RM				=		rm -rf
SRCDIR			=		./srcs/
INCLUDES		=		-I ./includes/
SRC_SERVER		=		./srcs/server.c ./srcs/utils.c
SRC_CLIENT		=		./srcs/client.c
OBJ_SERVER		=		$(SRC_SERVER:.c=.o)
OBJ_CLIENT		=		$(SRC_CLIENT:.c=.o)

all : $(NAME)
	
$(NAME) : $(SERVER) $(CLIENT)
		
$(SERVER) : $(OBJ_SERVER)
		@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^
		@tput setaf 2 && printf "\033[2K\r Executable '$(SERVER)' created.\n"

$(CLIENT) : $(OBJ_CLIENT)
		@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^
		@tput setaf 2 && printf "\033[2K\r Executable '$(CLIENT)' created.\n"

%.o: %.c
		@tput setaf 190 && printf "\033[2K\r Compiling $< "
		@$(CC) $(CFLAGS)  -o $@ -c $<

clean :
		@$(RM) $(OBJS_UTILS) $(OBJ_SERVER) $(OBJ_CLIENT)
		@tput setaf 928 && printf "\033[2K\r Objects have been deleted. \n"

fclean : clean
		@$(RM) $(SERVER) $(CLIENT)
		@tput setaf 928 && printf "\033[2K\r Executables have been deleted. \n"

re : fclean all
				
.PHONY:	all clean fclean re