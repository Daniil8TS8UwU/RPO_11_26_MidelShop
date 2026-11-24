#include "Storage.hpp"
#include "Account.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;

bool isStoregeCreated = false;

size_t maxStorageSize = 500;
size_t currentStorageSize = 0;
double maxPrice = 100000;

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
		size_t countArrStatic[staticSize]{ 9,7,7,6,4,5,5,5,3,4,13,8,15,10,35,25 };
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

		std::wcout << L"ID\t" << std::left << std::setw(70) << L"Название товара\t\t"
			<< L"Кол-во\t" << L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(70) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}

		std::wcout << L"\n\n";
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\t= Пополнение товаров склада =\n\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(70) << L"Название товара\t"
			<< L"Кол-во\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(70) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}

		std::wcout << L"\n\nЗаполненность склада: " << currentStorageSize << L" из "
			<< maxStorageSize << L"\n\n";
	}
	else if (mode == 2)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\t= Cписание товаров склада =\n\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(70) << L"Название товара\t"
			<< L"Кол-во\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(70) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}

		std::wcout << L"\n\n";

		std::wcout << L"\n\nЗаполненность склада: " << currentStorageSize << L" из "
			<< maxStorageSize << L"\n\n";
	}
	else if (mode == 3)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tИзменение цены\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(70) << L"Название товара\t"
			<< L"Кол-во\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(70) << nameArr[i]
				<< std::setprecision(2) << priceArr[i] << L"\n";
		}
	}
	else if (mode == 4)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tИзменение названия товара\n\n";

		std::wcout << L"ID\t" << L"Название товара\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(70) << nameArr[i]
				<< L"\n";
		}
		std::wcout << L"\n\n";
	}
	else if (mode == 5)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tУдаление товара\n\n";

		std::wcout << L"ID\t" << L"Название товара\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(70) << nameArr[i]
				<< L"\n";
		}
		std::wcout << L"\n\n";
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
			std::wcout << L"\n\nЗавершение операции попонения товара ";
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
				std::wcout << L"\n\n Введите количество товара для пополнения -- ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);
					if (count > maxStorageSize - currentStorageSize || count < 0)
					{
						std::wcout << L"\n\nНекорретное количество! На складе осталось "
							<< maxStorageSize - currentStorageSize << L" свободных мест\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L"---->"
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"\n\nПодтвердить?\n1 - Да\n2 - Нет\n\nВвод -- ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"\n\nТовар успешно пополнен\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"\n\nОтмена пополнения " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Error();
							}
						}
					}
				}
			}
		}
	}
}

void RemoveProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;

	while (true)
	{
		ShowStorage(2);
		std::wcout << L"\n\n= Введите ID товара или \"exit\" для выхода -- ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"\n\nЗавершение операции списания товара ";
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
				std::wcout << L"\n\n Введите количество товара для списания -- ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);
					if (count < 0 || count > countArr[id])
					{
						std::wcout << L"\n\nНекорретное количество! На складе осталось "
							<< maxStorageSize - currentStorageSize << L"";
					}
					else
					{
						while (true) 
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L"---->"
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"\n\n\tПодтвердить?\n1 - Да\n2 - Нет\n\nВвод -- ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"\n\n\tТовар успешно списан\n\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"\n\n\tОтмена пополнения " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Error();
							}
						}
					}
				}
			}
		}
	}
}

void ChangerPrise()
{
	std::wstring chooseId, choosePrice, choose;
	int id = 0;
	double price = 0;

	while (true)
	{
		ShowStorage(3);
		std::wcout << L"\n\n\tВведите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"\n\n\tЗавершение операции списания товара";
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
				std::wcout << L"\n\n\tВведите новую цену товара -- ";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price < 0 || price > maxPrice)
					{
						std::wcout << L"\n\n\t= Некорректная цена! Максимально возмжная цена: "
							<< maxPrice << L" рублей\n\n" ;
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << priceArr[id] << L" -----> "
								<< price;
							std::wcout << L"\n\n\tПодтвердить?\n1 - Да\n2 - Нет\n\nВвод -- ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"\n\n\t= Успешное изменение цены";
								priceArr[id] = price;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена изменения цены " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Error();
							}
						}
					}
				}
			}
		}

	}
}


