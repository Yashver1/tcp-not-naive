all: client server

client: client.cpp
	clang++ -std=c++20 -Wall -Wextra client.cpp -o client

server: server.cpp
	clang++ -std=c++20 -Wall -Wextra server.cpp -o server