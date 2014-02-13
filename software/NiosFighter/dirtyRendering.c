#include <stdlib.h>
#include "dirtyRendering.h"

void initDirtySection(dirtySection *target) {
	target->x = target->y = target->w = target->h = 0;
	target->next = 0;
}

void initDirtyManager(dirtyManager *dm) {
	dm->head = NULL;
}

void addDirtySection(dirtyManager *dm, dirtySection *ds) {
	//ds->h += 50;
	//ds->w += 50;
	//ds->x -= 50;
	//ds->y -= 50;
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

void swapdm(dirtyManager **dm1, dirtyManager **dm2) {
	dirtyManager *temp;
	temp = *dm1;
	*dm1 = *dm2;
	*dm2 = temp;
}

void addDirty(dirtyManager *dm, int x, int y, int w, int h) {
	dirtySection *newSection = malloc(sizeof(dirtySection));
	initDirtySection(newSection);
	newSection->x = x;
	newSection->y = y;
	newSection->w = w;
	newSection->h = h;
	addDirtySection(dm, newSection);
}

