make: prefers-color-scheme.c
	cc -Wall -o prefers-color-scheme prefers-color-scheme.c `pkg-config --cflags --libs glib-2.0 gio-2.0`

run:
	make
	./prefers-color-scheme

install:
	make
	strip ./prefers-color-scheme
	install -s ./prefers-color-scheme /usr/bin/

uninstall: /usr/bin/prefers-color-scheme
	rm /usr/bin/prefers-color-scheme
