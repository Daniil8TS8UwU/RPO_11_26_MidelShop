#include "Authorization.hpp"
#include "ServiceFunctions.hpp"
#include "Account.hpp"

void Start()
{
	while (true)
	{
		if (Login())
		{
			if (currentStatus == L"SuperAdmin")
			{
				CreateStorage();
				SuperAdminMenu();
			}
			else if (currentStatus == L"Admin")
			{
				//0w0
			}
			else if (currentStatus == L"User")
			{
				//0w0
			}
			else 
			{
				std::wcerr << L"\n\n_CURRENT_STATUS_LOGIN_ERROR_\n\n";
			}
		}
		else
		{
			system("cls");
			std::wcout << L"\n\n\n\t\t\t= Всего доброго! :) =\n\n\n";
			Sleep(1500);
			break;
		}
	}
}

bool Login()
{
	std::wstring login, pass;

	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\t= Добро пожаловать! =\n\n\t\t-={ ТВОРЧЕСКАЯ СТУДИЯ }=- \n\t\t   (Товары для хобби)\n\n\n";
		std::wcout << L"\n\t= Введите логин или \"exit\" для выхода = -- ";
		Getline(login);

		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"\n\t= Введите пароль = -- ";
			Getline(pass);
			
			for (size_t i = 0; i < userSize; i++)
			{
				if (login == loginArr[i] && pass == passArr[i])
				{
					std::wcout << L"\n\t= Добро пожаловать =" << loginArr[i] << L" =\n";
					std::wcout << L"\n\t= Ваш уровень доступа: " << startusArr[i] << L" =\n";
					currentId = userIdArr[i];
					currentStatus = startusArr[i];
					return true;
				}
			}
			std::wcout << L"\n\t= Неверный логин или пароль! Повторите попытку =\n\n";
			Sleep(2000);
		}	
	}
}

void SuperAdminMenu()
{
	std::wstring choose;

	while (true)
	{
		system("cls");

		std::wcout << L"\n1 -- Начать продажу";
		std::wcout << L"\n2 -- Показать склад";
		std::wcout << L"\n3 -- Пополнить товары";
		std::wcout << L"\n4 -- Списать товар";
		std::wcout << L"\n5 -- Изменить цены";
		std::wcout << L"\n6 -- Редактировать склад";
		std::wcout << L"\n7 -- Редактировать сотрудников";
		std::wcout << L"\n8 -- Показать прибыль";
		std::wcout << L"\n0 -- ";
		std::wcout << L"\nВвод: ";
		Getline(choose);
		
		if (choose == L"1")
		{

		}
		else if (choose == L"2")
		{
			ShowStorage;
		}
		else if (choose == L"3")
		{

		}
		else if (choose == L"4")
		{

		}
		else if (choose == L"5")
		{

		}
		else if (choose == L"6")
		{

		}
		else if (choose == L"7")
		{

		}
		else if (choose == L"8")
		{

		}
		else if (choose == L"0")
		{

		}
		else
		{
			Error();
		}
	}
}