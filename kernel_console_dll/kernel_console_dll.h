// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 KERNEL_CONSOLE_DLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// KERNEL_CONSOLE_DLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef KERNEL_CONSOLE_DLL_EXPORTS
#define KERNEL_CONSOLE_DLL_API __declspec(dllexport)
#else
#define KERNEL_CONSOLE_DLL_API __declspec(dllimport)
#endif

// 此类是从 kernel_console_dll.dll 导出的
class KERNEL_CONSOLE_DLL_API Ckernel_console_dll {
public:
	Ckernel_console_dll(void);
	// TODO:  在此添加您的方法。
};

extern KERNEL_CONSOLE_DLL_API int nkernel_console_dll;

KERNEL_CONSOLE_DLL_API int fnkernel_console_dll(void);
