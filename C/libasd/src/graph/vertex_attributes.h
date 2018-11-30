#ifndef __VERTEX_ATTRIBUTES_H__
#define __VERTEX_ATTRIBUTES_H__

#include "../standard_libraries.h"
#include "vertex.h"

//typedef struct dijkstra_attributes * DijkstraAttributes;
typedef struct tarjan_attributes * TarjanAttributes;
typedef struct steps_attributes * StepsAttributes;

/*
struct dijkstra_attributes
{
	double distance;
};
*/

struct tarjan_attributes
{
  int index;
  int lowIndex;
  int onStack;
};

struct steps_attributes
{
  int start;
  int end;
};

//DijkstraAttributes new_dijkstra_attributes(double distance);
//void destroy_dijkstra_attributes(DijkstraAttributes* attributes);
TarjanAttributes new_tarjan_attributes();
void destroy_tarjan_attributes(TarjanAttributes* attributes);
StepsAttributes new_steps_attributes(int start, int end);
void destroy_steps_attributes(StepsAttributes* attributes);
//int compare_vertex_dijkstra(Vertex v1, Vertex v2);
void destroy_double_pointer(double** double_pointer);

#endif