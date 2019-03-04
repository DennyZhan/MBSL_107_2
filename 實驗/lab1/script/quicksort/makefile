# 宣告編譯器, 目標及依賴文件
CC1 = arm-linux-gnueabihf-g++
CC2 = g++
STANDARD = -std=c++11

TARGET1 = main
TARGET2 = main_tk1
DEPENS = main.cpp sort.cpp


all: $(TARGET)

$(TARGET1): $(DEPENS)
	$(CC1) $(STANDARD) -o $@ $^

$(TARGET2): $(DEPENS)
	$(CC2) $(STANDARD) -o $@ $^

run: all
	./$(TARGET)

clean:
	rm $(TARGET)