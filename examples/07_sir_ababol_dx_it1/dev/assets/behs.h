	
// Add these:
// + 1 kills      (useless if + 8 obstacle)
// + 2 quicksands ( " , needs ENABLE_QUICKSANDS)
// + 4 platform   (side view)
// + 8 obstacle   (nullifies + 1 & + 2, see bellow)
// +16 breakable
// +32 conveyor   (pushes left, + 1 pushes right)
// +64 slippery

// Special values (= nonsensical combinations):
// 10 lock
// 11 pushable

const unsigned char behs0 [] = {
	0, 8, 8, 8, 0, 0, 0, 8, 0, 0, 8, 4, 8, 1, 8, 10,
	0, 0, 0, 0, 0
};

const unsigned char behs1 [] = {
	0, 0, 8, 1, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8
};

// 68 = 4 + 64, slippery platform
// 24 = 8 + 16, breakable obstacle
// 40 = 8 + 32, conveyor platform, pushes left.
