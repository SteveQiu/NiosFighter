#include "drawing.h"
int fstand1 = 0;
int fstand2 = 0;
int fpunch1 = 0;
int fpunch2 = 0;

void DrawStartScreen(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy,
		alt_up_char_buffer_dev* char_buffer_cpy, int x, int y, int w, int h) {
	int row;
	int column;
	int realw = x + w;
	int realh = y + h;
	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			/*draw_pixel_fast(pixel_buffer_cpy, startscreen[row][column], column,
			 row);*/
		}
	}
	alt_up_char_buffer_string(char_buffer_cpy, "Start Game", 35, 40);
	alt_up_char_buffer_string(char_buffer_cpy, "Instruction", 34, 50);
	//80*60 array across 320*280 resolution screen
}

void DrawInstruction(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy,
		alt_up_char_buffer_dev* char_buffer_cpy) {

}

void DrawBackground(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, int w, int h) {
	int row;
	int column;
	int realw = x + w;
	int realh = y + h;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			draw_pixel_fast(pixel_buffer_cpy,
					backgroundwithoutbars[row][column], column, row);
		}
	}
}

void DrawHealthBar(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y) {
	int row;
	int column;
	int realw = x + 126;
	int realh = y + 6;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			draw_pixel_fast(pixel_buffer_cpy, filledhealthbar[row - y][column
					- x], column, row);
		}
	}
}

void DrawBlockBar(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y) {
	int row;
	int column;
	int realw = x + 61;
	int realh = y + 1;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			draw_pixel_fast(pixel_buffer_cpy, blockbar[row - y][column - x],
					column, row);
		}
	}
}

void DrawBlock1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 71;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (blocking1[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy,
						blocking1[row - y][column - x], column, row);
		}
	}
	addDirty(dm, x, y, 71, 100);
}

void DrawBlock2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 42;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (blocking2[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy,
						blocking2[row - y][column - x], column, row);
		}
	}
	addDirty(dm, x, y, 42, 100);
}

void DrawHit1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 71;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (hit1[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, hit1[row - y][column - x],
						column, row);
		}
	}

	addDirty(dm, x, y, 71, 100);
}

void DrawHit2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 87;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (hit2[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, hit2[row - y][column - x],
						column, row);
		}
	}

	addDirty(dm, x, y, 87, 100);
}

void DrawStanding1p1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 42;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing1p1[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing1p1[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 42, 100);
}

void DrawStanding1p2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 37;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing1p2[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing1p2[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 37, 100);
}

