#pragma once
#pragma once
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

	// Ёкспортируемые функции дл€ работы с классом ArrayProcessor
	void* __stdcall createArrayProcessor(const int* arr, int size);
	void __stdcall destroyArrayProcessor(void* instance);

	void __stdcall sortArray(void* instance, int* sortedArr, int size);
	int __stdcall findElement(void* instance, int value);
	double __stdcall calculateAverage(void* instance);

#ifdef __cplusplus
}
#endif
