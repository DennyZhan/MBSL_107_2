// 可控制的接腳數量
const unsigned int numIO = 4;
// 接腳對應的名稱
const unsigned int IONames[numIO] = {160, 161, 162, 163};

int ExportIO(unsigned int index);
int UnexportIO(unsigned int index);
int SetIODir(unsigned int index, int inout=1);
int SetIOValue(unsigned int index, int value);
