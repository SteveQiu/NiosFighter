#include <stdlib.h>
#include "dirtyRendering.h"

void initDirtySection(dirtySection *target) {
	target->x = target->y = target->w = target->h = 0;
	target->next = 0;
}

void addDirtySection(dirtyManager *dm, dirtySection *ds) {
	ds->next = dm->head;
	dm->head = ds;
}

void popDirtySection(dirtyManager *dm) {
	if (dm->head != 0) {
		dirtySection *temp = dm->head;
		dm->head = dm->head->next;
		free(temp);
	}
}
