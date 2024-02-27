#------------------------------------------------------------------------------
#
#	$ Makefile $
#
#	Makefile to create an executable named philo.
#
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
#	NAME OF THE EXECUTABLE
#------------------------------------------------------------------------------
NAME	=	philo

#------------------------------------------------------------------------------
#	MAIN DIRECTORIES
#------------------------------------------------------------------------------
SRC			=	src
INCLUDE		=	include
OBJ_DIR		=	objects


#------------------------------------------------------------------------------
#	COMPILATION FLAGS
#------------------------------------------------------------------------------
CC				=	cc
CFLAGS			=	-Wall #-Wextra -Werror
HEADERS			=	-I./${INCLUDE}
OPTIMIZATION	=	#-O3
DEBUG			=	-g
SANITIZER		=	-fsanitize=address
PTHREAD			=	#-lpthread

#------------------------------------------------------------------------------
#	FILES
#------------------------------------------------------------------------------
PHILOSOPHERS_HEADER	=	${INCLUDE}/philosophers.h

ALLOCATION	=	ft_calloc.c clear_data.c
CONVERTERS	=	convert_input.c ft_atoi_err.c
DISPLAY		=	display_state.c ft_putchar.c ft_putnbr_long.c ft_putnbr.c \
				ft_putstr.c states_to_display.c
PROGRAM		=	main.c init_philosophers.c

SRC_FILES	=	${ALLOCATION} ${CONVERTERS} ${DISPLAY} ${PROGRAM}

#------------------------------------------------------------------------------
#	RULE TO GET THE .O COMPILED
#------------------------------------------------------------------------------
OBJ_FILES = ${patsubst %.c,${OBJ_DIR}/%.o,${notdir ${SRC_FILES}}}

${OBJ_DIR}/%.o: ${SRC}/*/%.c ${PHILOSOPHERS_HEADER} Makefile
	$(CC) ${CFLAGS} ${HEADERS} ${OPTIMIZATION} ${SANITIZER} ${PTHREAD} -c $< -o $@ ${DEBUG}

#------------------------------------------------------------------------------
#	MAIN RULES TO COMPILE AND CREATE THE EXECUTABLE AND TO CLEAN IT
#------------------------------------------------------------------------------
all: ${OBJ_DIR} ${NAME}

${NAME}: ${OBJ_FILES}
	@echo "Compilating philosophers."
	${CC} ${SANITIZER} ${OBJ_FILES} -o $@ ${DEBUG}

clean:
	rm -f ${OBJ_FILES}

fclean: clean
	@if [ -d ${OBJ_DIR} ]; \
	then \
        rmdir ${OBJ_DIR}; \
    fi
	rm -f ${NAME}

re: fclean all

${OBJ_DIR}:
	@echo "Creating objects file directory."
	@mkdir -p $@

.PHONY: all clean fclean re
