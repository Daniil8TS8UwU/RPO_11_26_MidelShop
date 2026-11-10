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
				//0w0
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
			std::wcout << L"\n\tНеверный логин или пароль. Повторите попытку\n\n";
			Sleep(2000);
		}	
	}
}