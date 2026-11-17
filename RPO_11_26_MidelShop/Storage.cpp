#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;

bool isStoregeCreated = false;
size_t maxStorageSize = 2000;
size_t currentStorageSize = 0;


void CreateStorage(int mode)
{
	if (mode == 0 && !isStoregeCreated)
	{
		const size_t staticSize = 16;

		size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
		std::wstring nameArrStatic[staticSize]
		{
			L"Полимерная глина \"Clay & Craft\" черная 50 г", L"Полимерная глина \"Clay & Craft\" серая 50 г", L"Полимерная глина \"Clay & Craft\" белая 50 г",
			L"Полимерная глина \"Clay & Craft\" черная 250 г", L"Полимерная глина \"Clay & Craft\" серая 250 г", L"Полимерная глина \"Clay & Craft\" белая 250 г",
			L"Набор инструментов для глиномеса \"PRO|CLAY\"", L"Набор кистей для рисования \"Камета\"", L"Влажная палитра для акрила \"WarCastele\"",
			L"Бумага холстовая А4 \"Камета\"", L"Скетчбук А5 80 старниц \"Бетта\"",
			L"Акриловая краска \"WarCastele\" для моделизма 12 цвета по 12 мл", L"Шейды для моделизма 20 мл", L"Гуашь \"Камета\" для рисования 12 цветов 15 мл",
			L"Ручки шариковые \"Камета\"", L"Карандаши \"Камета\"",
		};
		//Доделать!!!
		size_t countArrStatic[staticSize]{ 331,332,333,341,342,343,25,52,31,4,17,4012,4060,245,10,20 };
		double priceArrStatic[staticSize]{ 219.5,220.0,219.5,745.3,750.6,745.3,1250.9,934.3,405.8,24.9,450.2,2300.4,700.8,650.3,44.9,35.0 };

		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new 	size_t[sizeSt];
		priceArr = new double[sizeSt];

		FillArray(idArr, idArrStatic, sizeSt);
		FillArray(nameArr, nameArrStatic, sizeSt);
		FillArray(countArr, countArrStatic, sizeSt);
		FillArray(priceArr, priceArrStatic, sizeSt);

		for (size_t i = 0; i < sizeSt; i++)
		{
			currentStorageSize += countArrStatic[i];
		}


		isStoregeCreated = true;
	}

	else if (mode == 1)
	{
		//to
	}
	else
	{
		std::wcout << L"= Cкдад уже создан! =";
	}
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\t\t= Склад товаров для рукоделия =\n\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\t" << L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}

		std::wcout << L"\n\n";
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\t= Пополнение склада =\n\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}

		std::wcout << L"\n\n";

		std::wcout << L"Заполненность склада: " << currentStorageSize << L" из "
			<< maxStorageSize << L"\n\n";
	}
}

void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;

	while (true)
	{
		ShowStorage(1);
		std::wcout << L"\n\n= Введите ID товара или \"exit\" для выхода -- ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции попонения товара\n\n";
			Sleep(1600);
			return;
		}
		else if (IsNumber(chooseId))
		{ 
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Error();
			}
			else
			{
				std::wcout << L"Введите количество товара для пополнения -- ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);
					// проверить есть ли куда положить товар ЗАКОНЧИТЬ
				}
			}
		}
	}
}

