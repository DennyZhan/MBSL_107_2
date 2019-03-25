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
    const int leds[4] = { 160, 161, 162, 163 };
	string input, ledOnoffs[4];
	vector<string> values;

	// 讀入字串並分割
	input = getenv("QUERY_STRING");
	values = getValues(input);
	// 設定LED
	for (int i = 0; i < 4; ++i) {
		ledOnoffs[i] = values[i];

		ioExport(leds[i]);
		ioSetDir(leds[i], "out");
		if (ledOnoffs[i] == "on")
			ioSetValue(leds[i], 1);
		else
			ioSetValue(leds[i], 0);
	}
	// 輸出html
	cout << "Content-type:text/html\n\n" << endl
		<< "<!DOCTYPE html>"
		<< "<html lang = \"en\">"
		<< "<head>"
		<< "<meta charset = \"UTF-8\">"
		<< "<meta name = \"viewport\" content = \"width=device-width, initial-scale=1.0\">"
		<< "<meta http - equiv = \"X-UA-Compatible\" content = \"ie=edge\">"
		<< "<title>Lab3 - Response</title>"
		<< "</head>"
		<< "<body>"
        << "<h1>輸入資料</h1>"
		<< "<p>led1:" << ledOnoffs[0] << "</p>"
		<< "<p>led1:" << ledOnoffs[1] << "</p>"
		<< "<p>led1:" << ledOnoffs[2] << "</p>"
		<< "<p>led1:" << ledOnoffs[3] << "</p>"
    	<< "</body>"
		<< "</html>" << endl;

    exit(0);
}
