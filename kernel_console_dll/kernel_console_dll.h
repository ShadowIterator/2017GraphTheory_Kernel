// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� KERNEL_CONSOLE_DLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// KERNEL_CONSOLE_DLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef KERNEL_CONSOLE_DLL_EXPORTS
#define KERNEL_CONSOLE_DLL_API __declspec(dllexport)
#else
#define KERNEL_CONSOLE_DLL_API __declspec(dllimport)
#endif

// �����Ǵ� kernel_console_dll.dll ������
class KERNEL_CONSOLE_DLL_API Ckernel_console_dll {
public:
	Ckernel_console_dll(void);
	// TODO:  �ڴ�������ķ�����
};

extern KERNEL_CONSOLE_DLL_API int nkernel_console_dll;

KERNEL_CONSOLE_DLL_API int fnkernel_console_dll(void);
