#include <iostream>
//лямбда выражения
// в языке с++ лямбда выражения это анонимные функции
// они служат для обзода ряда граничения языков С и С++
// в частности невозможность создавать функции внутри других функций 
// невозможность передачи неглобальных переменных в другие функции без
// использования агрументов. 
// 
// у лямбда выражений есть свой собственный тип данных
// это не функция и данный тип нельзя упоминать в программе
// напрямую
// из за этой особенности такие типы называют Воландеморт типами
// 
// [захват контекста](аргументы)->Type{тело;}
// 
// 
// 
//
class MyNum {
public:
	MyNum() = default;
	MyNum(int val) :var(val) {}
	int var;
};

#include <algorithm>
#include <vector>

int main()
{
	int var{  };
	//                  //возможная к изменению
	//[var] (int a, int b)mutable -> void{ var = a + b; };
	//аргументы захваченные в контексте могут быть либо ссылками(изменяемые) либо параметрами(неизменяемые)

	auto finc = [&](int a, int b) -> void { 
		var = a + b; 
		};

	finc(03,014);
	std::cout << var;
	MyNum a(2), b(1);
	auto max_val = std::max(a, b,
		[](const MyNum& first,const MyNum& second)
		{return first.var < second.var; }
	);
	std::vector<MyNum> arrays;
	for (size_t i = 0; i < 26; i++)
	{
		arrays.push_back(26 - i);
	}
	std::cout << "\n";
	for (MyNum& el:arrays)
	{
		std::cout<<el.var<<" ";
	}

	std::sort(arrays.begin(), arrays.end(),
		[](const MyNum& first, const MyNum& second)
		{return first.var < second.var; }
		);

		std::cout << "\n";

		for (MyNum& el : arrays)
		{
			std::cout << el.var << " ";
		}

	return 0;
}

