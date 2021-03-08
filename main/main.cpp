#include "Convertor.h"

int main() {
	Convertor sas;
	Arabic test_ar;
	for (int i = 1; i <= 100; i++)
	{
		test_ar.value = i;
		sas.ConvertToRoman(test_ar);
		sas.print();
		sas.ConvertToArabic(sas.get_roman());
		sas.print();
	}
	test_ar.value = 3845;
	sas.ConvertToRoman(test_ar);
	sas.print();
	Roman roma;
	roma.value = "MMMDCCCXLV";
	sas.ConvertToArabic(roma);
	sas.print();
	Roman roma1;
	roma1.value = "IIIIII";
	roma1 = sas.check(roma1);
	std::cout << roma1.value;
	return 0;
}