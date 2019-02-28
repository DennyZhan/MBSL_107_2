# 宣告編譯器, 目標及依賴文件
CC = g++ -std=c++11
target = main.out
main = main.cpp
dependencies = sort.cpp

all: $(target) run

$(target): $(main) $(dependencies)
	$(CC) -o $@ $^

run: all
	./$(target)

clean:
	rm $(target)