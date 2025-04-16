import time
import random
import copy
from enum import Enum


class SortStats:
    def __init__(self):
        self.comparisons = 0
        self.swaps = 0
        self.iterations = 0
        self.time = 0.0


class SearchStats:
    def __init__(self):
        self.comparisons = 0
        self.time = 0.0


class ArrayType(Enum):
    RANDOM = 0
    SORTED = 1
    REVERSED = 2
    PARTIAL_25 = 3
    PARTIAL_50 = 4
    PARTIAL_75 = 5


def insertion_sort(arr):
    stats = SortStats()
    start_time = time.perf_counter()

    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        stats.iterations += 1
        comparisons_done = False

        while j >= 0:
            stats.comparisons += 1
            comparisons_done = True
            if arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
                stats.swaps += 1
                stats.iterations += 1
            else:
                break
        if not comparisons_done:
            stats.comparisons += 1

        arr[j + 1] = key

    stats.time = (time.perf_counter() - start_time) * 1000
    return stats


def selection_sort(arr):
    stats = SortStats()
    start_time = time.perf_counter()

    n = len(arr)
    for i in range(n - 1):
        min_idx = i
        stats.iterations += 1
        for j in range(i + 1, n):
            stats.comparisons += 1
            stats.iterations += 1
            if arr[j] < arr[min_idx]:
                min_idx = j
        if min_idx != i:
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
            stats.swaps += 1

    stats.time = (time.perf_counter() - start_time) * 1000
    return stats


def bubble_sort(arr):
    stats = SortStats()
    start_time = time.perf_counter()

    n = len(arr)
    swapped = False
    for i in range(n - 1):
        swapped = False
        stats.iterations += 1
        for j in range(n - i - 1):
            stats.comparisons += 1
            stats.iterations += 1
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                stats.swaps += 1
                swapped = True
        if not swapped:
            break

    stats.time = (time.perf_counter() - start_time) * 1000
    return stats


def partition(arr, low, high, stats):
    mid = (low + high) // 2
    pivot_val = max(min(arr[low], arr[mid]), min(max(arr[low], arr[mid]), arr[high]))
    pivot_idx = low if arr[low] == pivot_val else mid if arr[mid] == pivot_val else high

    arr[pivot_idx], arr[high] = arr[high], arr[pivot_idx]
    pivot = arr[high]

    i = low - 1
    for j in range(low, high):
        stats.comparisons += 1
        stats.iterations += 1
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
            stats.swaps += 1
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    stats.swaps += 1
    return i + 1


def quick_sort(arr, low, high, stats):
    if low < high:
        pi = partition(arr, low, high, stats)
        quick_sort(arr, low, pi - 1, stats)
        quick_sort(arr, pi + 1, high, stats)


def quick_sort_wrapper(arr):
    stats = SortStats()
    start_time = time.perf_counter()

    quick_sort(arr, 0, len(arr) - 1, stats)

    stats.time = (time.perf_counter() - start_time) * 1000
    return stats


def generate_base_array(n):
    return [random.randint(0, 9999) for _ in range(n)]


def prepare_array(base_array, array_type):
    arr = copy.deepcopy(base_array)
    n = len(arr)

    if array_type == ArrayType.SORTED:
        arr.sort()
    elif array_type == ArrayType.REVERSED:
        arr.sort()
        arr.reverse()
    elif array_type == ArrayType.PARTIAL_25:
        part = n // 4
        arr[:part] = sorted(arr[:part])
    elif array_type == ArrayType.PARTIAL_50:
        part = n // 2
        arr[:part] = sorted(arr[:part])
    elif array_type == ArrayType.PARTIAL_75:
        part = int(n * 0.75)
        arr[:part] = sorted(arr[:part])

    return arr


def linear_search(arr, target):
    stats = SearchStats()
    start_time = time.perf_counter()
    found = False
    for i in range(len(arr)):
        stats.comparisons += 1
        if arr[i] == target:
            found = True
            break
    if not found:
        raise ValueError(f"Элемент {target} не найден при линейном поиске")
    stats.time = (time.perf_counter() - start_time) * 1000
    return stats


def linear_search_with_sentinel(arr, target):
    stats = SearchStats()
    start_time = time.perf_counter()
    n = len(arr)
    arr_copy = arr.copy()
    arr_copy.append(target)
    i = 0
    while True:
        stats.comparisons += 1
        if arr_copy[i] == target:
            break
        i += 1

    # Проверяем, нашли ли реальный элемент или барьер
    if i == n:
        raise ValueError(f"Элемент {target} не найден при поиске с барьером")

    stats.time = (time.perf_counter() - start_time) * 1000
    return stats


def binary_search(sorted_arr, target):
    stats = SearchStats()
    start_time = time.perf_counter()
    low = 0
    high = len(sorted_arr) - 1
    found = False
    while low <= high:
        mid = (low + high) // 2
        stats.comparisons += 1
        if sorted_arr[mid] == target:
            found = True
            break
        elif sorted_arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
        stats.comparisons += 1

    if not found:
        raise ValueError(f"Элемент {target} не найден при бинарном поиске")

    stats.time = (time.perf_counter() - start_time) * 1000
    return stats


