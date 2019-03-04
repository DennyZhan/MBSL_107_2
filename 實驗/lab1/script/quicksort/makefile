# 宣告編譯器, 目標及依賴文件
CC1 = g++
CC2 = arm-linux-gnueabihf-g++  # 跨平台編譯
STANDARD = -std=c++11  #使用標準

TARGET1 = main
TARGET2 = main_tk1  # 跨平台編譯輸出
DEPENS = main.cpp sort.cpp
# 產生檔案以ssh將檔案複製到該位置
USER = ubuntu  # 使用者名稱
ID = 192.168.0.1  # tk1對應id
DIR = /home/ubunto/...  # 本機位置
TK1_DIR = /home/ubunto/  # 目標位置


all: $(TARGET1) $(TARGET2)

$(TARGET1): $(DEPENS)
	$(CC1) $(STANDARD) -o $@ $^

$(TARGET2): $(DEPENS)
	$(CC2) $(STANDARD) -o $@ $^
	
move:
	scp $(USER)@$(IP):DIR 

run: all
	./$(TARGET)

clean:
	rm $(TARGET)