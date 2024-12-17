#include <iostream>
#include <windows.h>

#ifdef UNICODE
#undef UNICODE
#endif

// ���� � DLL � �������������� ��������
#define LIB_PATH TEXT("array_processor.dll")
#define CREATE_FUNC_NAME "createArrayProcessor"
#define DESTROY_FUNC_NAME "destroyArrayProcessor"
#define SORT_FUNC_NAME "sortArray"
#define FIND_FUNC_NAME "findElement"
#define AVERAGE_FUNC_NAME "calculateAverage"

typedef void* (__stdcall* CreateProcessor)(const int*, int);
typedef void(__stdcall* DestroyProcessor)(void*);
typedef void(__stdcall* SortArrayFunc)(void*, int*, int);
typedef int(__stdcall* FindElementFunc)(void*, int);
typedef double(__stdcall* CalculateAverageFunc)(void*);

int main() {
    // ��������� ����������
    HMODULE libModule = LoadLibrary(LIB_PATH);
    if (!libModule) {
        std::cerr << "�� ������� ��������� ����������." << std::endl;
        return 1;
    }

    // ��������� �������
    CreateProcessor createProcessor = (CreateProcessor)GetProcAddress(libModule, CREATE_FUNC_NAME);
    DestroyProcessor destroyProcessor = (DestroyProcessor)GetProcAddress(libModule, DESTROY_FUNC_NAME);
    SortArrayFunc sortArrayFunc = (SortArrayFunc)GetProcAddress(libModule, SORT_FUNC_NAME);
    FindElementFunc findElementFunc = (FindElementFunc)GetProcAddress(libModule, FIND_FUNC_NAME);
    CalculateAverageFunc calculateAverageFunc = (CalculateAverageFunc)GetProcAddress(libModule, AVERAGE_FUNC_NAME);

    if (!createProcessor || !destroyProcessor || !sortArrayFunc || !findElementFunc || !calculateAverageFunc) {
        std::cerr << "�� ������� �������� ����� �������." << std::endl;
        FreeLibrary(libModule);
        return 1;
    }

    // �������� ������
    int arr[] = { 5, 2, 8, 1, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // ������ ��������� ArrayProcessor
    void* processor = createProcessor(arr, size);

    // ��������� ������
    int sortedArr[size];
    sortArrayFunc(processor, sortedArr, size);
    std::cout << "��������������� ������: ";
    for (int i = 0; i < size; ++i) {
        std::cout << sortedArr[i] << " ";
    }
    std::cout << std::endl;

    // ����� ��������
    int value = 8;
    int index = findElementFunc(processor, value);
    if (index != -1) {
        std::cout << "������� " << value << " ������ �� ������� " << index << "." << std::endl;
    }
    else {
        std::cout << "������� " << value << " �� ������." << std::endl;
    }

    // ���������� �������� ��������
    double avg = calculateAverageFunc(processor);
    std::cout << "������� ��������: " << avg << std::endl;

    // ���������� ������ � ����������� ����������
    destroyProcessor(processor);
    FreeLibrary(libModule);

    return 0;
}
