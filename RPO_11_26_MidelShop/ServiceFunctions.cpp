#include "ServiceFunctions.hpp"

void Getline(std::wstring& str)
{
	std::getline(std::wcin, str, L'\n');
}

bool IsNumber(const std::wstring& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::wcout << L"Ошибка длины. Максимум 9 значные числа\n\n";
		return false;
	}

	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::wcout << L"Введенные данные не являются числом\n\n";
			Sleep(1500);
			return false;
		}
	}
	return false;
}

bool IsNotSameName(const std::wstring& chooseName, std::wstring* nameArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		if (chooseName == nameArr[i])
		{
			std::wcout << L"Такой товар уже есть на складе\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}