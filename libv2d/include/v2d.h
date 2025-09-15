#ifndef __V2D_H
#define __V2D_H

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

#include <stdbool.h>
#include <stddef.h>

#include "v2d_enums.h"
#include "v2d_structs.h"
#include "v2d_types.h"

V2D_DECLSPEC extern const V2D_Const V2D;

V2D_DECLSPEC V2D_AppConfig V2D_CALL V2D_CreateDefaultConfig();

V2D_DECLSPEC int V2D_CALL V2D_Run(V2D_AppConfig *config, void *state);

V2D_DECLSPEC void V2D_CALL V2D_Quit(V2D_AppContext *app, int return_code);

V2D_DECLSPEC void V2D_CALL V2D_FillRectSolidColor(V2D_RenderContext *ctx, V2D_Rect rect, V2D_Color color);

#endif