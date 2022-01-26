/*
* Вычислить целочисленное выражение, указанное в варианте задания.
* При этом, и операнды и результаты вычислений следует выводить как в десятичном,
* так и в шестнадцатеричном виде.
* A (word), B (byte), C (dword).
* Вычислить: D = C - A / B; E = B * B - A + C.
*/

#include <iostream>
#include <cstdlib>

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	__int16 A = -1000; // word
	__int8 B = 10; // byte
	__int32 С = 3000; // dword
	__int32 D; // результат выражения D = C - A / B
	__int32 E; // результат выражения E = B * B - A + C

	__asm // D = C - A / B
	{
		movsx eax, A; // запись переменной A в регистр eax
		movsx ebx, B; // запись переменной B в регистр ebx

		cdq; // преобразование eax в 8-байтовое значение в паре регистров edx:eax (со знаком)
		idiv ebx; // деление eax = eax / ebx = A / B

		mov edx, С; // запись переменной C в регистр edx
		sub edx, eax; // вычитание edx = edx - eax = C - A / B

		mov D, edx; // запись содержимого edx в переменную D
	}

	printf("D в десятичной = %d", D);
	printf("\nD в шестнадцатиричной = %x", D);
	printf("\n\n");

	__asm // E = B * B - A + C
	{
		movsx eax, A; // запись переменной A в регистр eax
		movsx ebx, B; // запись переменной B в регистр ebx
		mov edx, С; // запись переменной С в регистр eсx

		imul ebx, ebx; // умножение ebx = ebx * ebx = B * B

		sub ebx, eax; // вычитание ebx = ebx - eax = B * B - A
		add ebx, edx; // сложение ebx = ebx + ecx = B * B - A + C
		mov E, ebx; // запись содержимого ebx в переменную E
	}

	printf("E в десятичной = %d", E);
	printf("\nE в шестнадцатиричной = %x", E);
	printf("\n\n");

	system("PAUSE");
	return 0;
}