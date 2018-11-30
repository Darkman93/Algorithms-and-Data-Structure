# Archives

ARCHIVES = utils test sort list_map hash_table binary_tree dictionary stack priority_queue graph heap

# Special rules

.SECONDEXPANSION:
.PHONY: all clean dirs
.DEFAULT_GOAL := all

# Directories

INCDIR = include
SRCDIR = src
LIBDIR = lib
OBJDIR = obj
DEPDIR = dep

OBJPATH = $(patsubst %, $(OBJDIR)/%, $(ARCHIVES))
DEPPATH = $(patsubst %, $(DEPDIR)/%, $(ARCHIVES))
SRCPATH = $(patsubst %, $(SRCDIR)/%, $(ARCHIVES))

DIR = $(LIBDIR) $(OBJDIR) $(OBJPATH) $(DEPDIR) $(DEPPATH) $(DEPDIR)/dictionary/adapters $(OBJDIR)/dictionary/adapters

# Files

LIB = $(patsubst %, $(LIBDIR)/lib%.a, $(ARCHIVES))

SRC = $(shell find $(SRCDIR) -name '*.c')
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DEP = $(patsubst $(SRCDIR)/%.c, $(DEPDIR)/%.d, $(SRC))

# Programs and flags

CC = gcc
AR = ar

CFLAGS  = -std=c11 -o $@
DFLAGS = -MM -MT $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $<)

ARFLAGS = rcT

ifeq ($(DEBUG), 1)
	CFLAGS += -O0 -g -Wall
else
	CFLAGS += -O3 -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--strip-all
endif

# Functions

getobjects = $(filter $(patsubst $(LIBDIR)/lib%.a, $(OBJDIR)/%, $(1))/%, $(OBJ))

# Create dependencies

$(DEPDIR)/%.d: $(SRCDIR)/%.c | dirs
	$(CC) $(DFLAGS) $(CFLAGS) $<

dirs: $(DIR)

$(DIR):
	mkdir -p $@

ifneq ($(MAKECMDGOALS), clean)
-include $(DEP)
endif

# ARCHIVES

all: $(LIB)
	$(MAKE) -C unit_test

$(LIBDIR)/libsort.a:  		 $(filter $(OBJDIR)/utils/%.o, $(OBJ))
$(LIBDIR)/libhash_table.a: $(filter $(OBJDIR)/list_map/%.o, $(OBJ))
$(LIBDIR)/libdictionary.a: $(filter $(OBJDIR)/binary_tree/%.o, $(OBJ))    \
                           $(filter $(OBJDIR)/hash_table/%.o, $(OBJ))     \
                           $(filter $(OBJDIR)/list_map/%.o, $(OBJ))
$(LIBDIR)/libgraph.a: 		 $(filter $(OBJDIR)/hash_table/%.o, $(OBJ))			\
													 $(filter $(OBJDIR)/list_map/%.o, $(OBJ)) 			\
													 $(filter $(OBJDIR)/sort/%.o, $(OBJ)) 					\
													 $(filter $(OBJDIR)/utils/%.o, $(OBJ))  				\
													 $(filter $(OBJDIR)/stack/%.o, $(OBJ))  				\
													 $(filter $(OBJDIR)/priority_queue/%.o, $(OBJ)) \
													 $(filter $(OBJDIR)/heap/%.o, $(OBJ))

$(LIBDIR)/%.a: $$(call getobjects, $$@)
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o:
	$(CC) $(CFLAGS) -c $<

# Utilities

clean:
	-rm -fr dep lib obj
	$(MAKE) -C unit_test clean
