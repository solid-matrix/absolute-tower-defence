#ifndef __LIBECS_H
#define __LIBECS_H

#ifdef _WIN32
#ifdef DLL_EXPORT
#define ECS_DECLSPEC __declspec(dllexport)
#else

#define ECS_DECLSPEC __declspec(dllimport)
#endif

#define ECS_CALL __cdecl

#else
#define ECS_DECLSPEC
#define ECS_CALL
#endif

#include <stddef.h>

typedef struct ECS_World ECS_World;

typedef size_t ECS_EntityId;

typedef size_t ECS_ComponentType;

typedef size_t ECS_SystemType;

typedef struct ECS_System ECS_System;

struct ECS_System {
};

ECS_DECLSPEC ECS_World *ECS_CALL ECS_CreateWorld();

ECS_DECLSPEC void ECS_CALL ECS_DestroyWorld(ECS_World *world);

ECS_DECLSPEC ECS_ComponentType ECS_CALL ECS_RegisterComponent(ECS_World *world, size_t size);

ECS_DECLSPEC ECS_SystemType ECS_CALL ECS_RegisterSystem(ECS_World *world, ECS_System *system);

ECS_DECLSPEC ECS_EntityId ECS_CALL ECS_CreateEntity(ECS_World *world);

ECS_DECLSPEC void ECS_CALL ECS_AddComponent(ECS_World *world, ECS_EntityId entity, ECS_ComponentType componentType, void *data);

ECS_DECLSPEC void ECS_CALL ECS_Update(ECS_World *world);

#endif