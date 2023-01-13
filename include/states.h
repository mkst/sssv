#ifndef STATES_H
#define STATES_H

// getters

#define ST_GET_HEALTH         4+0x7F7F

#define ST_GET_RANDOM         5+0x7F7F

#define ST_GET_XPOS           6+0x7F7F
#define ST_GET_ZPOS           7+0x7F7F
#define ST_GET_YPOS           8+0x7F7F

#define ST_GET_XVEL           11+0x7F7F
#define ST_GET_ZVEL           12+0x7F7F
#define ST_GET_YVEL           13+0x7F7F
#define ST_GET_ZROT           14+0x7F7F
#define ST_GET_YROT           15+0x7F7F

#define ST_GET_SCORE          19+0x7F7F
#define ST_GET_STATE          21+0x7F7F
#define ST_GET_CONT_STICK_X   24+0x7F7F
#define ST_GET_CONT_STICK_Y   25+0x7F7F
#define ST_GET_CONT_BUTTON_A  26+0x7F7F
#define ST_GET_CONT_BUTTON_B  27+0x7F7F
#define ST_GET_OBJECT_TYPE    32+0x7F7F

// setters

#define ST_SET_HEALTH         4+0x7F7F

#define ST_SET_XPOS           6+0x7F7F
#define ST_SET_ZPOS           7+0x7F7F
#define ST_SET_YPOS           8+0x7F7F

#define ST_SET_XVEL           11+0x7F7F
#define ST_SET_ZVEL           12+0x7F7F
#define ST_SET_YVEL           13+0x7F7F
#define ST_SET_ZROT           14+0x7F7F
#define ST_SET_YROT           15+0x7F7F

#define ST_SET_SCORE          19+0x7F7F
#define ST_SET_STATE          21+0x7F7F

// commands

#define CMD_NOOP              0
#define CMD_ADD               1
#define CMD_SUBTRACT          2
#define CMD_MULTIPLY          3
#define CMD_DIVIDE            4
#define CMD_LOGICAL_AND       5
#define CMD_LOGICAL_OR        6
#define CMD_MODULO            7
#define CMD_RSHIFT            8
#define CMD_LSHIFT            9

#endif
