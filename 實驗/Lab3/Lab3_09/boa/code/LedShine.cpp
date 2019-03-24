#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <iostream>
#include <vector>
#include "GPIOControl.h"
using namespace std;


vector<string> getValues(string data)
{
	vector<string> values;

	values.clear();
	for (int i = 0; i < data.size(); ++i) {
		if (data[i] == '=') {
			for (int j = i + 1; j < data.size(); ++j) {
				if (j == (data.size() - 1)) {
					values.push_back(data.substr(i + 1, j - i));
					break;
				}
				else if (data[j] == '&') {
					values.push_back(data.substr(i + 1, j - i - 1));
					break;
				}
			}
		}
	}

	return values;
}


int main()
{
	const int leds[4] = { 190, 191, 192, 193 };
	string input;
	int times = 0;
	vector<string> values;

	// 讀入字串併分割
	input = getenv("QUERY_STRING");
	values = getValues(input);
	// 輸出資訊至html
	cout << "<!DOCTYPE html>"
		<< "<html lang = \"en\">"
		<< "<head>"
		<< "<meta charset = \"UTF-8\">"
		<< "<meta name = \"viewport\" content = \"width=device-width, initial-scale=1.0\">"
		<< "<meta http - equiv = \"X-UA-Compatible\" content = \"ie=edge\">"
		<< "<title>Lab3 - Response</title>"
		<< "</head>"
		<< "<body>"
		<< "<h1>輸入資料</h1>"
		<< "<p>閃爍 " << times << "次</p>"
		<< "</body>"
		<< "</html>" << endl;
    // 設定LED
    times = stoi(values[0]);
    for (int i = 0; i < 4; ++i) {
        ioExport(leds[i]);
        ioSetDir(leds[i], "out");
        ioSetValue(leds[i], 0);
    }
	// 開始閃爍
    for (int i = 0; i < times; ++i) {
        ioSetValue(leds[0], 1);
		ioSetValue(leds[1], 1);
		ioSetValue(leds[2], 0);
		ioSetValue(leds[3], 0);
        sleep(1);
		ioSetValue(leds[0], 0);
		ioSetValue(leds[1], 0);
		ioSetValue(leds[2], 1);
		ioSetValue(leds[3], 1);
        sleep(1);
    }

	return 0;
}