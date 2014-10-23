/*************************************************************************
** ColorTest.cpp                                                        **
**                                                                      **
** This file is part of dvisvgm -- the DVI to SVG converter             **
** Copyright (C) 2005-2014 Martin Gieseking <martin.gieseking@uos.de>   **
**                                                                      **
** This program is free software; you can redistribute it and/or        **
** modify it under the terms of the GNU General Public License as       **
** published by the Free Software Foundation; either version 3 of       **
** the License, or (at your option) any later version.                  **
**                                                                      **
** This program is distributed in the hope that it will be useful, but  **
** WITHOUT ANY WARRANTY; without even the implied warranty of           **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         **
** GNU General Public License for more details.                         **
**                                                                      **
** You should have received a copy of the GNU General Public License    **
** along with this program; if not, see <http://www.gnu.org/licenses/>. **
*************************************************************************/

#include <gtest/gtest.h>
#include "Color.h"

using namespace std;

TEST(ColorTest, construct) {
	Color c1(UInt8(1), UInt8(2), UInt8(3));
	EXPECT_EQ(c1.rgbString(), "#010203");
	Color c2(1.0/255, 2.0/255, 3.0/255);
	EXPECT_EQ(c2.rgbString(), "#010203");
	Color c3 = "Blue";
	EXPECT_EQ(c3.rgbString(), "#0000ff");
	Color c4 = "blue";
	EXPECT_EQ(c4.rgbString(), "#0000ff");
}


TEST(ColorTest, gray) {
	Color c;
	c.setGray(10.0/255);
	EXPECT_EQ(c.rgbString(), "#0a0a0a");
	c.setGray(UInt8(15));
	EXPECT_EQ(c.rgbString(), "#0f0f0f");
}


TEST(ColorTest, hsb) {
	Color c;
	c.setHSB(0.0, 1.0, 1.0);
	EXPECT_EQ(c.rgbString(), "#ff0000");
	c.setHSB(120.0/360, 1.0, 1.0);
	EXPECT_EQ(c.rgbString(), "#00ff00");
	c.setHSB(20.0/360, 0.75, 0.8);
	EXPECT_EQ(c.rgbString(), "#cc6633");
}


TEST(ColorTest, cmyk) {
	Color c;
	c.setCMYK(0.5, 0.4, 0.6, 0.2);
	EXPECT_EQ(c.rgbString(), "#4d6633");
}


TEST(ColorTest, name) {
	Color c;
	EXPECT_TRUE(c.setName("Magenta"));
	EXPECT_EQ(c.rgbString(), "#ff00ff");
	EXPECT_FALSE(c.setName("mulberry"));
	EXPECT_TRUE(c.setName("mulberry", false));
	EXPECT_EQ(c.rgbString(), "#a314f9");

	EXPECT_FALSE(c.setName("#Magenta"));
	EXPECT_FALSE(c.setName("#bcdefg"));
	EXPECT_TRUE(c.setName("#abcdef"));
	EXPECT_EQ(c.rgbString(), "#abcdef");
	EXPECT_TRUE(c.setName("#89A"));
	EXPECT_EQ(c.rgbString(), "#00089a");
}


TEST(ColorTest, getXYZ) {
	Color c;
	double x, y, z;
	c.setRGB(1.0, 0, 0);
	c.getXYZ(x, y, z);
	EXPECT_NEAR(x, 0.412456, 0.000001);
	EXPECT_NEAR(y, 0.212673, 0.000001);
	EXPECT_NEAR(z, 0.019334, 0.000001);

	c.setRGB(0, 1.0, 0);
	c.getXYZ(x, y, z);
	EXPECT_NEAR(x, 0.357576, 0.000001);
	EXPECT_NEAR(y, 0.715152, 0.000001);
	EXPECT_NEAR(z, 0.119192, 0.000001);

	c.setRGB(0, 0, 1.0);
	c.getXYZ(x, y, z);
	EXPECT_NEAR(x, 0.180437, 0.000001);
	EXPECT_NEAR(y, 0.072175, 0.000001);
	EXPECT_NEAR(z, 0.950304, 0.000001);

	valarray<double> rgb(3), xyz(3);
	rgb[0] = 0.2;
	rgb[1] = 0.75;
	rgb[2] = 0.9;
	Color::RGB2XYZ(rgb, xyz);
	EXPECT_NEAR(xyz[0], 0.342574, 0.000001);
	EXPECT_NEAR(xyz[1], 0.437554, 0.000001);
	EXPECT_NEAR(xyz[2], 0.811202, 0.000001);
}


TEST(ColorTest, getLab) {
	Color c;
	double l, a, b;
	c.setRGB(1.0, 0, 0);
	c.getLab(l, a, b);
	EXPECT_NEAR(l, 53.2408, 0.0001);
	EXPECT_NEAR(a, 80.0925, 0.0001);
	EXPECT_NEAR(b, 67.2032, 0.0001);

	c.setRGB(0, 1.0, 0);
	c.getLab(l, a, b);
	EXPECT_NEAR(l, 87.7347, 0.0001);
	EXPECT_NEAR(a, -86.1827, 0.0001);
	EXPECT_NEAR(b, 83.1793, 0.0001);

	c.setRGB(0, 0, 1.0);
	c.getLab(l, a, b);
	EXPECT_NEAR(l, 32.2970, 0.0001);
	EXPECT_NEAR(a, 79.1875, 0.0001);
	EXPECT_NEAR(b, -107.8602, 0.0001);

	valarray<double> rgb(3), lab(3);
	rgb[0] = 0.2;
	rgb[1] = 0.75;
	rgb[2] = 0.9;
	Color::RGB2Lab(rgb, lab);
	EXPECT_NEAR(lab[0], 72.0647, 0.0001);
	EXPECT_NEAR(lab[1], -23.7597, 0.0001);
	EXPECT_NEAR(lab[2], -29.4733, 0.0001);
}
