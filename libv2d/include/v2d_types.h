#include "SDL3/SDL_events.h"

#ifndef __V2D_TYPES_H
#define __V2D_TYPES_H

/* Common */

typedef struct V2D_Point V2D_Point;

typedef struct V2D_Color V2D_Color;

typedef struct V2D_Extent V2D_Extent;

typedef struct V2D_Rect V2D_Rect;

// shape
typedef union V2D_Shape V2D_Shape;
typedef struct V2D_Rectangle V2D_Rectangle;
typedef struct V2D_RoundedRectangle V2D_RoundedRectangle;
typedef struct V2D_Ellipse V2D_Ellipse;
typedef struct V2D_Polygon V2D_Polygon;

// brush
typedef union V2D_Brush V2D_Brush;
typedef struct V2D_SolidBrush V2D_SolidBrush;
// typedef struct V2D_LinearGradientFillBrush V2D_LinearGradientFillBrush;

typedef union V2D_Drawable V2D_Drawable;

/* Application */
typedef struct V2D_Const V2D_Const;

typedef struct V2D_ConstColors V2D_ConstColors;

typedef struct V2D_AppContext V2D_AppContext;

typedef struct V2D_RenderContext V2D_RenderContext;

typedef struct V2D_AppConfig V2D_AppConfig;

typedef void (*V2D_LoadFunc)(void *state, V2D_AppContext *app_ctx);

typedef void (*V2D_UpdateFunc)(void *state, V2D_AppContext *app_ctx, float dt);

typedef void (*V2D_RenderFunc)(void *state, V2D_AppContext *app_ctx, V2D_RenderContext *render_ctx);

typedef void (*V2D_EventFunc)(void *state, V2D_AppContext *app_ctx, SDL_Event *event);

typedef void (*V2D_UnloadFunc)(void *state, V2D_AppContext *app_ctx);

#endif