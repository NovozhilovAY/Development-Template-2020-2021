#include "Monom.h"
#include "Polinom.h"
void print_main_menu(Polinom& p1, Polinom& p2, Polinom& res)
{
	std::cout << "p1 = " << p1.to_str();
	std::cout << "   p2 = " << p2.to_str();
	std::cout << "   res = " << res.to_str() << std::endl;
	std::cout << "1) Add the polinoms"<< std::endl;
	std::cout << "2) Subtract the polinoms" << std::endl;
	std::cout << "3) Multiply the polinoms" << std::endl;
	std::cout << "4) Calculate polinom res" << std::endl;
	std::cout << "5) Input the polinoms again" << std::endl << std::endl;
	std::cout << "6) Exit" << std::endl;
	std::cout << "Enter your choice: ";
}
void calculate_polinom(Polinom& res)
{
	int x, y, z;
	std::cout << "Input X: ";
	std::cin >> x;
	std::cout << "Input Y: ";
	std::cin >> y;
	std::cout << "Input Z: ";
	std::cin >> z;
	std::cout << res.to_str() << " = " << res.Calculate(x, y, z) << std::endl;
}
void input_monom(Monom& m)
{
	int A, B, C, coef;
	std::cout << "Input coef: ";
	std::cin >> coef;
	std::cout << "Input A: ";
	std::cin >> A;
	std::cout << "Input B: ";
	std::cin >> B;
	std::cout << "Input C: ";
	std::cin >> C;
	Monom monom(coef, A, B, C);
	m = monom;
}

void input_polinom(Polinom& p)
{
	Monom m;
	
	int num_of_monoms;
	std::cout << "Input number of monoms: ";
	std::cin >> num_of_monoms;
	for (int i = 0; i < num_of_monoms; i++)
	{
		std::cout << "Input monom "<<i+1<<std::endl;
		input_monom(m);
		p += m;
	}
}

int main()
{
	Polinom p1;
	Polinom p2;
	Polinom res;
	int answer = 0;
	std::cout << "Input polinoms p1 and p2:\n";
	input_polinom(p1);
	input_polinom(p2);
	while (answer != 6)
	{
		system("cls");
		print_main_menu(p1,p2,res);
		std::cin >> answer;
		switch (answer)
		{
		case 1:
			res = p1 + p2;
			std::cout << p1.to_str() << "  +  " << p2.to_str() << " = " << res.to_str() <<std::endl;
			system("pause");
			break;
		case 2:
			res = p1 - p2;
			std::cout << p1.to_str() << "  -  " << p2.to_str() << " = " << res.to_str() << std::endl;
			system("pause");
			break;
		case 3:
			res = p1 * p2;
			std::cout << p1.to_str() << "  *  " << p2.to_str() << " = " << res.to_str() << std::endl;
			system("pause");
			break;
		case 4:
			calculate_polinom(res);
			system("pause");
			break;
		case 5:
			system("cls");
			std::cout << "Input polinoms p1 and p2:\n";
			p1.DelPolinom();
			p2.DelPolinom();
			res.DelPolinom();
			input_polinom(p1);
			input_polinom(p2);
			break;
		case 6:
			return 0;
		}
		
	}
	return 0;
}
