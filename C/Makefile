.PHONY: clean

CFLAGS = -std=c11

ifeq ($(DEBUG), 1)
	CFLAGS += -O0 -g -Wall
else
	CFLAGS += -O3 -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--strip-all
endif

IDIR = -I libasd/include -I dataset
LDIR = -L libasd/lib -L dataset

CFLAGS += $(IDIR) $(LDIR)

CC = gcc $(CFLAGS)

LIBASD = libasd/lib
LIBDATASET = dataset

all: sort.out dictionary.out graph.out

sort.out : sort.o $(LIBDATASET)/libdataset.a $(LIBASD)/libsort.a $(LIBASD)/libtest.a
	$(CC) -o $@ $< -l test -l dataset -l sort

dictionary.out : dictionary.o
	$(CC) -o $@ $< -l test -l dataset -l dictionary

graph.out : graph.o
	$(CC) -o $@ $< -l graph

%.o: %.c
	$(CC) -c $<

$(LIBDATASET)/libdataset.a :
	$(MAKE) -C dataset

%.a :
	$(MAKE) -C libasd

clean :
	rm -f *.o *.out
	$(MAKE) -C dataset clean
