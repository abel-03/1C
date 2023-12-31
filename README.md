Письменный этап отбора на кафедру 1С

ФИО: Мирумян Абел Валерьевич

Номер задачи: 2

Решение задачи "Заражение городов эпидемией"
Это решение представляет собой программу на C++, решающую задачу по заражению городов эпидемией. Программа принимает на вход карту городов в виде графа и находит минимальное количество городов, которые нужно изначально заразить эпидемией, чтобы в итоге все города были заражены.

Входные данные
Входные данные представляют собой карту городов, заданную списком из M рёбер графа. Каждое ребро представлено парой целых чисел u и v, где u и v - номера городов, соединённых ребром.

Основные функции
CrossingMakeBlack
Эта функция делает города черными, то есть помечает их как зараженные эпидемией. Город считается зараженным, если он сам заражен или его два соседа заражены.

Crossing
Эта функция считает количество пересечений (соседей) между двумя городами в графе.

Главная функция: main
Основная функция, где осуществляется ввод и обработка данных. Алгоритм пошагово выбирает города для заражения эпидемией, учитывая условия задачи, и формирует ответ.

Работа программы
Программа находит минимальное количество городов, которые нужно заразить изначально эпидемией, чтобы все города были заражены. После этого выводит номера этих городов.

Для компиляции и запуска программы используйте стандартный процесс для языка C++.

Описание алгоритма
1. Инициализация данных и ввод графа:

Сначала инициализируются необходимые структуры данных, такие как unordered_map для хранения графа, unordered_set для хранения вершин и их состояний, и deque для обработки вершин по алгоритму BFS.
Происходит ввод количества рёбер (M) и самих рёбер (u, v), формируя граф.

2. Алгоритм для заражения городов:

Используется итеративный процесс, пока не будут заражены все города:

a. Выбор начальной зараженной вершины:

При первой итерации выбираются две вершины (x, y), которые не были заражены ранее и имеют максимальное количество соседей в графе.
Эти вершины помечаются как зараженные (черные) и добавляются в очередь для обработки.

b. Обработка вершин из очереди:

Для каждой вершины из очереди:
Проверяется каждый сосед и, если он ещё не заражён, делается черным.
Затем выбирается сосед с максимальным количеством пересечений с текущей вершиной и, если он ещё не заражён, он тоже делается черным.
Если не удалось найти соседа для заражения, текущая вершина помечается как неподвижная, то есть больше не рассматривается для заражения, и процесс переходит к следующей вершине в очереди для обработки.
В конце если остались вершины незараженные, то их заражаем сами.

3.  Вывод результата:

После завершения обработки всех вершин выводится количество зараженных городов и их номера.
Алгоритм стремится минимизировать количество зараженных городов, начиная с выбора оптимальных вершин для начального заражения и затем эффективно распространяя эпидемию по городам.





