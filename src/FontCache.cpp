/***********************************************************************
** FontCache.cpp                                                      **
**                                                                    **
** This file is part of dvisvgm -- the DVI to SVG converter           **
** Copyright (C) 2005-2009 Martin Gieseking <martin.gieseking@uos.de> **
**                                                                    **
** This program is free software; you can redistribute it and/or      **
** modify it under the terms of the GNU General Public License        **
** as published by the Free Software Foundation; either version 2     **
** of the License, or (at your option) any later version.             **
**                                                                    **
** This program is distributed in the hope that it will be useful,    **
** but WITHOUT ANY WARRANTY; without even the implied warranty of     **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      **
** GNU General Public License for more details.                       **
**                                                                    **
** You should have received a copy of the GNU General Public License  **
** along with this program; if not, write to the Free Software        **
** Foundation, Inc., 51 Franklin Street, Fifth Floor,                 **
** Boston, MA 02110-1301, USA.                                        **
***********************************************************************/

#include <fstream>
#include "FontCache.h"
#include "FontGlyph.h"

using namespace std;

enum 

FontCache::FontCache () {
}


void FontCache::set (int c, const list<GlyphCommand*> &cmds) {
	
}


FontGlyph* glyph (int c) const {
	if (_glyphdata.find(c) == _glyphdata.end())
		return 0;
	FORALL ();
}


void FontCache::write (const char *fname) {
	ofstream ofs(fname, ios::binary);
	if (ofs) {
		FORALL (_glyphdata, ) {

		}
	}
}