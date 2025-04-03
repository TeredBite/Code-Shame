#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
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
    cout << "Выберите номер действия: " << endl
        << "1 - Первое задание." << endl
        << "2 - Второе задание." << endl
        << "3 - Третье задание." << endl
        << "4 - Выход из программы." << endl;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case (1):
    {
        string line;
        cout << "Введите строку: ";
        getline(cin, line);
        bool check = CheckBinary(line);

        while (!check)
        {
            cout << "Ошибка ввода. Введите корректную строку." << endl;
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
        cout << "Выберите способ обработки строки:" << endl;
        cout << "1 - std::string\n2 - C-строки (массив символов)" << endl;
        int methodChoice;
        cin >> methodChoice;
        cin.ignore();

        if (methodChoice == 1) // string
        {
            string filename;
            cout << "Введите название файла: ";
            cin >> filename;
            cin.ignore();

            ifstream file(filename);
            if (!file) {
                cerr << "Ошибка открытия файла!" << endl;
                exit(1);
            }
            string line;
            getline(file, line);
            file.close();

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

            cout << "Слова длиной 3 символа:" << endl;
            for (int i = 0; i < wordCount; i++)
            {
                if (words[i].size() == 3)
                {
                    cout << words[i] << endl;
                }
            }

            delete[] words;
        }
        else if (methodChoice == 2) // C-строки
        {
            string filename;
            cout << "Введите название файла: ";
            cin >> filename;
            cin.ignore();

            ifstream file(filename);
            if (!file) {
                cerr << "Ошибка открытия файла!" << endl;
                exit(1);
            }
            string fileContent;
            getline(file, fileContent);
            file.close();

            char line[256];
            strncpy(line, fileContent.c_str(), 255);
            line[255] = '\0';

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

            cout << "Слова длиной 3 символа:" << endl;
            for (int i = 0; i < wordCount; i++)
            {
                if (strlen(words[i]) == 3)
                {
                    cout << words[i] << endl;
                }
            }
        }
        else
        {
            cout << "Неправильный выбор метода!" << endl;
        }
        break;
    }
    case (3):
    {
        string filename;
        cout << "Введите название файла: ";
        cin >> filename;
        cin.ignore();

        ifstream file(filename);
        if (!file) {
            cerr << "Ошибка открытия файла!" << endl;
            exit(1);
        }

        string word;
        int count = 0;
        while (file >> word)
        {
            if (word.length() == 5)
            {
                count++;
            }
        }
        file.close();

        cout << "Количество слов из пяти букв: " << count << endl;
        break;
    }
    case (4):
    {
        break;
    }
    default:
        cout << "Неправильный выбор. Введите число от 1 до 4." << endl;
    }
}
