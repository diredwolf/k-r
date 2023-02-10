# If necessary we can use $(info VARIABLE:$(VARIABLE)) to debug.
# We can also use make -d.

CC			:=	cc
RM			:=	rm

CFLAGS		:=	-std=c89 -Wall -Wextra -Werror -pedantic
RMFLAGS		:=	-f

SRCDIR		:=	src
BINDIR		:=	bin

# Edit the $(HEADERS) variable as necessary.
COMPILE.c	:=	$(CC) $(CFLAGS)
REMOVE		:=	$(RM) $(RMFLAGS)

SRCS		:=	$(wildcard $(SRCDIR)/*.c)
PROGRAMS	:=	$(patsubst $(SRCDIR)/%.c, %, $(SRCS))

PROGRAMS	:=	$(addprefix $(BINDIR)/, $(PROGRAMS))

all: $(PROGRAMS)

$(BINDIR)/%: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(COMPILE.c) -o $@ $<

clean:
	$(REMOVE) $(PROGRAMS)

re: clean all

.PHONY:	all clean re
