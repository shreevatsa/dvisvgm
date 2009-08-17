/*************************************************************************
** XMLDocument.h                                                        **
**                                                                      **
** This file is part of dvisvgm -- the DVI to SVG converter             **
** Copyright (C) 2005-2009 Martin Gieseking <martin.gieseking@uos.de>   **
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

#ifndef XMLDOCUMENT_H
#define XMLDOCUMENT_H

#include "XMLNode.h"

class XMLDocument
{
   public:
      XMLDocument (XMLElementNode *root=0);
      ~XMLDocument ();
		void clear ();
		void append (XMLNode *node);
		void setRootNode (XMLElementNode *root);
		const XMLElementNode* getRootElement () const {return rootElement;}
		ostream& write (ostream &os) const;
		bool emit (ostream& os, XMLNode *stopNode);

   private:
		list<XMLNode*> nodes;
		XMLElementNode *rootElement;
		bool emitted;
};

#endif
