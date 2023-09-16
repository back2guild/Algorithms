CC=gcc
# CFLAG=-Wall -Wextra -Werror -g -o0 -Wformat -std=c17 -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition
#CFLAG=-Wall -Wextra -Werror -g -o0 -Wformat -std=c17
CFLAG=-Wall -Wextra -Werror -g -o0 
LIB_COMMAND=ar -rc

INIT=init

SRCDIR=src
OBJDIR=obj
LIBDIR=lib
BINDIR=bin


TESTDIR=tests
TESTBINDIR=$(TESTDIR)/$(BINDIR)

TESTS=$(wildcard $(TESTDIR)/*.c)
TESTBINS=$(patsubst $(TESTDIR)/%.c, $(TESTBINDIR)/%, $(TESTS))

BIN=$(BINDIR)/main
LIB=$(LIBDIR)/Algorithms.a

VPATH=$(SRCDIR)

SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(LIB)

$(INIT):
	@mkdir -p -v $(OBJDIR) $(BINDIR) $(LIBDIR) $(TESTBINDIR)

$(LIB): $(INIT) $(BIN)
	$(LIB_COMMAND) $(LIB) $(OBJS)

$(BIN): $(OBJS)
	# $(CC) $(CFLAG) $(OBJS) -o $@ -lm

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAG) -c $< -o $@


.PHONY: run
.PHONY: clean

run:
	./$(BIN)


clean:
	if [ -d "$(OBJDIR)" ]; then \
		rm -rfv $(OBJDIR); \
	fi \

	if [ -d "$(LIBDIR)" ]; then \
		rm -rfv $(LIBDIR); \
	fi \
	
	if [ -d "$(TESTBINDIR)" ]; then \
		rm -rfv $(TESTBINDIR); \
	fi \
	
	if [ -d "$(BINDIR)" ]; then \
		rm -rfv $(BINDIR); \
	fi \

$(TESTBINDIR)/%: $(TESTDIR)/%.c
	# $(CC) $(CFLAG) $< $(LIB) -o $@ -lcriterion -lm
	$(CC) $(CFLAG) $< $(OBJS) -o $@ -lcriterion -lm

test: clean $(LIB) $(TESTBINDIR) $(TESTBINS)
	for t in $(TESTBINS) ; do ./$$t --verbose ; done

$(TESTBINDIR):
	@mkdir $@