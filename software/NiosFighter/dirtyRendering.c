#include "dirtyRendering.h"

void initDirtySection(dirtySection *target) {
	target->x = target->y = target->w = target->h = 0;
	target->next = NULL;
}

void addDirtySection(dirtyManager *dm, dirtySection *ds) {
	ds->next = dm->head;
	dm->head = ds;
}