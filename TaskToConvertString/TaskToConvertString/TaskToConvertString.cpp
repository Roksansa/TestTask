#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <unordered_map>

/**
 * K - размер алфавита
 * N - размер входной строки
 * Сложность по памяти 0(N + K) - выходная строка + дополнительная память на хранение уникал. объектов
 * Сложность по производительности - 0(N) - проход по N-элементам и поиск по мапе (амортизиров О(1)).
 */
std::string ConvertStringToOtherString(const std::string& oldString)
{
	std::string str;
	str.resize(oldString.length());
	/* вместо мапы можно использовать массив, если мы точно знаем K допустимых значений,
	 * например, для string, который - std::basic_string<char>, размер массива был бы 256.
	 * но в общем случае N-символов по K-значному алфавиту могут быть сильно разрежены и тогда лучше использовать мапу.
	 */
	std::unordered_map<int, size_t> uniqChars;
	constexpr char oneTime = '(';
	constexpr char twoTime = ')';

	const size_t length = oldString.length();
	for (size_t i = 0; i < length; ++i)
	{
		int currentChar = std::tolower(oldString[i]);
		auto pair = uniqChars.find(currentChar);
		str[i] = twoTime;
		if (pair == uniqChars.end())
		{
			uniqChars.emplace(std::make_pair(currentChar, i));
			str[i] = oneTime;
		}
		else if (pair->second != length)
		{
			str[pair->second] = twoTime;
			pair->second = length;
		}
	}
	return str;
}


int main(int argc, char* argv[])
{
	while (true)
	{
		std::string stringIn;
		std::getline(std::cin, stringIn);
		const std::string stringOut = ConvertStringToOtherString(stringIn);
		std::cout << stringOut << " " << std::endl;
	}
	return 0;
}
