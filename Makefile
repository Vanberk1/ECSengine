build:
	g++ -w -std=c++17 -Wfatal-errors \
	./src/*.cpp -o game.exe \
	-I"C:\mingw64\include" \
	-L"C:\mingw64\lib" \
	-I"./lib/SDL2/include" \
	-L"./lib/SDL2/lib" \
	-lmingw32 \
	-lSDL2main \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2;

clean:
	rm ./game.exe;

run:
	./game.exe;
