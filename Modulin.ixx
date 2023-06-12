
import <cmath>;
import <iostream>;
import <vector>;
import <string>;
import <map>;

export module Modulin;

long long some(const std::vector<long long>& vetor);
long long subtraia(const std::vector<long long>& vetor);
long long multiplique(const std::vector<long long>& vetor);
long long divida(const std::vector<long long>& vetor);
long long potencia(const std::vector<long long>& vetor);
export long long (*comando[])(const std::vector<long long>&) { some, subtraia, multiplique, divida, potencia };



export namespace calculate {

	void operacao(long long (*comando[])(const std::vector<long long>&), int qual) {
		long long result{};
		std::map<int, std::string> mapa{{0, "somados"}, { 1,"subtraidos" }, { 2,"multiplicados" }, { 3,"divididos" }, { 4,"Elevados a potencia dada uma base" }};

		std::cout << "Insira os numeros a serem " << mapa[qual - 1];
		if (qual == 4)
			std::cout << "(insira pare, qualquer letra ou 0 para parar)\n";
		else
			std::cout << " (insira ""pare"" ou qualquer letra para parar)\n";
		std::string input;
		std::vector<long long> vetor;
		long long i{ 1 };
		while (i) {
			try {
				std::cin >> input;
				vetor.push_back(std::stoi(input));
			}
			catch (std::invalid_argument) {
				result=comando[qual - 1](vetor);
				i = false;
			}
		}
		std::cout << "O resultado equivale a " << result << "\n";
	}
	void raiz() {
		long long result{};
		std::cout << "Insira o numero ao qual deseja saber a raiz\n";
		std::cin >> result;
		std::cout << "O resultado desta raiz equivale a " << sqrt(result);
	}

} //fim do namesapce calculate

long long some(const std::vector<long long>& vetor) {
	long long result{};
	for (auto i : vetor)
		result += i;
	return result;
}
long long subtraia(const std::vector<long long>& vetor) {
	long long result{vetor.at(0)};
	for (auto i=vetor.begin()+1;i!=vetor.end();++i)
		result -= *i;
	return result;
}

long long multiplique(const std::vector<long long>& vetor) {
	long long result{ 1 };
	for (auto i : vetor)
		result *= i;
	return result;
}

long long divida(const std::vector<long long>& vetor) {
	long long result{ vetor.at(0) };
	for (auto i = vetor.begin() + 1; i != vetor.end(); ++i) {
		result /= *i;
	}
	return result;
}

long long potencia(const std::vector<long long>& vetor) {
	long long result{ vetor.at(0) };
	try {
		for (auto i = vetor.begin() + 1; i != vetor.end(); ++i) {
			result = pow(static_cast<float>(result), static_cast<float>(*i));
		}
	}
	catch (...) {
		std::cerr << "Comando nao concluido.\n";
		return 0;
	}
	return result;
}