all: bin/deconoha bin/deconoha-png bin/deconoha-ogg

bin/deconoha-png:
	mkdir -p bin
	cc -o bin/deconoha-png deconoha-png.c

bin/deconoha-ogg:
	mkdir -p bin
	cc -o bin/deconoha-ogg deconoha-ogg.c

bin/deconoha:
	mkdir -p bin
	cc -o bin/deconoha deconoha.c

clean:
	rm -rf bin
