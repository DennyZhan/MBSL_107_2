# 編譯器
CC1=g++
CC2=arm-linux-gnueabihf-g++  # 跨平台編譯
STANDARD=-std=c++11  #使用標準
# 輸出
TARGET1=main
TARGET2=main_tk1
#依賴
DEPENS=main.cpp
# 跨平台傳送
USER=ubuntu  # 使用者名稱
IP=192.168.137.199  # tk1對應ida
DIR=/home/ubuntu/Documents/lab2  # 本機位置
TK1_DIR=/home/ubuntu/  # 目標位置


all: $(TARGET1) $(TARGET2)

$(TARGET1): $(DEPENS)
	$(CC1) $(STANDARD) -o $@ $^

$(TARGET2): $(DEPENS)
	$(CC2) $(STANDARD) -o $@ $^
	
move:
	scp $(DIR)/$(TARGET2) $(USER)@$(IP):$(TK1_DIR)

run:
	./$(TARGET)

clean:
	rm $(TARGET)
