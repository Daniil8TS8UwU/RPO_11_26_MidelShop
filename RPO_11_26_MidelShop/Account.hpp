#ifndef _ACCOUNTS_HPP_
#define _ACCOUNTS_HPP_

#include "ServiceFunctions.hpp"

extern std::wstring* loginArr;
extern std::wstring* passArr;
extern std::wstring* startusArr;
extern unsigned int* userIdArr;

extern size_t userSize;
extern size_t currentId;
extern std::wstring currentStatus;

extern size_t maxLogin;
extern size_t minLogin;
extern size_t maxPass;
extern size_t minPass;

extern std::unordered_set<wchar_t> loginSymbols;
extern std::unordered_set<wchar_t> passSymbols;

void ChangeAccounts();
void CreateNewAccount();

void CreateSet();
bool CheckLogin(const std::wstring& login);
bool CheckPass(const std::wstring& pass);

#endif // !_ACCOUNTS_HPP_