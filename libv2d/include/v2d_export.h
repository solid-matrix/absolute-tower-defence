#ifdef _WIN32
#ifdef DLL_EXPORT
#define V2D_DECLSPEC __declspec(dllexport)
#else

#define V2D_DECLSPEC __declspec(dllimport)
#endif

#define V2D_CALL __cdecl

#else
#define V2D_DECLSPEC
#define V2D_CALL
#endif