all:
	g++ -std=c++11 gpio.cpp main.cpp -lpthread -o main.o
	arm-linux-gnueabihf-g++ -std=c++11 gpio.cpp main.cpp -lpthread -o main_tk1.o

clean:
	rm test.o
	rm main.o
