# 編譯器相關
CC = arm-linux-gnueabihf-g++	# 跨平台編譯器
STANDARD = -std=c++11			# 使用標準
# 輸入
DEPENS = SubmitData.cpp
#DEPENS = SetLedValue.cpp GPIOControl.cpp
#DEPENS = LedShine.cpp GPIOControl.cpp
# 輸出
TARGET = SubmitData.cgi
#TARGET = SetLedValue.cgi
#TARGET = LedShine.cgi

all: $(TARGET)

$(TARGET) : $(DEPENS)
	$(CC) $(STANDARD) -o $@ $^

run: all
	./$(TARGET)

clean:
	rm $(TARGET)