void DrawStanding1p3(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 38;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing1p3[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing1p3[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 38, 100);
}

void DrawStanding1p4(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 41;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing1p4[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing1p4[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 41, 100);
}

void DrawStanding1p5(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 48;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing1p5[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing1p5[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 48, 100);
}

void DrawStanding1p6(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 48;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing1p6[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing1p6[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 48, 100);
}

void DrawStanding1p7(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 54;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing1p7[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing1p7[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 54, 100);
}
void DrawStanding2p1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 76;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing2p1[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing2p1[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 76, 100);
}

void DrawStanding2p2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 73;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing2p2[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing2p2[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 73, 100);
}

void DrawStanding2p3(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 64;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing2p3[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing2p3[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 64, 100);
}

void DrawStanding2p4(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 63;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing2p4[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing2p4[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 63, 100);
}

void DrawStanding2p5(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 62;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing2p5[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing2p5[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 62, 100);
}

void DrawStanding2p6(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 67;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing2p6[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing2p6[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 74, 100);
}

void DrawStanding2p7(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 74;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (standing2p7[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, standing2p7[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 74, 100);
}

void DrawPunching1p1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 61;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (punching1p1[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, punching1p1[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 61, 100);
}

void DrawPunching1p2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 87;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (punching1p2[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, punching1p2[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 87, 100);
}

void DrawPunching1p3(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 86;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (punching1p3[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, punching1p3[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 86, 100);
}

void DrawPunching1p4(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 61;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (punching1p4[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, punching1p4[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 61, 100);
}

void DrawPunching2p1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 61;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (punching2p1[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, punching2p1[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 61, 100);
}

void DrawPunching2p2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 69;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (punching2p2[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, punching2p2[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 69, 100);
}

void DrawPunching2p3(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 86;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (punching2p3[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, punching2p3[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 86, 100);
}

void DrawPunching2p4(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm) {
	int row;
	int column;
	int realw = x + 87;
	int realh = y + 100;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (punching2p4[row - y][column - x] != 0xFFFF)
				draw_pixel_fast(pixel_buffer_cpy, punching2p4[row - y][column
						- x], column, row);
		}
	}

	addDirty(dm, x, y, 87, 100);
}

void DrawHP(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy, gameState *gstate,
		dirtyManager *dm) {

	int x_1 = 14;
	int y_1 = 10;
	int w_1 = 126 - gstate->player1.health * 1.26 + 1;
	int h_1 = 6;

	int x_2 = 180 + gstate->player2.health * 1.26;
	int y_2 = 10;
	int w_2 = 126 - gstate->player2.health * 1.26 + 1;
	int h_2 = 6;

	addDirty(dm, x_1, y_1, w_1, h_1);
	addDirty(dm, x_2, y_2, w_2, h_2);
}

//Draw the timer by giving a time in int, using inttochar to convert int
void DrawTimer(alt_up_char_buffer_dev* char_buffer_cpy, int time_remain) {
	// Write some text
	char time_char[3];
	InttoChar(time_remain, time_char);

	alt_up_char_buffer_string(char_buffer_cpy, " ", 38, 3);
	alt_up_char_buffer_string(char_buffer_cpy, time_char, 39, 3);
	alt_up_char_buffer_string(char_buffer_cpy, " ", 41, 3);
	//80*60 array across 320*280 resolution screen
}

void DrawStanding1(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate,
		dirtyManager *dm) {
	if (fstand1 == 0) {
		DrawStanding1p1(buffer_cpy, gstate->player1.xPosition + 110
				- gstate->player1.width, 110, dm);
		fstand1++;
	} else if (fstand1 == 1) {
		DrawStanding1p2(buffer_cpy, gstate->player1.xPosition + 110
				- gstate->player1.width - 1, 110, dm);
		fstand1++;
	} else if (fstand1 == 2) {
		DrawStanding1p3(buffer_cpy, gstate->player1.xPosition + 110
				- gstate->player1.width - 2, 110, dm);
		fstand1++;
	} else if (fstand1 == 3) {
		DrawStanding1p4(buffer_cpy, gstate->player1.xPosition + 110
				- gstate->player1.width - 3, 110, dm);
		fstand1++;
	} else if (fstand1 == 4) {
		DrawStanding1p5(buffer_cpy, gstate->player1.xPosition + 110
				- gstate->player1.width - 4, 110, dm);
		fstand1++;
	} else if (fstand1 == 5) {
		DrawStanding1p6(buffer_cpy, gstate->player1.xPosition + 110
				- gstate->player1.width - 3, 110, dm);
		fstand1++;
	} else if (fstand1 == 6) {
		DrawStanding1p7(buffer_cpy, gstate->player1.xPosition
				- gstate->player1.width - 2 + 110, 110, dm);
		fstand1 = 0;
	}
}

void DrawStanding2(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate,
		dirtyManager *dm) {
	if (fstand2 == 0) {
		DrawStanding2p1(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width, 110, dm);
		fstand2++;
	} else if (fstand2 == 1) {
		DrawStanding2p2(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width - 1, 110, dm);
		fstand2++;
	} else if (fstand2 == 2) {
		DrawStanding2p3(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width - 2, 110, dm);
		fstand2++;
	} else if (fstand2 == 3) {
		DrawStanding2p4(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width - 3, 110, dm);
		fstand2++;
	} else if (fstand2 == 4) {
		DrawStanding2p5(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width - 4, 110, dm);
		fstand2++;
	} else if (fstand2 == 5) {
		DrawStanding2p6(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width - 3, 110, dm);
		fstand2++;
	} else if (fstand2 == 6) {
		DrawStanding2p7(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width - 2, 110, dm);
		fstand2 = 0;
	}
}

void DrawPunching1(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate,
		dirtyManager *dm) {
	if (fpunch1 == 0) {
		DrawPunching1p1(buffer_cpy, gstate->player1.xPosition + 110
				- gstate->player1.width, 110, dm);
		fpunch1++;
	} else if (fpunch1 == 1) {
		DrawPunching1p2(buffer_cpy, gstate->player1.xPosition + 110
				- gstate->player1.width, 110, dm);
		fpunch1++;
	} else if (fpunch1 == 2) {
		DrawPunching1p3(buffer_cpy, gstate->player1.xPosition + 110
				- gstate->player1.width, 110, dm);
		fpunch1++;
	} else if (fpunch1 == 3) {
		DrawPunching1p4(buffer_cpy, gstate->player1.xPosition + 110
				- gstate->player1.width, 110, dm);
		fpunch1 = 0;
	}
}

void DrawPunching2(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate,
		dirtyManager *dm) {
	if (fpunch2 == 0) {
		DrawPunching2p1(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width - 3, 110, dm);
		fpunch2++;
	} else if (fpunch2 == 1) {
		DrawPunching2p2(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width - 5, 110, dm);
		fpunch2++;
	} else if (fpunch2 == 2) {
		DrawPunching2p3(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width - 7, 110, dm);
		fpunch2++;
	} else if (fpunch2 == 3) {
		DrawPunching2p4(buffer_cpy, gstate->player2.xPosition + 150 - 33
				- gstate->player2.width - 9, 110, dm);
		fpunch2 = 0;
	}
}

void DrawCharacter(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate,
		dirtyManager *dm) {

	if (gstate->player1.status == STATUS_IDLE) {
		DrawStanding1(buffer_cpy, gstate, dm);
	}
	if (gstate->player2.status == STATUS_IDLE) {
		DrawStanding2(buffer_cpy, gstate, dm);
	}
	if (gstate->player1.status == STATUS_PUNCHING) {
		DrawPunching1(buffer_cpy, gstate, dm);
	}
	if (gstate->player2.status == STATUS_PUNCHING) {
		DrawPunching2(buffer_cpy, gstate, dm);
		playsound("punch.wav", gstate->audio);
	}
	if (gstate->player1.status == STATUS_STUNNED) {
		DrawHit1(buffer_cpy, gstate->player1.xPosition - gstate->player1.width
				+ 110, 110, dm);
	}
	if (gstate->player2.status == STATUS_STUNNED) {
		DrawHit2(buffer_cpy, gstate->player2.xPosition - gstate->player2.width
				- 33 + 150, 110, dm);
	}
	if (gstate->player1.status == STATUS_BLOCKING) {
		DrawBlock1(buffer_cpy, gstate->player1.xPosition
				- gstate->player1.width + 110, 110, dm);
	}
	if (gstate->player2.status == STATUS_BLOCKING) {
		DrawBlock2(buffer_cpy, gstate->player2.xPosition - 33
				- gstate->player2.width + 150, 110, dm);
	}
}

