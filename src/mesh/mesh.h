#ifndef MESH_H
#define MESH_H

#include <stdint.h>

typedef struct {
    float x;
    float y;
    float z;
} vertex_t;

typedef struct {
    vertex_t *vertices;
    uint32_t *indices;
} mesh_t;

#endif