#ifndef __V2D_DRAWABLE_H
#define __V2D_DRAWABLE_H

#include "v2d.h"
#include <stddef.h>

// Shapes
typedef enum V2D_ShapeType {
    V2D_SHAPE_RECTANGLE,         // rectangle (special polygon, use the most)
    V2D_SHAPE_ELLIPSE,           // ellipse, circle, point
    V2D_SHAPE_ROUNDED_RECTANGLE, // rounded-rectangle
    V2D_SHAPE_POLYGON,           // triangle , convex-polygon
} V2D_ShapeType;

typedef struct V2D_Rectangle {
    V2D_ShapeType type;
    V2D_Point pos;
    V2D_Extent extent;
} V2D_Rectangle;

typedef struct V2D_Ellipse {
    V2D_ShapeType type;
    V2D_Point pos;
    V2D_Extent extent; // enclosing rectangle to define
} V2D_Ellipse;

typedef struct V2D_RoundedRectangle {
    V2D_ShapeType type;
    V2D_Point pos;
    V2D_Extent extent;
    float r0; // top-left corner
    float r1; // top-right corner
    float r2; // bottom-right corner
    float r3; // bottom-left corner
} V2D_RoundedRectangle;

typedef struct V2D_Polygon {
    V2D_ShapeType type;
    V2D_Point *points;
    const size_t count;
} V2D_Polygon;

typedef union V2D_Shape {
    V2D_ShapeType type;
    V2D_Rectangle rectangle;
    V2D_Ellipse ellipse;
    V2D_RoundedRectangle rounded_rectangle;
    V2D_Polygon polygon;
} V2D_Shape;

size_t a = sizeof(V2D_Shape);

// Brushes
typedef struct V2D_Brush {

} V2D_Brush;

// Pens
typedef struct V2D_Pen {

} V2D_Pen;

typedef union V2D_Drawable V2D_Drawable;

union V2D_Drawable {
};

#endif