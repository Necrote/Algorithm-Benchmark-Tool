CC = gcc
CFLAGS=-w -I. -I/usr/include/glib-2.0 -I/usr/include/libgsf-1 -I/usr/include/libxml2 `pkg-config --cflags gtk+-3.0`
LDFLAGS=`pkg-config --libs gtk+-3.0`

goffice:ABTmain.o
	$(CC) -o ABTmain ABTmain.o $(LDFLAGS) $(CFLAGS)

run:ABTmain
	./ABTmain

.PHONY: clean

clean:
	rm *.o
