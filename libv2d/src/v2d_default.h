#ifndef __V2D_DEFAULT_H
#define __V2D_DEFAULT_H

#include "v2d.h"

typedef struct {
    V2D_Point position;
    V2D_Color color;
} V2D_DefaultVertex;

typedef struct {
    V2D_Extent resolution;
    float time;
} V2D_DefaultUniformBuffer;

#endif