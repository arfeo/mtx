# Compiler (clang or gcc)
CC = clang
# Ohoh, we will link using CCL
CCL = clang++
OPTS = -c -Wall -O3 -std=c99 -I$(HOME)/include -I$(CURDIR)/include 

# Project name
PROJECT = mtx

# Directories
OBJDIR = build
SRCDIR = src

# Extensions
SRCEXT = .c
OBJEXT = .o

# Libraries
LIBS = -lcrypto -stdlib=libc++ lib/fact.o

# Files and folders
SRCS    = $(shell find $(SRCDIR) -name '*$(SRCEXT)')
SRCDIRS = $(shell find . -name '*$(SRCEXT)' | dirname {} | sort | uniq | sed 's/\/$(SRCDIR)//g' )
OBJS    = $(patsubst $(SRCDIR)/%$(SRCEXT),$(OBJDIR)/%$(OBJEXT),$(SRCS))

# Targets
$(PROJECT): buildrepo $(OBJS)
#	$(CC) $(OBJS) $(LIBS) -o $@
	$(CCL) $(OBJS) $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%$(SRCEXT)
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(PROJECT) $(OBJDIR)/*

buildrepo:
	@$(call make-repo)

# Create obj directory structure
define make-repo
	mkdir -p $(OBJDIR)
	for dir in $(SRCDIRS); do mkdir -p $(OBJDIR)/$$dir; done
endef
