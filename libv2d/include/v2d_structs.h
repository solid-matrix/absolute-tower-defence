#include "SDL3/SDL_gpu.h"
#include "v2d_enums.h"
#include "v2d_types.h"

#ifndef __V2D_STRUCTS_H
#define __V2D_STRUCTS_H

struct V2D_Point {
    float x;
    float y;
};

struct V2D_Color {
    float r;
    float g;
    float b;
    float a;
};

struct V2D_Extent {
    float width;
    float height;
};

struct V2D_Rect {
    float x;
    float y;
    float width;
    float height;
};

struct V2D_ConstColors {
    const V2D_Color TRANSPARENT;          // {0.0000f, 0.0000f, 0.0000f, 0.0000f}
    const V2D_Color BLACK;                // {0.0000f, 0.0000f, 0.0000f, 1.0000f}
    const V2D_Color SILVER;               // {0.7529f, 0.7529f, 0.7529f, 1.0000f}
    const V2D_Color GRAY;                 // {0.5020f, 0.5020f, 0.5020f, 1.0000f}
    const V2D_Color WHITE;                // {1.0000f, 1.0000f, 1.0000f, 1.0000f}
    const V2D_Color MAROON;               // {0.5020f, 0.0000f, 0.0000f, 1.0000f}
    const V2D_Color RED;                  // {1.0000f, 0.0000f, 0.0000f, 1.0000f}
    const V2D_Color PURPLE;               // {0.5020f, 0.0000f, 0.5020f, 1.0000f}
    const V2D_Color FUCHSIA;              // {1.0000f, 0.0000f, 1.0000f, 1.0000f}
    const V2D_Color GREEN;                // {0.0000f, 0.5020f, 0.0000f, 1.0000f}
    const V2D_Color LIME;                 // {0.0000f, 1.0000f, 0.0000f, 1.0000f}
    const V2D_Color OLIVE;                // {0.5020f, 0.5020f, 0.0000f, 1.0000f}
    const V2D_Color YELLOW;               // {1.0000f, 1.0000f, 0.0000f, 1.0000f}
    const V2D_Color NAVY;                 // {0.0000f, 0.0000f, 0.5020f, 1.0000f}
    const V2D_Color BLUE;                 // {0.0000f, 0.0000f, 1.0000f, 1.0000f}
    const V2D_Color TEAL;                 // {0.0000f, 0.5020f, 0.5020f, 1.0000f}
    const V2D_Color AQUA;                 // {0.0000f, 1.0000f, 1.0000f, 1.0000f}
    const V2D_Color ALICEBLUE;            // {0.9412f, 0.9725f, 1.0000f, 1.0000f}
    const V2D_Color ANTIQUEWHITE;         // {0.9804f, 0.9216f, 0.8431f, 1.0000f}
    const V2D_Color AQUAMARINE;           // {0.4980f, 1.0000f, 0.8314f, 1.0000f}
    const V2D_Color AZURE;                // {0.9412f, 1.0000f, 1.0000f, 1.0000f}
    const V2D_Color BEIGE;                // {0.9608f, 0.9608f, 0.8627f, 1.0000f}
    const V2D_Color BISQUE;               // {1.0000f, 0.8941f, 0.7686f, 1.0000f}
    const V2D_Color BLANCHEDALMOND;       // {1.0000f, 0.9216f, 0.8039f, 1.0000f}
    const V2D_Color BLUEVIOLET;           // {0.5412f, 0.1686f, 0.8863f, 1.0000f}
    const V2D_Color BROWN;                // {0.6471f, 0.1647f, 0.1647f, 1.0000f}
    const V2D_Color BURLYWOOD;            // {0.8706f, 0.7216f, 0.5294f, 1.0000f}
    const V2D_Color CADETBLUE;            // {0.3725f, 0.6196f, 0.6275f, 1.0000f}
    const V2D_Color CHARTREUSE;           // {0.4980f, 1.0000f, 0.0000f, 1.0000f}
    const V2D_Color CHOCOLATE;            // {0.8235f, 0.4118f, 0.1176f, 1.0000f}
    const V2D_Color CORAL;                // {1.0000f, 0.4980f, 0.3137f, 1.0000f}
    const V2D_Color CORNFLOWERBLUE;       // {0.3922f, 0.5843f, 0.9294f, 1.0000f}
    const V2D_Color CORNSILK;             // {1.0000f, 0.9725f, 0.8627f, 1.0000f}
    const V2D_Color CRIMSON;              // {0.8627f, 0.0784f, 0.2353f, 1.0000f}
    const V2D_Color CYAN;                 // {0.0000f, 1.0000f, 1.0000f, 1.0000f}
    const V2D_Color DARKBLUE;             // {0.0000f, 0.0000f, 0.5451f, 1.0000f}
    const V2D_Color DARKCYAN;             // {0.0000f, 0.5451f, 0.5451f, 1.0000f}
    const V2D_Color DARKGOLDENROD;        // {0.7216f, 0.5255f, 0.0431f, 1.0000f}
    const V2D_Color DARKGRAY;             // {0.6627f, 0.6627f, 0.6627f, 1.0000f}
    const V2D_Color DARKGREEN;            // {0.0000f, 0.3922f, 0.0000f, 1.0000f}
    const V2D_Color DARKGREY;             // {0.6627f, 0.6627f, 0.6627f, 1.0000f}
    const V2D_Color DARKKHAKI;            // {0.7412f, 0.7176f, 0.4196f, 1.0000f}
    const V2D_Color DARKMAGENTA;          // {0.5451f, 0.0000f, 0.5451f, 1.0000f}
    const V2D_Color DARKOLIVEGREEN;       // {0.3333f, 0.4196f, 0.1843f, 1.0000f}
    const V2D_Color DARKORANGE;           // {1.0000f, 0.5490f, 0.0000f, 1.0000f}
    const V2D_Color DARKORCHID;           // {0.6000f, 0.1961f, 0.8000f, 1.0000f}
    const V2D_Color DARKRED;              // {0.5451f, 0.0000f, 0.0000f, 1.0000f}
    const V2D_Color DARKSALMON;           // {0.9137f, 0.5882f, 0.4784f, 1.0000f}
    const V2D_Color DARKSEAGREEN;         // {0.5608f, 0.7373f, 0.5608f, 1.0000f}
    const V2D_Color DARKSLATEBLUE;        // {0.2824f, 0.2392f, 0.5451f, 1.0000f}
    const V2D_Color DARKSLATEGRAY;        // {0.1843f, 0.3098f, 0.3098f, 1.0000f}
    const V2D_Color DARKSLATEGREY;        // {0.1843f, 0.3098f, 0.3098f, 1.0000f}
    const V2D_Color DARKTURQUOISE;        // {0.0000f, 0.8078f, 0.8196f, 1.0000f}
    const V2D_Color DARKVIOLET;           // {0.5804f, 0.0000f, 0.8275f, 1.0000f}
    const V2D_Color DEEPPINK;             // {1.0000f, 0.0784f, 0.5765f, 1.0000f}
    const V2D_Color DEEPSKYBLUE;          // {0.0000f, 0.7490f, 1.0000f, 1.0000f}
    const V2D_Color DIMGRAY;              // {0.4118f, 0.4118f, 0.4118f, 1.0000f}
    const V2D_Color DIMGREY;              // {0.4118f, 0.4118f, 0.4118f, 1.0000f}
    const V2D_Color DODGERBLUE;           // {0.1176f, 0.5647f, 1.0000f, 1.0000f}
    const V2D_Color FIREBRICK;            // {0.6980f, 0.1333f, 0.1333f, 1.0000f}
    const V2D_Color FLORALWHITE;          // {1.0000f, 0.9804f, 0.9412f, 1.0000f}
    const V2D_Color FORESTGREEN;          // {0.1333f, 0.5451f, 0.1333f, 1.0000f}
    const V2D_Color GAINSBORO;            // {0.8627f, 0.8627f, 0.8627f, 1.0000f}
    const V2D_Color GHOSTWHITE;           // {0.9725f, 0.9725f, 1.0000f, 1.0000f}
    const V2D_Color GOLD;                 // {1.0000f, 0.8431f, 0.0000f, 1.0000f}
    const V2D_Color GOLDENROD;            // {0.8549f, 0.6471f, 0.1255f, 1.0000f}
    const V2D_Color GREENYELLOW;          // {0.6784f, 1.0000f, 0.1843f, 1.0000f}
    const V2D_Color GREY;                 // {0.5020f, 0.5020f, 0.5020f, 1.0000f}
    const V2D_Color HONEYDEW;             // {0.9412f, 1.0000f, 0.9412f, 1.0000f}
    const V2D_Color HOTPINK;              // {1.0000f, 0.4118f, 0.7059f, 1.0000f}
    const V2D_Color INDIANRED;            // {0.8039f, 0.3608f, 0.3608f, 1.0000f}
    const V2D_Color INDIGO;               // {0.2941f, 0.0000f, 0.5098f, 1.0000f}
    const V2D_Color IVORY;                // {1.0000f, 1.0000f, 0.9412f, 1.0000f}
    const V2D_Color KHAKI;                // {0.9412f, 0.9020f, 0.5490f, 1.0000f}
    const V2D_Color LAVENDER;             // {0.9020f, 0.9020f, 0.9804f, 1.0000f}
    const V2D_Color LAVENDERBLUSH;        // {1.0000f, 0.9412f, 0.9608f, 1.0000f}
    const V2D_Color LAWNGREEN;            // {0.4863f, 0.9882f, 0.0000f, 1.0000f}
    const V2D_Color LEMONCHIFFON;         // {1.0000f, 0.9804f, 0.8039f, 1.0000f}
    const V2D_Color LIGHTBLUE;            // {0.6784f, 0.8471f, 0.9020f, 1.0000f}
    const V2D_Color LIGHTCORAL;           // {0.9412f, 0.5020f, 0.5020f, 1.0000f}
    const V2D_Color LIGHTCYAN;            // {0.8784f, 1.0000f, 1.0000f, 1.0000f}
    const V2D_Color LIGHTGOLDENRODYELLOW; // {0.9804f, 0.9804f, 0.8235f, 1.0000f}
    const V2D_Color LIGHTGRAY;            // {0.8275f, 0.8275f, 0.8275f, 1.0000f}
    const V2D_Color LIGHTGREEN;           // {0.5647f, 0.9333f, 0.5647f, 1.0000f}
    const V2D_Color LIGHTGREY;            // {0.8275f, 0.8275f, 0.8275f, 1.0000f}
    const V2D_Color LIGHTPINK;            // {1.0000f, 0.7137f, 0.7569f, 1.0000f}
    const V2D_Color LIGHTSALMON;          // {1.0000f, 0.6275f, 0.4784f, 1.0000f}
    const V2D_Color LIGHTSEAGREEN;        // {0.1255f, 0.6980f, 0.6667f, 1.0000f}
    const V2D_Color LIGHTSKYBLUE;         // {0.5294f, 0.8078f, 0.9804f, 1.0000f}
    const V2D_Color LIGHTSLATEGRAY;       // {0.4667f, 0.5333f, 0.6000f, 1.0000f}
    const V2D_Color LIGHTSLATEGREY;       // {0.4667f, 0.5333f, 0.6000f, 1.0000f}
    const V2D_Color LIGHTSTEELBLUE;       // {0.6902f, 0.7686f, 0.8706f, 1.0000f}
    const V2D_Color LIGHTYELLOW;          // {1.0000f, 1.0000f, 0.8784f, 1.0000f}
    const V2D_Color LIMEGREEN;            // {0.1961f, 0.8039f, 0.1961f, 1.0000f}
    const V2D_Color LINEN;                // {0.9804f, 0.9412f, 0.9020f, 1.0000f}
    const V2D_Color MAGENTA;              // {1.0000f, 0.0000f, 1.0000f, 1.0000f}
    const V2D_Color MEDIUMAQUAMARINE;     // {0.4000f, 0.8039f, 0.6667f, 1.0000f}
    const V2D_Color MEDIUMBLUE;           // {0.0000f, 0.0000f, 0.8039f, 1.0000f}
    const V2D_Color MEDIUMORCHID;         // {0.7294f, 0.3333f, 0.8275f, 1.0000f}
    const V2D_Color MEDIUMPURPLE;         // {0.5765f, 0.4392f, 0.8588f, 1.0000f}
    const V2D_Color MEDIUMSEAGREEN;       // {0.2353f, 0.7020f, 0.4431f, 1.0000f}
    const V2D_Color MEDIUMSLATEBLUE;      // {0.4824f, 0.4078f, 0.9333f, 1.0000f}
    const V2D_Color MEDIUMSPRINGGREEN;    // {0.0000f, 0.9804f, 0.6039f, 1.0000f}
    const V2D_Color MEDIUMTURQUOISE;      // {0.2824f, 0.8196f, 0.8000f, 1.0000f}
    const V2D_Color MEDIUMVIOLETRED;      // {0.7804f, 0.0824f, 0.5216f, 1.0000f}
    const V2D_Color MIDNIGHTBLUE;         // {0.0980f, 0.0980f, 0.4392f, 1.0000f}
    const V2D_Color MINTCREAM;            // {0.9608f, 1.0000f, 0.9804f, 1.0000f}
    const V2D_Color MISTYROSE;            // {1.0000f, 0.8941f, 0.8824f, 1.0000f}
    const V2D_Color MOCCASIN;             // {1.0000f, 0.8941f, 0.7098f, 1.0000f}
    const V2D_Color NAVAJOWHITE;          // {1.0000f, 0.8706f, 0.6784f, 1.0000f}
    const V2D_Color OLDLACE;              // {0.9922f, 0.9608f, 0.9020f, 1.0000f}
    const V2D_Color OLIVEDRAB;            // {0.4196f, 0.5569f, 0.1373f, 1.0000f}
    const V2D_Color ORANGE;               // {1.0000f, 0.6471f, 0.0000f, 1.0000f}
    const V2D_Color ORANGERED;            // {1.0000f, 0.2706f, 0.0000f, 1.0000f}
    const V2D_Color ORCHID;               // {0.8549f, 0.4392f, 0.8392f, 1.0000f}
    const V2D_Color PALEGOLDENROD;        // {0.9333f, 0.9098f, 0.6667f, 1.0000f}
    const V2D_Color PALEGREEN;            // {0.5961f, 0.9843f, 0.5961f, 1.0000f}
    const V2D_Color PALETURQUOISE;        // {0.6863f, 0.9333f, 0.9333f, 1.0000f}
    const V2D_Color PALEVIOLETRED;        // {0.8588f, 0.4392f, 0.5765f, 1.0000f}
    const V2D_Color PAPAYAWHIP;           // {1.0000f, 0.9373f, 0.8353f, 1.0000f}
    const V2D_Color PEACHPUFF;            // {1.0000f, 0.8549f, 0.7255f, 1.0000f}
    const V2D_Color PERU;                 // {0.8039f, 0.5216f, 0.2471f, 1.0000f}
    const V2D_Color PINK;                 // {1.0000f, 0.7529f, 0.7961f, 1.0000f}
    const V2D_Color PLUM;                 // {0.8667f, 0.6275f, 0.8667f, 1.0000f}
    const V2D_Color POWDERBLUE;           // {0.6902f, 0.8784f, 0.9020f, 1.0000f}
    const V2D_Color REBECCAPURPLE;        // {0.4000f, 0.2000f, 0.6000f, 1.0000f}
    const V2D_Color ROSYBROWN;            // {0.7373f, 0.5608f, 0.5608f, 1.0000f}
    const V2D_Color ROYALBLUE;            // {0.2549f, 0.4118f, 0.8824f, 1.0000f}
    const V2D_Color SADDLEBROWN;          // {0.5451f, 0.2706f, 0.0745f, 1.0000f}
    const V2D_Color SALMON;               // {0.9804f, 0.5020f, 0.4471f, 1.0000f}
    const V2D_Color SANDYBROWN;           // {0.9569f, 0.6431f, 0.3765f, 1.0000f}
    const V2D_Color SEAGREEN;             // {0.1804f, 0.5451f, 0.3412f, 1.0000f}
    const V2D_Color SEASHELL;             // {1.0000f, 0.9608f, 0.9333f, 1.0000f}
    const V2D_Color SIENNA;               // {0.6275f, 0.3216f, 0.1765f, 1.0000f}
    const V2D_Color SKYBLUE;              // {0.5294f, 0.8078f, 0.9216f, 1.0000f}
    const V2D_Color SLATEBLUE;            // {0.4157f, 0.3529f, 0.8039f, 1.0000f}
    const V2D_Color SLATEGRAY;            // {0.4392f, 0.5020f, 0.5647f, 1.0000f}
    const V2D_Color SLATEGREY;            // {0.4392f, 0.5020f, 0.5647f, 1.0000f}
    const V2D_Color SNOW;                 // {1.0000f, 0.9804f, 0.9804f, 1.0000f}
    const V2D_Color SPRINGGREEN;          // {0.0000f, 1.0000f, 0.4980f, 1.0000f}
    const V2D_Color STEELBLUE;            // {0.2745f, 0.5098f, 0.7059f, 1.0000f}
    const V2D_Color TAN;                  // {0.8235f, 0.7059f, 0.5490f, 1.0000f}
    const V2D_Color THISTLE;              // {0.8471f, 0.7490f, 0.8471f, 1.0000f}
    const V2D_Color TOMATO;               // {1.0000f, 0.3882f, 0.2784f, 1.0000f}
    const V2D_Color TURQUOISE;            // {0.2510f, 0.8784f, 0.8157f, 1.0000f}
    const V2D_Color VIOLET;               // {0.9333f, 0.5098f, 0.9333f, 1.0000f}
    const V2D_Color WHEAT;                // {0.9608f, 0.8706f, 0.7020f, 1.0000f}
    const V2D_Color WHITESMOKE;           // {0.9608f, 0.9608f, 0.9608f, 1.0000f}
    const V2D_Color YELLOWGREEN;          // {0.6039f, 0.8039f, 0.1961f, 1.0000f}
};

