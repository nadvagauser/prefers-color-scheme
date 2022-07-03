make:
	cc -Wall -o prefers-color-scheme prefers-color-scheme.c `pkg-config --cflags --libs glib-2.0 gio-2.0`

run:
	make
	./prefers-color-scheme
