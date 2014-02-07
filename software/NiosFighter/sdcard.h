#include <altera_up_sd_card_avalon_interface.h>
#include <stdio.h>

typedef struct sdcard {
	alt_up_sd_card_dev device_reference;
	int connected;
}sdcard;

void initsdcard(sdcard *card,alt_up_sd_card_dev **device_reference);

void testsdcard(sdcard *card,alt_up_sd_card_dev *device_reference);
