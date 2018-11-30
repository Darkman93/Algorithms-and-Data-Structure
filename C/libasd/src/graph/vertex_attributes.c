#include "vertex_attributes.h"
#include "../utils/comparators.h"

/*
DijkstraAttributes new_dijkstra_attributes(double distance)
{
	DijkstraAttributes attributes = malloc(sizeof(struct dijkstra_attributes));
	if(!attributes) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
	attributes->distance = distance;
	return attributes;
}

void destroy_dijkstra_attributes(DijkstraAttributes* attributes)
{
	free(*attributes);
	attributes = NULL;
}
*/

TarjanAttributes new_tarjan_attributes()
{
	TarjanAttributes attributes = malloc(sizeof(struct tarjan_attributes));
	if(!attributes) error(EXIT_FAILURE, 0, "malloc error in function %s", __func__);
	return attributes;
}

void destroy_tarjan_attributes(TarjanAttributes* attributes)
{
	free(*attributes);
	attributes = NULL;
}

StepsAttributes new_steps_attributes(int start, int end)
{
	StepsAttributes attributes = malloc(sizeof(struct steps_attributes));
	if(!attributes) error(EXIT_FAILURE, 0, "malloc error in function %s", __func__);
	attributes->start = start;
	attributes->end = end;
	return attributes;
}

void destroy_steps_attributes(StepsAttributes* attributes)
{
	free(*attributes);
	attributes = NULL;
}

//todo questa funzione la lasciamo qua???
void destroy_double_pointer(double** double_pointer)
{
	free(*double_pointer);
	double_pointer = NULL;
}

/*
int compare_vertex_dijkstra(Vertex v1, Vertex v2)
{
	if(!v1 || !v2 || !v1->attributes || !v2->attributes) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
	double* a = &((DijkstraAttributes) v1->attributes)->distance;
	double* b = &((DijkstraAttributes) v2->attributes)->distance;
	return compare_double(a, b);
}
*/