typedef struct dirtySection {
	int x,y;
	int w,h;
	dirtySection *next;
};

void initDirtySection(dirtySection *target);

typedef struct dirtyManager {
	dirtySection *head;
};

void addDirtySection(dirtyManager *dm, dirtySection *ds);
void popDirtySection(dirtyManager *dm);

//Usage in rendering function
/*
 * void render(dirtyManager *dm) {
 * 	while (dm->head != NULL) {
 * 		redrawSection(dm->head);
 * 		popDirtySection(dm);
 * 	}
 *
 *	renderCharacter(dm);
 * }
 *
 * void renderCharacter(dirtyManager *dm) {
 * 	dirtySection *newSection = malloc(sizeof(dirtySection));
 * 	initDirtySection(newSection);
 * 	newsection->x = 150
 *  //add in rest of section info
 *  addDirtySection(dm, newSection);
 * }
 *
 */
