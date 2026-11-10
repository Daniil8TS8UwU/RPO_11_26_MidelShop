#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;

void CreateStorage(int mode)
{
	const size_t staticSize = 10;

	size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::wstring nameArrStatic[staticSize]
	{
		L"Полимерная глина \"Clay & Craft\" серая", 
		L"Набор для глиномеса \"PRO|CLAY\""
		L"Бумага холстовая А5 \"Камета\""
		L"Акриловая краска \"WarCastele\" для моделизма"
		L""
		L""
	};
	//Доделать!!!
	size_t countArrStatic[staticSize];
	double priceArrStatic[staticSize];
}