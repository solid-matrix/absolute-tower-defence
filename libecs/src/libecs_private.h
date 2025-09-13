#ifndef __LIBECS_IMPL_H
#define __LIBECS_IMPL_H

#include "libecs.h"
typedef struct ECS_EntityManager {

} ECS_EntityManager;

typedef struct ECS_ComponentStore {
    size_t component_size;

    // TODO: how to store components

    size_t count;
    size_t capacity;
} ECS_ComponentStore;

typedef struct ECS_ComponentManager {
    ECS_ComponentStore *stores;
    size_t count;
    size_t capacity;
} ECS_ComponentManager;

typedef struct ECS_SystemManager {
    ECS_System **systems;

    size_t count;
    size_t capacity;
} ECS_SystemManager;

struct ECS_World {
    ECS_EntityManager *entity_manager;
    ECS_ComponentManager *component_manager;
    ECS_SystemManager *system_manager;
};

ECS_EntityManager *ECS_CreateEntityManager();

void ECS_DestroyEntityManager(ECS_EntityManager *entity_manager);

ECS_ComponentManager *ECS_CreateComponentManager();

void *ECS_DestroyComponentManager(ECS_ComponentManager *component_manager);

ECS_SystemManager *ECS_CreateSystemManager();

void ECS_DestroySystemManager(ECS_SystemManager *system_manager);

#endif