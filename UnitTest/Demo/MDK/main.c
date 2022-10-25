#include "unittest.h"


#define _GROUP_ G1
SETUP()
{
}

TEARDOWN()
{
}


TEST(teteeeww)
{
	UT_INT_EQUAL(3+4,9);
}
#undef _GROUP_


#define _GROUP_ G2
SETUP()
{
}

TEARDOWN()
{
}


TEST(tetrrrr)
{
	UT_STRING_EQUAL("abc","abc");
}

#undef _GROUP_

#define _GROUP_ a2
SETUP()
{
}

TEARDOWN()
{
}


TEST(trrr)
{
	double a = 0.300006;
	double b = 0.300005;
	UT_FLOAT_EQUAL(a,b,0.0000001);
}

#undef _GROUP_


int main()
{
	testmain(0,NULL);
	while(1)
	{
	}
}