struct V2D_Const {
    const V2D_ConstColors COLORS;
};

struct V2D_AppConfig {

    V2D_LoadFunc onLoad;
    V2D_UpdateFunc onUpdate;
    V2D_RenderFunc onRender;
    V2D_EventFunc onEvent;
    V2D_UnloadFunc onUnload;

    // TODO console_enabled;
    bool debug;

    char *window_title;
    int window_width;
    int window_height;

    // TODO icon

    bool window_borderless;
    bool window_resiable;
    bool window_fullscreen;

    // TODO window_vsync;
};

struct V2D_AppContext {
    SDL_Window *window;
    SDL_GPUDevice *device;
    SDL_GPUGraphicsPipeline *default_graphics_pipeline;

    bool should_close;
    int return_code;

    float currentTime;
};

struct V2D_RenderContext {
    V2D_AppContext *app;
    SDL_GPUCommandBuffer *command_buffer;
    Uint32 width;
    Uint32 height;
    SDL_GPUTexture *swapchain_texture;
    SDL_GPURenderPass *render_pass;
    SDL_GPUGraphicsPipeline *graphics_pipeline;
};

struct V2D_Rectangle {
    V2D_ShapeType type;
    V2D_Point pos;
    V2D_Extent extent;
};

struct V2D_Ellipse {
    V2D_ShapeType type;
    V2D_Point pos;
    V2D_Extent extent; // enclosing rectangle to define
};

struct V2D_RoundedRectangle {
    V2D_ShapeType type;
    V2D_Point pos;
    V2D_Extent extent;
    float r0; // top-left corner
    float r1; // top-right corner
    float r2; // bottom-right corner
    float r3; // bottom-left corner
} V2D_Roundedectangle;

struct V2D_Polygon {
    V2D_ShapeType type;
    V2D_Point *points;
    const size_t count;
};

union V2D_Shape {
    V2D_ShapeType type;
    V2D_Rectangle rectangle;
    V2D_Ellipse ellipse;
    V2D_RoundedRectangle rounded_rectangle;
    V2D_Polygon polygon;
};

// Brushes
struct V2D_SolidBrush {
    V2D_BrushType type;
    V2D_Color color;
};

// struct V2D_LinearGradientFillBrush {
//     V2D_BrushType type;
// };

union V2D_Brush {
    V2D_BrushType type;
    V2D_SolidBrush solid_brush;
};

// Pens
struct V2D_Pen {
    int a;
};

union V2D_Drawable {
    int a;
};

#endif