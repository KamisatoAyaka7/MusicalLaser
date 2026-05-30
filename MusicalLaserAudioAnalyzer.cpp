#include<iostream>
#include<fstream>
#include<string>

using namespace std;

constexpr int length = 1100;

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	constexpr char fileNames[14][16] = {
		"D:/Audio/A4.wav",
		"D:/Audio/A5.wav",
		"D:/Audio/B4.wav",
		"D:/Audio/B5.wav",
		"D:/Audio/C5.wav",
		"D:/Audio/C6.wav",
		"D:/Audio/D5.wav",
		"D:/Audio/D6.wav",
		"D:/Audio/E5.wav",
		"D:/Audio/E6.wav",
		"D:/Audio/F5.wav",
		"D:/Audio/F6.wav",
		"D:/Audio/G5.wav",
		"D:/Audio/G6.wav"
	};

	char fcontent[14][length * 2] = { {0} };

	for (int i = 0; i < 14; i++)
	{
		ifstream f(fileNames[i], ios::in | ios::binary);
		f.seekg(8864);
		f.read(fcontent[i], static_cast<streamsize>(length) * 2);
		f.close();
	}

	uint16_t content[14][length] = { {0} };
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < length; j++)
		{
			content[i][j] = 0;
			content[i][j] += fcontent[i][j * 2];
			content[i][j] += fcontent[i][j * 2 + 1]<<8;
			printf("%#X, ", content[i][j]);
		}
		printf("\n\n\n\n");
	}
	

	/*
#pragma warning(suppress : 4996)
	void *_ = freopen("D:/Audio/note_map.h", "w+", stdout);
	printf("#pragma once\n");
	for (int i = 0; i < 14; i++)
	{
		string note = string("const int16_t ");
		note += fileNames[i][9];
		note += fileNames[i][10];
		note += "[";
		note += to_string(length);
		note += "]";
		note += " = \n{\n\t";
		printf("%s", note.c_str());
		for (int j = 0; j < length; j++)
			if (j < length - 1) 
			{
				printf("%#x, ", content[i][j]);
				if ((j + 1) % 5 == 0)
					printf("\n\t");
			}
			else
				printf("%#x\n}", content[i][j]);
		printf("\n\n\n\n");
	}
	fclose(stdout);
	*/
}