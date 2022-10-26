/**
  ******************************************************************************
  * @file    main.c
  * @author  Kevin Gao
  * @version V1.0.0
  * @date    26-October-2022
  * @brief   This file provides unint test demo.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 Kevin Gao.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include "unittest.h"


#define _GROUP_ G1
SETUP()
{
}

TEARDOWN()
{
}


TEST(integer_compare)
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


TEST(string_compare)
{
	UT_STRING_EQUAL("abc","abc");
}

#undef _GROUP_

#define _GROUP_ a2
double a = 0.300006;
double b = 0.300005;
SETUP()
{
	a = 0.300006;
	b = 0.300005;
}

TEARDOWN()
{
	a = 0.0;
	b = 0.0;
}


TEST(float_compare)
{
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