void ChangerStorage()
{
	std::wstring choose;

	while (true)
	{

		system("cls");

		std::wcout << L"\n\n\t\t\tРедактирование склада \n\n";
		std::wcout << L"\t1 - Добавить новый товар\n";
		std::wcout << L"\t2 - Изменить название товара\n";
		std::wcout << L"\t3 - Удаление товара\n";
		std::wcout << L"\t4 - Изменить лимиты склада\n";
		std::wcout << L"\t0 - Выход\n";
		std::wcout << L"\tВвод: ";
		Getline(choose);
		if (choose == L"1")
		{
			AddNewProduct();
		}
		else if (choose == L"2" && sizeSt > 0)
		{
			ChangeProductName();
		}
		else if (choose == L"3" && sizeSt > 0)
		{
			DeleteProduct();
		}
		else if (choose == L"4")
		{

		}
		else if (choose == L"0")
		{
			std::wcout << L"\n\n\t= Выход из редактора склада =\n";
			Sleep(1500);
			break;
		}
		else
		{
			if (sizeSt < 1)
			{
				std::wcout << L"\n\n\t= Склад пуст =\n";
			}
			Error();
		}
	}
}

void AddNewProduct()
{
	std::wstring chooseName, choose;

	while (true)
	{
		while (true)
		{
			system("cls");

			std::wcout << L"Введите название нового товара или \"exit\" для выхода: ";
			Getline(chooseName);
			if (chooseName == L"exit" || chooseName == L"Exit")
			{
				std::wcout << "Отмена создания нового товара";
				Sleep(1500);
				return;
			}

			//ДОДЕЛАТЬ

			while (true)
			{
				system("cls");

				std::wcout << L"Введите колличество нового товара или ..."; //ДОДЕЛАТЬ
			}

			//ДОПОЛНИТЬ И СКОПИРОВАТЬ

			system("cls");


		}
	}
}

void ChangeProductName()
{
	std::wstring chooseId, chooseName, choose;
	int id = 0;
	while (true)
	{
		ShowStorage(4);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции изменения названия товара\n\n";
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
				std::wcout << L"Введите новое название для товара: ";
				Getline(chooseName);
				if (chooseName == L"exit" || chooseName == L"Exit")
				{
					std::wcout << L"Отмена создания нового товара\n\n";
					Sleep(1500);
					return;
				}
				if (chooseName.size() < 3 || chooseName.size() > 40)
				{
					std::wcout << L"Ошибка длины названия товара\nДопустимое значение от 3 до 40 символов\n\n";
					Sleep(1500);
					continue;
				}
				if (IsNotSameName(chooseName, nameArr, sizeSt))
				{
					continue;
				}
				else
				{
					while (true)
					{
						system("cls");
						std::wcout << nameArr[id] << L"----->" << chooseName << L"\n\n";

						std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
						Getline(choose);

						if (choose == L"1")
						{
							std::wcout << L"Успешное изменение названия товара\n\n";
							nameArr[id] = chooseName;
							Sleep(1500);
							break;
						}
						else if (choose == L"2")
						{
							std::wcout << L"Отмена изменения названия " << nameArr[id] << L"\n";
							Sleep(1500);
							break;
						}
						else
						{
							Error();
						}
					}
				}
			}
		}
	}

}
void DeleteProduct()
{
	std::wstring chooseId, pass;
	int id = 0;
	while (true)
	{

		ShowStorage(5);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции удаления товара\n\n";
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

				std::wcout << L"Подтвердите удаление товара: " << nameArr[id] << L"\nПароль Супер Админа: ";
				Getline(pass);
				if (pass == passArr[0])
				{
					std::wcout << L"Удаление товара";
					for (size_t i = 0; i < 5; i++)
					{
						Sleep(500);
						std::wcout << L".";
					}
					Sleep(500);
					ArrDeleteByIndex(idArr, sizeSt, id);
					ArrDeleteByIndex(nameArr, sizeSt, id);
					currentStorageSize -= countArr[id];
					ArrDeleteByIndex(countArr, sizeSt, id);
					ArrDeleteByIndex(priceArr, sizeSt, id);
					sizeSt--;

					for (size_t i = id; i < sizeSt; i++)
					{
						idArr[i] = i + 1;
					}
					// Доделать
					std::wcout << L"\n\nТовар успешно удален\n";
					Sleep(1500);
					continue;
				}
				else
				{
					Error();
				}

			}
		}



	}
}
