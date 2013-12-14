.PHONY: clean fclean re

SRC = main.c\
	ft_strchr.c\
	ft_strnew.c\
	ft_strdup.c\
	ft_strdel.c\
	ft_strjoin.c\
	ft_strcmp.c\
	ft_strlen.c\
	ft_memset.c\
	ft_memalloc.c\
	ft_strcpy.c\
	ft_strcat.c\
	ft_bzero.c\
	get_next_line.c\
	ft_memmove.c\
	ft_putstr.c\
	ft_putchar.c\
	maxheap.c

NAME = hotrace
DEB = deb
FLAGS =  -Wall -Werror -Wextra
GITFILES = main.c\
	ft_strchr.c\
	get_next_line.c\
	ft_strnew.c\
	ft_strdup.c\
	ft_strdel.c\
	ft_strjoin.c\
	ft_strcmp.c\
	ft_strlen.c\
	ft_memset.c\
	ft_memalloc.c\
	ft_strcpy.c\
	ft_strcat.c\
	ft_bzero.c\
	header.h\
	README.md\
	ft_putstr.c\
	Makefile\
	ft_memmove.c\
	ft_putchar.c\
	maxheap.c



all:
	gcc $(FLAGS) $(SRC) -o $(NAME)

debug:
	cc -g $(SRC) -o $(DEB)
	gdb $(DEB)

gps:
	git add $(GITFILES); git commit -m"auto"; git push

gpl:
	git pull;

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(DEB)

re: fclean all 

pasw:
	git config --global credential.helper "cache --timeout=36000"
