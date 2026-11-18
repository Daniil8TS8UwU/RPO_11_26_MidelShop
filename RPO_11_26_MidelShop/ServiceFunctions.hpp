#ifndef _SERVICEFUNCTIONS_HPP_
#define _SERVICEFUNCTIONS_HPP_

#include <Windows.h>
#include <string>
#include <iostream>
#include <iomanip>

void Getline(std::wstring& str);
bool IsNumber(const std::wstring& str);
bool IsNotSameName(const std::wstring& chooseName); //ДОДЕЛАТЬ

__forceinline void Error()
{
	std::wcout << L"\n\t\t= НЕКОРЕТНЫЙ ВВОД!! =\n\n";
	Sleep(1500);
}

template <class ArrType>
void FillArray(ArrType* dynamicArr, ArrType* staticArr, size_t commonSize) 
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

#endif // !_SERVICEFUNCTIONS_HPP_

