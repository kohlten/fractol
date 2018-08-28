SRC = src
OBJ = obj
OUT = fractol
LIB = src/lib

CFILES := $(wildcard $(SRC)/*.c)
OFILES := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CFILES))

LIBCFILES := $(wildcard $(LIB)/*.c)
LIBOFILES := $(patsubst $(LIB)/%.c, $(OBJ)/%.o, $(LIBCFILES))

CC = gcc

ifeq ($(shell uname), Darwin)
	OS = MAC
	MINILIBX = minilibx
	LIBS = -L $(MINILIBX) -L /usr/X11/lib -L libft -framework OpenGL -framework CoreFoundation -framework AppKit -lft -lmlx
else
	OS = LINUX
	MINILIBX = minilibx_linux
	LIBS = -L $(MINILIBX) -L libft -lft -lmlx -lX11 -lXext -lm
endif

CFLAGS = -Wall -Wextra -Werror -I includes -I minilibx -I includes/lib
POFILES := $(patsubst $(SRC)/%.c, %.o, $(CFILES))

all: $(OBJ) $(MINILIBX)/libmlx.a libft/libft.a $(LIBOFILES) $(OFILES)
	@echo "CC $(CFLAGS) -o $(OUT) $(LIBS) $(LIBOFILES) $(OFILES)"
	@$(CC) $(CFLAGS) -o $(OUT)  $(OFILES) $(LIBOFILES) $(LIBS)
	@echo "Done"

$(OBJ)/%.o: $(SRC)/%.c
	@echo "CC $(CFLAGS) -c -o $@ $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ)/%.o: $(LIB)/%.c
	@echo "CC $(CFLAGS) -c -o $@ $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(MINILIBX)/libmlx.a:
	cd $(MINILIBX) && make

libft/libft.a:
	cd libft && make

$(OBJ):
	mkdir obj

clean:
	-@rm -rf $(OBJ)
	@cd libft && make clean
	@echo "Cleaned object files"
	-@rm $(OUT)
	@echo "Cleaned binary"

fclean: clean
	@cd libft && make fclean
	-@cd $(MINILIBX) && make clean > /dev/null && rm *.a
	@echo "Cleaned minilibx"

re: clean all

.PHONY: all fclean clean re

