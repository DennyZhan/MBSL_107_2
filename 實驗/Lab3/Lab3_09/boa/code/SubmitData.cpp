#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
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
	string input, dataType, data;
	vector<string> values;

	// 讀入字串
	input = getenv("QUERY_STRING");
	// 分割字串
	values = getValues(input);
	// 解析字串
	if (values[0] == "number")
		dataType = "學號";
	else
		dataType = "姓名";
	data = values[1];
	// 輸出html
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
		<< "<p>" << dataType << ": " << data << "</p>"
		<< "</body>"
		<< "</html>" << endl;

	return 0;
}