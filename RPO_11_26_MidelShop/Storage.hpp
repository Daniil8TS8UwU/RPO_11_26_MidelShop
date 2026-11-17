#ifndef _STORAGE_HPP_
#define _STORAGE_HPP_

#include "ServiceFunctions.hpp"

// размер склада
extern size_t sizeSt;
extern size_t *idArr;
extern std::wstring* nameArr;
extern size_t* countArr;
extern double* priceArr;

extern bool isStoregeCreated;
extern size_t maxStorageSize;
extern size_t currentStorageSize;

void CreateStorage(int mode = 0);
void ShowStorage(int mode = 0);
void AddProduct();


#endif // !_STORAGE_HPP_
