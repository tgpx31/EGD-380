#ifndef TYPE_H
#define TYPE_H

// enum Type
// {
	// NONE = -1,
	// normal = 0,
	// fighting = 1,
	// flying = 2,
	// poison = 3,
	// ground = 4,
	// rock = 5,
	// bug = 6,
	// ghost = 7,
	// fire = 8,
	// water = 9,
	// grass = 10,
	// electric = 11,
	// psychic = 12,
	// ice = 13,
	// dragon = 14,
	// dark = 15
// };

static const float TypeChart[16][16] = 
{
	// defending type ----->
//  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
	1, 1, 1, 1, 1,.5, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, // normal
	2, 1,.5,.5, 1, 2,.5, 0, 1, 1, 1, 1,.5, 2, 1, 2, // fighting
	1, 2, 1, 1, 1,.5, 2, 1, 1, 1, 2,.5, 1, 1, 1, 1, // flying
	1, 1, 1,.5,.5,.5, 1,.5, 1, 1, 2, 1, 1, 1, 1, 1, // poison
	1, 1, 0, 2, 1, 2, 1, 1, 2,.5,.5, 2, 1, 1, 1, 1, // ground
	1,.5, 2, 1,.5,.5, 2, 1, 2,.5,.5, 1, 1, 2, 1, 1, // rock
	1,.5,.5,.5, 1,.5, 1, 1,.5, 1, 2, 1, 2, 1, 1, 2, // bug
	0, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1,.5, // ghost
	1, 1, 1, 1, 1,.5, 2, 1,.5,.5, 2, 1, 1, 2,.5, 1, // fire
	1, 1, 1, 1, 2, 2, 1, 1, 2,.5,.5, 1, 1, 1,.5, 1, // water
	1, 1,.5,.5, 2, 2,.5, 1,.5, 2,.5, 1, 1, 1,.5, 1, // grass
	1, 1, 2, 1, 0, 1, 1, 1, 1, 2,.5,.5, 1, 1,.5, 1, // electric
	1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,.5, 1, 1, 0, // psychic
	1, 1, 2, 1, 2, 1, 1, 1,.5,.5, 2, 1, 1,.5, 2, 1, // ice
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, // dragon
	1,.5, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1,.5, // dark
};

#endif