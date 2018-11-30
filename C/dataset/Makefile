.PHONY: clean

CFLAGS = -std=c11

ifeq ($(DEBUG), 1)
	CFLAGS += -O0 -g -Wall
else
	CFLAGS += -O3 -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--strip-all
endif

CC = gcc $(CFLAGS)
AR = ar rcT

LDIR = ../libasd/lib

libdataset.a : dataset.o recordset.o $(LDIR)/libutils.a
	$(AR) $@ $^

%.o : %.c %.h
	$(CC) -c $<

# FOR DEVELOPERS OF THE LIBRARY ASD
%.a :
	$(MAKE) -C ../libasd

clean :
	rm -f *.o *.a
	$(MAKE) -C ../libasd clean
