import Modulin;
#include <iostream>

auto main(int argumentos, char** linhas) -> int {
	int menu{};
	std::cout << "--BEM VINDO A CALCULADORA FODA--"
		<< "\nInsira qual operacao voce deseja realizar:"
		<<"\nQualquer numero diferente das opcoes para sair"
		<< "\n1 para soma"
		<< "\n2 para subtracao"
		<< "\n3 para produto"
		<< "\n4 para divisao"
		<< "\n5 para potenciacao"
		<< "\n6 para raiz quadrada"
		<< "\n\ninput: ";
	std::cin >> menu;
	if (menu>0 && menu <6)
		calculate::operacao(comando, menu);
	else if (menu == 6)
		calculate::raiz();
	else {
		std::cout << "Cabo";
		return 0;
	}
	
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}