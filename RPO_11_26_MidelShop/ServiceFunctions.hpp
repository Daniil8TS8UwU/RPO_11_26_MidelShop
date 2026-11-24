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
bool isNotSameName(const std::wstring& chooseName, std::wstring* nameArr, size_t commonSize);
template <class ArrType>
void ArrPushBack(ArrType*& arr, size_t arrSize)
{
	arrSize++;
	ArrType* temp = new ArrType[arrSize];
	for (size_t i = 0; i < arrSize - 1; i++)
	{
		temp[i] = arr[i];
	}
	std::swap(arr, temp);
	delete[]temp;

}

template <class ArrType>
void ArrDeleteByIndex(ArrType*& arr, size_t arrSize, int index)
{
	arrSize--;
	ArrType* temp = new ArrType[arrSize];
	for (size_t i = 0, j = 0; i < arrSize; i++, j++)
	{

		if (j == index)
		{
			j++;
		}

		temp[i] = arr[j];
	}
	std::swap(arr, temp);
	delete[]temp;
}

#endif // !_SERVICEFUNCTIONS_HPP_

