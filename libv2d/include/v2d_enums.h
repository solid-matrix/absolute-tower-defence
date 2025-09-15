#ifndef __V2D_ENUMS_H
#define __V2D_ENUMS_H

typedef enum V2D_ShapeType {
    V2D_SHAPE_RECTANGLE,         // rectangle (special polygon, use the most)
    V2D_SHAPE_ELLIPSE,           // ellipse, circle, point
    V2D_SHAPE_ROUNDED_RECTANGLE, // rounded-rectangle
    V2D_SHAPE_POLYGON,           // triangle , convex-polygon
} V2D_ShapeType;

typedef enum V2D_BrushType {
    V2D_BRUSH_SOLID,
    V2D_BRUSH_TEXTURE,
    V2D_BRUSH_PATTERN,
    V2D_BRUSH_SHADER,
    V2D_BRUSH_LINEAR_GRADIENT,
    V2D_BRUSH_RADIAL_GRADIENT,
    V2D_BRUSH_CORNER_GRADIENT,
} V2D_BrushType;

#endif