/*************************************************************
	Практическое занятие №4. Встроенные массивы.
							Простейшие алгоритмы сортировки и поиска.
							
*************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>

#define	  stop __asm nop


void printArray(int arr[], size_t size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void printArray(char arr[], size_t size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

bool checkUnique(int num, int arr[], size_t size) {
	bool check = true;
	for (int i = 0; i < size; i++) {
		if (arr[i] == num) {
			check = false;
			break;
		}
	}
	return check;
}


int main()
//Задания, помеченные * не являются обязательными. Но выполнение их крайне желательно!!!
{
	///////////////////////////////////////////////////////////////
	//			Указатели (продолжение)                              
	///////////////////////////////////////////////////////////////

			//Задание 1. Модификатор const. 
			//В каждом из заданий объявите указатель требуемого вида. 
			//Посредством каждого указателя попробуйте:
			//1) получить значение по адресу
			//2) записать новое значение по адресу
			//3) модифицировать указатель
	//Замечания:
	//1.операторы явного преобразования типа использовать не следует
	//2.если компилятор не позволяет выполнить операцию, то комментируйте эту строку с пояснением


			//Задание 1a. Указатель является константой. 
		//int x = 10;
		//int y = 20;
		//int* const ptr = &x;    // константный указатель на переменную типа int
		//y = *ptr;			// получили значение по адресу
		//*ptr = y;				// записали новое значение по адресу
		////ptr = &y;               // ошибка: нельзя изменить значение константного указателя
		//stop	 


			//Задание 1б. Указываемое значение является константой.
		//const int x = 10;
		//int y = 20;

		//const int *ptr = &x; 
		//y = *ptr;					  // получили значение по адресу
		//ptr = &y;					  // успешно модифицировали указатель
		////*ptr = 20;				  // нельзя изменить значение, на которое указывает указатель

		//stop

	// *******************************************************


			//Задание 1в. И указатель, и указываемое значение
			//являются константами. 
		//int x = 10;
		//int y = 20;
		//const int* const ptr = &x;    // константный указатель на константноеn значение
		//y = *ptr;					    // получили значение по адресу
		////*ptr = 30					// ошибка: модифицировать значение по адресу запрещено
		//// ptr = &y;				    //ошибка: модифицировать адрес запрещено

		//stop

	// *******************************************************


			//Задание 1г. Указатель на переменную, объявленную с
			//ключевым словом const. 
		//const int nN = 1;

		////Объявите указатель и проинициализируйте его выражением - &nN	
		//const int* ptr = &nN;

		//stop


	//*******************************************************
		//Задание 1д. const  и void-указатель. 
	{
		//1) Что нужно сделать для того, чтобы следующее закомментированное выражение
		//стало корректным?
		//const int n = 1;
		//const void* pn = &n;    // *static_cast<const int*>(n)

		////2) как получить значение посредством  void* ?
		//int* y = static_cast<int*>(pn);      // приведение типов
		//int value = *y;						 // получение значения		

	}
	//*******************************************************

		//Задание 1е. Объявите указатель на тип char и проинициализируйте
		//его адресом строкового литерала. Присвойте переменной типа char значение
		//любого элемента строки.
		//Проверьте - возможно ли присвоить какое-либо значение по адресу,
		//задаваемому указателем?
		//const char* ptr;
		//ptr = "abcd";
		//char temp = *ptr;                // 'a' - указатель типа char обратится только к первому символу, 1 байт.
		//temp = *(ptr + 1);
		//temp = *(ptr + 2);
		//temp = *(ptr + 3);
		//temp = *(ptr + 4);
		//temp = *(ptr + 5);  // 		temp	0 '\0'	char
		////*ptr = 'new';       //невозможно присваивать значение константной переменной

		//stop
	//
	// //*******************************************************
		//Задание 2. Явное преобразование указателя. 
		//Иногда возникает необходимость одни и те же данные интерпретировать по-разному,

		//например, целое можно представить как совокупность четырех
		//байтов и работать с каждым байтом по отдельности. Для этого
		//нужно иметь возможность "указывать" как на целое, так и на байт. 

		//Следовательно, возникает необходимость явного преобразования указателя. 

		//Подсказка: для правильной интерпретации этого задания воспользуйтесь
		//возможностями отладчика представлять данные в интересующем
		//Вас виде (в данном случае - в шестнадцатеричном) - для
		//этого используйте правую клавишу мыши,находясь в окне

		//переменных и изменяйте пункт - Hexadecimal display !!!!!!!!!!!!!!!!!
	{

		unsigned int nObject5 = 0x55667788;
		unsigned int* pnObject5 = &nObject5;

		//Раскомментировав следующую строчку кода, обратите внимание на сообщение компилятора 
		//- он не считает преобразование "легальным" (безопасным)

		unsigned char* pucObject5;

		//	pucObject5=static_cast<unsigned char*>(pnObject5);	//(1)

		pucObject5 = reinterpret_cast<unsigned char*>(pnObject5);	//а такое
					//преобразование - целиком на совести программиста.
					//Его можно применять, только четко представляя себе
					//результат преобразования (2)

		//Откомментируйте (!) следующие строчки следующим образом:
		// сс=..., 	pucObject5 - изменился? 	*pucObject5=...

		char cc = *(pucObject5++);	// сс = 0x88,  pucObject5=0x00f3f779 - инкрементируется 

		cc = (*pucObject5)++;		// сс = 0x77 - инкремент содержимого по адресу,  pucObject5=0x00f3f779 - неизменен

		cc = ++ * (pucObject5);		// сс = 0x79   инкрементируется (0х78+1) и присваивается сс, pucObject5=0x00f3f779 - неизменен

		cc = *(++pucObject5);		// pucObject5=0x00f3f77a - инкрементируется и присваивается сс = 0x66 
		stop
	}
	///////////////////////////////////////////////////////////////
	//			Встроенные массивы                               
	///////////////////////////////////////////////////////////////

		//Задание 3. 
		//Имеется одномерный встроенный массив, проинициализированный при объявлении 
		//Отсортируйте массив по возрастанию значений. 
		//Используйте "пузырьковую" сортировку  
		// Правильность решения проверьте с помощью отладчика

#if 1
	{
		int ar[] = { 5, 4, 7,  8, 1, 2, 6, 0, 10, 12, 77, 11,
					  6, 8, 33, 21, 1, 2, 3, 4 };
		int size_ar = sizeof(ar) / sizeof(int);
		int end_ar = size_ar - 1;
		for (int i = 0; i < end_ar; i++) {
			for (int j = 0; j < (end_ar - i); j++) {
				if (ar[j] > ar[j + 1]) {
					int temp = ar[j];
					ar[j] = ar[j + 1];
					ar[j + 1] = temp;
				}
			}
		}
//		printArray(ar, size_ar);
	}
#endif

	// *******************************************************
		//Задание 4  
		//в)Инициализация массива строковыми литералами:
		//Объявите одномерный массив УКАЗАТЕЛЕЙ и проинициализируйте его СТРОКОВЫМИ литералами . 
		//Выведите  массив на печать.
	{
		const char* ptrs[] = { "Hello", "New", "World" };
		for (int i = 0; i < (sizeof(ptrs) / sizeof(*ptrs)); i++) {   //  *ptrs - 4 ,байта
//			std::cout << ptrs[i] << std::endl;
		}
	}
	// *******************************************************
		//Задание 5. 
		//a) Объявите одномерный неинициализированный массив ( размером N)
		//Задайте значения элементов с помощью генератора случайных чисел.

		//Подсказка 1: для генерации случайных чисел используйте функцию
		//стандартной библиотеки - rand() (<cstdlib>)
		// int tmp= rand(); // получим случайное значение в диапазоне от 0 до RAND_MAX
			//значение RAND_MAX задано в файле <stdlib.h>  и равно  0x7fff

		//если Вам требуется задать иные границы диапазона при генерации случайного числа, 
		//то это можно сделать так:
		//v1 = rand() % 100;         // v1 в диапазоне 0 - 99
		//v2 = rand() % 100 + 1;     // v2 в диапазоне 1 - 100
		//v3 = rand() % 30 + 1985;   // v3 в диапазоне 1985-2014 

		//Подсказка 2: На самом деле те значения, которые создаются генератором случайных
		//чисел являются "псевдослучайными", то есть при двух последовательных запусках
		//приложения Вы получаете две одинаковые последовательности значений.
		//Для того чтобы генерируемые "случайные" значения были разными при каждом 
		//запуске приложения используйте функции стандартной библиотеки srand() (<cstdlib>)
		//и time() (<ctime>).
		//Функция srand() осуществляет "привязку" начала генерации к указанному в качестве параметра значению.
		//Функция time() задает эту точку отсчета, считывая текущее время
		//srand( time( 0 ) );
	//(Подсказки в файле Алгоритмы для лабораторной работы_4. pdf)

#if 0
		{
			const int N = 10;
			int arr[N];
			srand(time(0));
			for (int i = 0; i < N; i++) {
				arr[i] = rand() % 100 + 1;
			}

			//б) Выведите массив на печать
			std::cout << "Create the array:" << std::endl;
			printArray(arr, N);

			//в)Отсортируйте массив по убыванию значений.
			//Используйте сортировку "выбором"

			int size_arr = N;
			int end_arr = size_arr - 1;

			for (int i = 0; i < end_arr; i++) {
				int index_big = i;
				for (int y = i + 1; y < size_arr; y++) {
					if (arr[y] > arr[index_big]) {
						index_big = y;
					}
				}
				if (index_big != i) {
					int temp = arr[i];
					arr[i] = arr[index_big];
					arr[index_big] = temp;
				}
			}
			std::cout << "Sorted the array:" << std::endl;
			printArray(arr, size_arr);
		}
#endif
	// 

// *******************************************************

	//Задание 6. 
	//Объявите встроенный одномерный массив, состоящий из N элементов целого типа. 
	//Напишите фрагмент кода, который вводит целые числа с помощью
	//потока ввода в объявленный Вами массив, каждый раз ( на каждой итерации!)
	//упорядочивая полученное значение по возрастанию.
	//Для проверки выводите массив на консоль на каждой итерации`

#if 0

	const int N = 10;
	int arr[N] = {0};
	int size_arr = N;
	int end_arr = size_arr - 1;

	int k = size_arr;
	while (k > 0) {
		printArray(arr, size_arr - k);
		int el;
		int currElement = size_arr - k;
		std::cout << "Add an element to the array:" << std::endl;
		std::cin >> el;
		arr[size_arr - k] = el;

		for (int i = 0; i < size_arr; i++) {

			int biggest = i;
			for (int y = i + 1; y <= currElement; y++) {
				if (arr[y] < arr[biggest]) {
					biggest = y;
				}
			}
			if (biggest != i) {
				int temp = arr[i];
				arr[i] = arr[biggest];
				arr[biggest] = temp;
			}
		}
		k--;
	}
	printArray(arr, size_arr);

#endif

// *******************************************************
	//Задание 7. 

	//Простой поиск.
	//Модифицируйте предыдущее задание следующим образом:
	//очередное введенное значение помещается в массив только при условии, 
	//что там еще такого нет (то есть дубли игнорируются)
#if 0
	{
		const int N = 10;
		int arr[N] = { 0 };
		int size_arr = N;
		int end_arr = size_arr - 1;

		int k = size_arr;
		while (k > 0) {
			printArray(arr, size_arr - k);
			int el;
			int currElement = size_arr - k;
			std::cout << "Add an element to the array:" << std::endl;
			std::cin >> el;

			if (checkUnique(el, arr, size_arr)) {
				arr[size_arr - k] = el;
				for (int i = 0; i < size_arr; i++) {
					int biggest = i;
					for (int y = i + 1; y <= currElement; y++) {
						if (arr[y] < arr[biggest]) {
							biggest = y;
						}
					}
					if (biggest != i) {
						int temp = arr[i];
						arr[i] = arr[biggest];
						arr[biggest] = temp;
					}
				}
				k--;
			}
			else {
				std::cout << "Wrong input! Duplicates are not allowed. \n" << std::endl;
			}
		}
	}
#endif

// *******************************************************
	//Задание 8
	//Объявите одномерный встроенный массив элементов типа char.
	//Сформируйте значения элементов массива с помощью генератора случайных 
	//чисел таким образом, чтобы в массиве были только символы '*' и '_'  

	//"сдвиньте звездочки" в начало массива, например:
	//было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
	//стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
	//и распечатайте массив 
//(Подсказки в файле Алгоритмы для лабораторной работы_4. pdf)

#if 0
	{
		const int size_arr = 10;
		char arr[size_arr] = {};
		char one = '*';
		char empty = '_';
		srand(time(0));
		for (int i = 0; i < size_arr; i++) {
			i[arr] = (rand() % 2 == 0) ? one : empty;
		}
		std::cout << "The array is generated:" << std::endl;
		printArray(arr, size_arr);

		int counter = 0;
		for (int i = 0; i < size_arr; i++) {
			if (i[arr] == one) {
				i[arr] = '_';
				counter[arr] = one;
				counter++;
			}
		}
		std::cout << "The array is transformed:" << std::endl;
		printArray(arr, size_arr);
	}

#endif
// *******************************************************
	//Задание 9
	//объявите одномерный встроенный массив  из N элементов и проинициализируйте его.
	//а) сдвиньте все элементы массива вправо на 1 позицию
#if 0
	{
		const int size_arr = 7;
		const int end_arr = size_arr - 1;
		int arr1[] = { 5, 7, 9, 14, 8, 16, 2 };
		for (int i = end_arr; i > 0; i--) {
			arr1[i] = arr1[i - 1];
		}
		std::cout << "a) Array shift right:" << std::endl;
		printArray(arr1, size_arr);

		std::cout << std::endl;
	}

	//б) (Циклическая перестановка). Сдвиньте все элементы массива вправо на 1 позицию , 
	//но последний элемент не должен быть утерян. Его следут переместить в начало.
	//например,  { 5, 2, 11, 4, 23, 9 } ->  {9, 5, 2, 11, 4, 23 }

	{
		const int size_arr = 6;
		const int end_arr = size_arr - 1;
		int arr2[] = { 5, 2, 11, 4, 23, 9 };
		int temp = arr2[end_arr];
		for (int i = end_arr; i > 0; i--) {	
			arr2[i] = arr2[i - 1];
		}
		arr2[0] = temp;
		std::cout << "b) Cyclic permutation: \n" << " 5 2 11 4 23 9 -> ";
		printArray(arr2, size_arr);
	}
#endif

	//в)(Кольцевой буфер) выведите массив на печать, циклически "сдвинув" элементы вправо на 1 позицию.
	//При решении задачи не следует перемещать элементы массива, а надо использовать кольцевой буфер.
	// Одномерный массив можно "свернуть" в кольцо и считать, что за последним элементом следует начальный и
	// потом установить "новое" начало массива.
#if 0
	{
		const int size_arr = 6;
		const int end_arr = size_arr - 1;
		int arr3[] = { 5, 2, 11, 4, 23, 9 };

		int begin;
		std::cout << "Enter the begin index(0 - 5): " << std::endl;
		std::cin >> begin;
		for (int i = begin; i < size_arr + begin; i++) {
			(i >= size_arr) ? (std::cout << arr3[i - size_arr]) : (std::cout << arr3[i]);
			std::cout << ' ';
		}
	}
#endif

// *****************************************************************************************************************
	//Задание 10 (*)
	//алгоритм "тасования колоды"
	//объявите одномерный встроенный массив  из N элементов и 
	// заполните  его неповторяющимися числами из заданного отрезка 
	//натурального ряда, расположенными в случайном порядке
//(Подсказки в файле Алгоритмы для лабораторной работы_4.pdf)
//Алгоритм:
//Массив  A [N] инициализируется последовательными значениями из отрезка, например [0,N-1]
//index=N-1, где index- максимальное значение индекса.

//В цикле по index выполняется перемешивание значений:
//	1. Генерируется случайное число  R из отрезка [0, index]
//	2. Выполняется обмен значений A[index]  и  A[R]
//	3. index=index -1
//	4. Если index==0, то конец
//	5. Переход к шагу 1    

	//Для того, чтобы выполнять это задание было интереснее, можно воспользоваться следующим массивом
	// массив текстовых эквивалентов  достоинства карт

#if 1
	const char* cards[] = { " 2\5", " 3\5", " 4\5", " 5\5", " 6\5", " 7\5", " 8\5", " 9\5", "10\5", " J\5", " Q\5", " K\5", " A\5",
		" 2\4", " 3\4", " 4\4", " 5\4", " 6\4", " 7\4", " 8\4", " 9\4", "10\4", " J\4", " Q\4", " K\4", " A\4",
		" 2\3", " 3\3", " 4\3", " 5\3", " 6\3", " 7\3", " 8\3", " 9\3", "10\3", " J\3", " Q\3", " K\3", " A\3",
		" 2\6", " 3\6", " 4\6", " 5\6", " 6\6", " 7\6", " 8\6", " 9\6", "10\6", " J\6", " Q\6", " K\6", " A\6",
	};

	int size_deck = sizeof(cards) / sizeof(*cards);
	
	std::cout << "The deck:" << std::endl;
	for (int i = 0; i < size_deck; i++) {
		std::cout << cards[i];
	}
	std::cout << std::endl;

	int end_arr = size_deck - 1;
	const char *temp;
	for (int i = end_arr; i > 0; i--) {
		srand(time(0));
		int curr_index = rand() % (i + 1);
		temp = cards[i];
		cards[i] = cards[curr_index];
		cards[curr_index] = temp;
	}

	std::cout << "Sorted the deck:" << std::endl;
	for (int i = 0; i < size_deck; i++) {
		std::cout << cards[i];
	}
	std::cout << std::endl;
#endif

//*********************   Дополнительное задание   ****************************************************
//Задание 11 (*)  
// Выполните задания 3 и 4 по курсовой работе 
// описание заданий находится в файлах "Задание (игра Змейка)_3 (одномерные массивы)_3.docx" и 
// "Задание (игра Змейка)_4 (+еда)_3.docs"
// Каждое задание выполняется в отдельном проекте
// Рекомендация:
// Все проекты (project), связанные с курсовой работой имеет смысл помещать в одно решение (solution)
//*****************************************************************************************************

}
