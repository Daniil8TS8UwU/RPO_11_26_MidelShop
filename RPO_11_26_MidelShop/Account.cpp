#include "Account.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize]{ L"admin",L"user1",L"user2" };
std::wstring* passArr = new std::wstring[userSize]{ L"admin",L"user1",L"user2" };
std::wstring* startusArr = new std::wstring[userSize]{ L"SuperAdmin",L"Admin",L"User" };
unsigned int* userIdArr = new unsigned int[userSize] {0, 1, 2};