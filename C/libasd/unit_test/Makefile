.PHONY: all clean
.DEFAULT_GOAL := all

LIBDIR = ../lib

SRC = $(shell find $(SRCDIR) -name '*.c')
OBJ = $(patsubst %.c, %.o, $(SRC))
DEP = $(patsubst %.c, %.d, $(SRC))
BIN = $(patsubst %.c, %.out, $(SRC))

CC = gcc

CFLAGS  = -std=c11 -o $@
DFLAGS  = -MM -MT $(patsubst %.c, %.o, $<)

ifeq ($(DEBUG), 1)
	CFLAGS += -O0 -g -Wall
else
	CFLAGS += -O3 -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--strip-all
endif

%.d : %.c
	$(CC) $(DFLAGS) $(CFLAGS) $<

ifneq ($(MAKECMDGOALS), clean)
-include $(DEP)
endif

all: $(BIN)

# MANUAL DEPENDENCIES

binary_tree/binary_tree_test.out: $(LIBDIR)/libbinary_tree.a
hash_table/hash_table_test.out: $(LIBDIR)/libhash_table.a
hash_table/hash_table_iterator_test.out: $(LIBDIR)/libhash_table.a
heap/heap_test.out: $(LIBDIR)/libheap.a
list_map/list_map_test.out: $(LIBDIR)/liblist_map.a $(LIBDIR)/libsort.a
list_map/list_map_iterator_test.out: $(LIBDIR)/liblist_map.a
sort/heap_sort_test.out: $(LIBDIR)/libsort.a
sort/insertion_sort_test.out: $(LIBDIR)/libsort.a
sort/merge_sort_test.out: $(LIBDIR)/libsort.a
sort/quick_sort_test.out: $(LIBDIR)/libsort.a
sort/selection_sort_test.out: $(LIBDIR)/libsort.a
priority_queue/priority_queue_test.out: $(LIBDIR)/libpriority_queue.a
graph/graph_test.out: $(LIBDIR)/libgraph.a

######

%.out: %.o $(LIBDIR)/libtest.a $(LIBDIR)/libutils.a
	$(CC) $(CFLAGS) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.d' -delete
	find . -type f -name '*.out' -delete
