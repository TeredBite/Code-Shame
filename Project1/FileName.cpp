#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

bool CheckBinary(string numbers)
{
	bool space = false;
	int size = numbers.size();
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] != ' ')
		{
			space = true;
			break;
		}
	}
	if (!space)
	{
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if ((numbers[i] != '1') && (numbers[i] != '0') && (numbers[i] != ' ')) {
			return false;
		}
	}
	return true;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	cout << "Выберите номер действие: " << endl 
        << "1 - Первое задание." << endl 
        << "2 - Второе задание." 
        << endl << "3 - Третье задание." 
        << endl << "4 - Выход из программы." << endl;
	cin >> choice;
	cin.ignore();
	switch (choice)
	{
	case (1):
	{
		string line;
		cout << "Введите строку:";
		getline(cin, line);
		bool check = CheckBinary(line);

		while (!check) 
		{
			cout << "Ошибка ввода. Введите корректную строку.";
			getline(cin, line);
			check = CheckBinary(line);
		}

		cout << "Введена корректная строка: " << line << endl;

		stringstream ss(line);
		string group;
		cout << "Группы с чётным количеством символов:" << endl;
		while (ss >> group)
		{
			if (group.size() % 2 == 0)
			{
				cout << group << endl;
			}
		}
		break;
	}

    case (2):
    {
        int methodChoice;
        cout << "Выберите способ обработки строки:" << endl;
        cout << "1 - std::string\n2 - C-строки (массив символов)" << endl;
        cin >> methodChoice;
        cin.ignore();

        if (methodChoice == 1) // string
        {
            cout << "Введите строку, где слова разделены пробелами и символами '/':" << endl;
            string line;
            getline(cin, line);

            for (char& ch : line)
            {
                if (ch == '/')
                {
                    ch = ' ';
                }
            }

            istringstream iss(line);
            string temp;
            int wordCount = 0;
            while (iss >> temp)
            {
                wordCount++;
            }

            if (wordCount == 0)
            {
                cout << "В строке нет слов." << endl;
                return 0;
            }

            string* words = new string[wordCount];

            istringstream iss2(line);
            int index = 0;
            while (iss2 >> temp)
            {
                words[index] = temp;
                index++;
            }

            int count3 = 0;
            cout << "\nСлова длиной 3 символа:" << endl;
            for (int i = 0; i < wordCount; i++)
            {
                if (words[i].size() == 3)
                {
                    cout << words[i] << endl;
                    count3++;
                }
            }

            if (count3 == 0)
            {
                cout << "Нет слов длиной 3 символа." << endl;
            }
            else
            {
                cout << "Количество слов длиной 3 символа: " << count3 << endl;
            }

            int totalLength = 0;
            for (int i = 0; i < wordCount; i++)
            {
                totalLength += words[i].size();
            }

            double avgLength = static_cast<double>(totalLength) / wordCount;
            cout << "Средняя длина слов: " << avgLength << endl;

            bool found = false;
            cout << "Слова средней длины:" << endl;
            for (int i = 0; i < wordCount; i++)
            {
                if (words[i].size() == static_cast<int>(avgLength))
                {
                    cout << words[i] << endl;
                    found = true;
                }
            }

            if (!found)
            {
                cout << "Таких слов нет." << endl;
            }

            cout << "Обратный порядок:" << endl;
            for (int i = wordCount - 1; i >= 0; i--)
            {
                cout << words[i] << " ";
            }
            cout << endl;
            delete[] words;
        }
        else if (methodChoice == 2) // Работа с C-строками
        {
            cout << "Введите строку (макс. 256 символов), где слова разделены пробелами и символами '/':" << endl;
            char line[256];
            cin.getline(line, 256);

            // Замена '/' на пробелы
            for (int i = 0; line[i] != '\0'; i++)
            {
                if (line[i] == '/')
                {
                    line[i] = ' ';
                }
            }

            char* words[50];
            int wordCount = 0;

            char* token = strtok(line, " ");
            while (token != nullptr)
            {
                words[wordCount] = token;
                wordCount++;
                token = strtok(nullptr, " ");
            }

            if (wordCount == 0)
            {
                cout << "В строке нет слов." << endl;
                return 0;
            }

            int count3 = 0;
            cout << "\nСлова длиной 3 символа:" << endl;
            for (int i = 0; i < wordCount; i++)
            {
                if (strlen(words[i]) == 3)
                {
                    cout << words[i] << endl;
                    count3++;
                }
            }

            if (count3 == 0)
            {
                cout << "Нет слов длиной 3 символа." << endl;
            }
            else
            {
                cout << "Количество слов длиной 3 символа: " << count3 << endl;
            }

            int totalLength = 0;
            for (int i = 0; i < wordCount; i++)
            {
                totalLength += strlen(words[i]);
            }

            double avgLength = static_cast<double>(totalLength) / wordCount;
            cout << "Средняя длина слов: " << avgLength << endl;

            bool found = false;
            cout << "Слова средней длины:" << endl;
            for (int i = 0; i < wordCount; i++)
            {
                if (strlen(words[i]) == static_cast<int>(avgLength))
                {
                    cout << words[i] << endl;
                    found = true;
                }
            }

            if (!found)
            {
                cout << "Таких слов нет." << endl;
            }

            cout << "Обратный порядок:" << endl;
            for (int i = wordCount - 1; i >= 0; i--)
            {
                cout << words[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Неправильный выбор метода!" << endl;
        }
        break;
    }

	default:
	{
		cout << "Неправильный выбор. Введите число от 1 до 4." << endl;
	}
	}
}