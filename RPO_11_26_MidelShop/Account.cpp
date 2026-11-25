#include "Account.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize]{ L"admin",L"user1",L"user2" };
std::wstring* passArr = new std::wstring[userSize]{ L"admin",L"user1",L"user2" };
std::wstring* startusArr = new std::wstring[userSize]{ L"SuperAdmin",L"Admin",L"User" };
unsigned int* userIdArr = new unsigned int[userSize] {0, 1, 2};

size_t maxLogin = 15;
size_t minLogin = 5;
size_t maxPass = 20;
size_t minPass = 8;

bool isSetCreated = false;

std::unordered_set<wchar_t> loginSymbols;
std::unordered_set<wchar_t> passSymbols;

void ChangeAccounts()
{
	std::wstring choose;

	if (!isSetCreated)
	{
		CreateSet();
	}

	while (true)
	{

		system("cls");

		std::wcout << L"\n\n\t\t\t= Редактирование учетных записей =\n\n";
		std::wcout << L"\t1 - Создать новый аккаунт\n";
		std::wcout << L"\t2 - Показать всех сотрудников\n";
		std::wcout << L"\t3 - Изменить пароль\n";
		std::wcout << L"\t4 - Изменить уровни доступа\n";
		std::wcout << L"\t5 - Редактировать премии и штрафы сотрудников\n";
		std::wcout << L"\t6 - Удалить аккаунт\n";
		std::wcout << L"\t0 - Выход\n";
		std::wcout << L"\tВвод: ";
		Getline(choose);
		if (choose == L"1")
		{
			
		}
		else if (choose == L"2")
		{
		
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
		else if (choose == L"0")
		{
			std::wcout << L"\n\n\t= Выход из редактора учетных записей =\n";
			Sleep(1500);
			break;
		}
		else
		{
			Error();
		}
	}
}

void CreateNewAccount()
{
	std::wstring chooseLogin, choosePass, chooseStatus, choose;

	while (true)
	{
		while (true)
		{
			system("cls");
			std::wcout << L"Введите логин нового пользователя или \"exit\" для выхода -- ";
			Getline(chooseLogin);
			if (chooseLogin == L"exit" || chooseLogin == L"Exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}
			if ((CheckLogin(chooseLogin)))
			{
				break;
			}
			else
			{
				Error();
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"Введите пароль нового пользователя или \"exit\" для выхода -- ";
			Getline(choosePass);
			if (choosePass == L"exit" || choosePass == L"Exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}
			if (CheckPass(choosePass))
			{
				break;
			}
			else
			{
				Error();
			}
		}
	}
}



void CreateSat()
{
	for (wchar_t i = L'0'; i <= L'9'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = L'A'; i <= L'Z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = L'a'; i <= L'z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = L'!'; i <= L'~'; i++)
	{
		passSymbols.insert(i);
	}
}

bool CheckLogin(const std::wstring& login)
{
	if (login.size() < minLogin || login.size() > maxLogin) 
	{
		std::wcout << L"Ошибка длины логинаю Допустимо от " << minLogin << L" до "
			<< maxLogin << L" символов\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < userSize; i++)
	{
		if (login == loginArr[i])
		{
			std::wcout << L"Такой пользователь уже есть";
		}
	}

	int count = 0;
	for (size_t i = 0; i < login.size(); i++)
	{
		if (loginSymbols.count(login[i]))
		{
			std::wcout << L"Некорректные символы логина!\n";
			std::wcout << L"Допустимые символы: A-Z, a-z, 0-9\n\n";
			Sleep(2000);
			return false;
		}
		else if (count < 3 && (login[i] >= L'A' && login[i] <= L'Z') || (login[i] >= L'a' && login[i] <= L'z'))
		{
			count++;
		}
	}

	if (count >= 3)
	{
		return true;
	}
	else
	{
		std::wcout << L"////" << count << L"\n\n";
		Sleep(2000);
		return false;
	}

	return true;
}

bool CheckPass(const std::wstring& pass)
{

	{
		if (pass.size() < minPass || pass.size() > maxPass)
		{
			std::wcout << L"Ошибка длины логинаю Допустимо от " << minPass << L" до "
				<< maxPass << L" символов\n\n";
			Sleep(1500);
			return false;
		}
		

		int count = 0;
		for (size_t i = 0; i < pass.size(); i++)
		{
			if (!loginSymbols.count(pass[i]))
			{
				std::wcout << L"Некорректные символы логина!\n";
				std::wcout << L"Допустимые символы: A-Z, a-z, 0-9\n\n";
				Sleep(2000);
				return false;
			}
			else if (count < 3 && (pass[i] >= L'A' && pass[i] <= L'Z') || (pass[i] >= L'a' && pass[i] <= L'z'))
			{
				count++;
			}
		}

		if (count >= 3)
		{
			return true;
		}
		else
		{
			std::wcout << L"////" << count << L"\n\n";
			Sleep(2000);
			return false;
		}

		return true;
	}
}