def print_stats_table(method_name, stats):
    print(f"{method_name:<20}{stats.comparisons:<15}{stats.swaps:<10}"
          f"{stats.time:<15.2f}{stats.iterations:<15}")


def print_search_stats(method_name, stats):
    print(f"{method_name:<25}{stats.comparisons:<15}{stats.time:<15.2f}")


def run_single_test(size, array_type, base_array):
    try:
        original_arr = prepare_array(base_array, array_type)

        # Копии для сортировок
        arr_insertion = copy.deepcopy(original_arr)
        arr_selection = copy.deepcopy(original_arr)
        arr_bubble = copy.deepcopy(original_arr)
        arr_quick = copy.deepcopy(original_arr)

        print("\nТип массива: ", end="")
        if array_type == ArrayType.RANDOM:
            print("Случайный", end="")
        elif array_type == ArrayType.SORTED:
            print("Отсортированный", end="")
        elif array_type == ArrayType.REVERSED:
            print("Обратный порядок", end="")
        elif array_type == ArrayType.PARTIAL_25:
            print("Частично отсортированный (25%)", end="")
        elif array_type == ArrayType.PARTIAL_50:
            print("Частично отсортированный (50%)", end="")
        elif array_type == ArrayType.PARTIAL_75:
            print("Частично отсортированный (75%)", end="")
        print(f" (Размер: {size})")

        # Тестирование сортировок
        print("-" * 75)
        print(f"{'Метод':<20}{'Сравнения':<15}{'Обмены':<10}{'Время (мс)':<15}{'Итерации':<15}")

        insertion_stats = insertion_sort(arr_insertion)
        print_stats_table("Сортировка вставками", insertion_stats)

        selection_stats = selection_sort(arr_selection)
        print_stats_table("Сортировка выбором", selection_stats)

        bubble_stats = bubble_sort(arr_bubble)
        print_stats_table("Пузырьковая", bubble_stats)

        quick_stats = quick_sort_wrapper(arr_quick)
        print_stats_table("Быстрая сортировка", quick_stats)

        # Тестирование поиска
        target = random.choice(original_arr)
        sorted_for_binary = sorted(original_arr)

        print("\nРезультаты поиска:")
        print(f"{'Метод':<25}{'Сравнения':<15}{'Время (мс)':<15}")

        try:
            linear_stats = linear_search(original_arr, target)
            print_search_stats("Линейный без барьера", linear_stats)
        except ValueError as e:
            print(f"Ошибка поиска: {str(e)}")

        try:
            sentinel_stats = linear_search_with_sentinel(original_arr, target)
            print_search_stats("Линейный с барьером", sentinel_stats)
        except ValueError as e:
            print(f"Ошибка поиска: {str(e)}")

        try:
            binary_stats = binary_search(sorted_for_binary, target)
            print_search_stats("Бинарный поиск", binary_stats)
        except ValueError as e:
            print(f"Ошибка поиска: {str(e)}")

    except Exception as e:
        print(f"Ошибка при тестировании для размера {size}: {str(e)}")


def run_tests():
    sizes = [20, 500, 1000, 5000, 10000]
    array_types = [ArrayType.RANDOM, ArrayType.SORTED, ArrayType.REVERSED,
                   ArrayType.PARTIAL_25, ArrayType.PARTIAL_50, ArrayType.PARTIAL_75]

    print("\n=== Запуск тестов производительности ===")
    for size in sizes:
        base_array = generate_base_array(size)
        for array_type in array_types:
            run_single_test(size, array_type, base_array)


def partition_descending_abs(arr, low, high, stats):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        stats.comparisons += 1
        if abs(arr[j]) >= abs(pivot):
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
            stats.swaps += 1
        stats.iterations += 1
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    stats.swaps += 1
    return i + 1


def quick_sort_descending_abs(arr, low, high, stats):
    if low < high:
        pi = partition_descending_abs(arr, low, high, stats)
        quick_sort_descending_abs(arr, low, pi - 1, stats)
        quick_sort_descending_abs(arr, pi + 1, high, stats)


def custom_quick_sort_task():
    size = 15
    arr = [random.randint(-100, 100) for _ in range(size)]
    stats = SortStats()

    print("\nСгенерированный массив из 15 случайных чисел (-100..100):")
    print(' '.join(map(str, arr)))

    quick_sort_descending_abs(arr, 0, size - 1, stats)

    print("\nРезультат сортировки (по убыванию модулей):")
    print(' '.join(map(str, arr)))


def main():
    random.seed(time.time())

    choice = input("1. Запустить тесты производительности\n"
                   "2. Отсортировать 15 элементов\n"
                   "Выберите действие: ")

    if choice == '1':
        run_tests()
    elif choice == '2':
        custom_quick_sort_task()
    else:
        print("Некорректный выбор!")


if __name__ == "__main__":
    main()