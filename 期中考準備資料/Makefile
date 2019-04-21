# 編譯器
CC = arm-linux-gnueabihf-g++	# 跨平台編譯
CC_STD = -std=c++11  			# 編譯器使用的C++版本
# 依賴文件
DEP = main.cpp					# 可多個文件
# 輸出文件
TRGT = main

all: $(TRGT)

$(TRGT): $(DEP)
	$(CC) $(CC_STD) -o $@ $^

run:
	./$(TRGT)

clean:
	rm $(TRGT)
