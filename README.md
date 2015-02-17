_dvisvgm_ &ndash; A fast DVI to SVG converter
=============================================

Description
-----------

_dvisvgm_ is a utility for TeX/LaTeX users. It converts
[DVI files](http://en.wikipedia.org/wiki/Device_independent_file_format) to the
XML-based scalable vector graphics format [SVG](http://www.w3.org/TR/SVG).
The latest releases support standard DVI files (format 2) as well as DVI output
created by [pTeX](http://www.ascii.co.jp/pb/ptex) in vertical mode (format 3),
and [XeTeX](http://scripts.sil.org/xetex) (format 5, also known as XDV).

Short overview of the main features:

* Complete font support including [virtual fonts](http://www.tex.ac.uk/cgi-bin/texfaq2html?label=virtualfonts), evaluation of [font encodings](http://www.tex.ac.uk/cgi-bin/texfaq2html?label=whatenc), CMap files, sub-font definitions and font maps.
* Glyph outlines of all required fonts are embedded into the generated SVG files.
* Glyph outlines of fonts that are not available in a vector format are generated on-the-fly by vectorizing [METAFONT](http://en.wikipedia.org/wiki/Metafont)'s bitmap output.
* _dvisvgm_ allows to replace [paths](http://www.w3.org/TR/SVG/fonts.html|font elements]] by [[http://www.w3.org/TR/SVG/paths.html) so that applications without SVG font support are enabled to render dvisvgm's output properly.
* Computes tight bounding boxes for the generated graphics, but supports common paper formats and arbitrary user-defined sizes as well.
* Option `--eps` allows to convert [EPS](https://en.wikipedia.org/wiki/Encapsulated_PostScript) files to SVG.
* [Intersections of clipping paths](http://dvisvgm.sf.net/Clipping) can be computed directly in order to increase the compatibility of the generated SVG files.
* Approximates PostScript [color gradient fills](http://dvisvgm.sourceforge.net/Gradients) not directly supported by SVG 1.1.
* Optionally creates compressed [SVGZ](https://en.wikipedia.org/wiki/Scalable_Vector_Graphics#Compression) files.
* Provides options for applying page transformations, like translation, rotation, scaling, and skewing.
* Evaluates color, emTeX, tpic, hyperref/HyperTeX, PDF mapfile, and PostScript [specials](http://www.tex.ac.uk/cgi-bin/texfaq2html?label=specials).
* The converter was successfully tested on various Linux ([TeX Live](http://www.tug.org/texlive)) and Windows ([MiKTeX](http://www.miktex.org)) systems.
* _dvisvgm_ has been added to [TeX Live](http://www.tug.org/texlive) and is therefore available for a wide range of operating systems.

<a href="http://dvisvgm.sf.net/Downloads">![dvisvgm downloads](http://dvisvgm.sf.net/uploads/download.png)</a>


Usage
-----
For detailed information about the command-line interface and all available
options of _dvisvgm_, see the [manual page](http://dvisvgm.sourceforge.net/Manpage).


Dependencies
------------

_dvisvgm_ relies on the following free libraries:

* [Clipper](http://www.angusj.com/delphi/clipper.php)  
  To compute the intersection of two curved paths, _dvisvgm_ flattens the paths to
  polygons, intersects them using a slightly modified version of Clipper, and reconstructs
  the curves afterwards.

* [FreeType 2](http://www.freetype.org)  
  This library is used to extract the glyph outlines from vector fonts (PFB, OTF, TTF).

* [Ghostscript](http://pages.cs.wisc.edu/~ghost)  
  The PostScript special handler requires the Ghostscript library libgs.so (Linux)
  or gsdll32.dll/gsdll64.dll (Windows) to be installed. If the configure script
  finds the corresponding Ghostscript development files on the system, it
  directly links against libgs.so. Otherwise, the library is looked up during
  runtime and the PostScript support is enabled only if libgs.so could be found.
  Due to incompatible changes of the Ghostscript API, _dvisvgm_ requires
  Ghostscript 8.31 or later.

* [Kpathsea](https://tug.org/kpathsea)  
  This library is part of the Web2C package and is usually installed in
  conjunction with a TeX distribution. Kpathsea provides functions for searching
  files in the large texmf tree.

* [potracelib](http://potrace.sourceforge.net)  
  Peter Selinger's bitmap tracing library is utilized to vectorize Metafont's
  bitmap output.

* [zlib](http://www.zlib.org)  
  Compressed SVG files are produced by using functions of this library and the
  [Gzstream wrapper classes](http://www.cs.unc.edu/Research/compgeom/gzstream)
  which are licensed under LGPL version 2.1 (or optionally any later version)
  and should be included with this package.

If you want to build and run the testsuite located in the _tests_
subdirectory, you also need the [googletest](http://code.google.com/p/googletest)
libraries.


Compilation
-----------

Quick installation info:
* type `./configure`
* type `make`
* type `make install` as root (or `sudo make install`)

For generic configuration instructions see the file INSTALL.

The configure script should recognize all necessary parameters.
If a library is installed but not detected, specify its location
as command-line parameter of configure, e.g.
`./configure --with-freetype=/usr/local/freetype`
(all available options can be displayed with `./configure --help`)

The tracer module calls Metafont in case of lacking TFM or PFB files
via a system call. Please ensure that Metafont is installed and
reachable through the search path.

If you don't like compiling the sources yourself, you can download
pre-compiled binaries for Windows and MiKTeX from the
[project website](http://dvisvgm.sourceforge.net) instead.


Additional Information
----------------------

This package is available from [CTAN](http://ctan.org), and can be downloaded
from the [project website](http://dvisvgm.sourceforge.net) as well. There you
can find the sources, pre-compiled binaries, the manual page, FAQs and further
information about the converter and related topics.

If you've found a bug, please let me know. You can either send me an email or
preferably use the [bug tracker at Launchpad](https://launchpad.net/dvisvgm).


Copyright
---------

Copyright &copy; 2005&ndash;2015 [Martin Gieseking](mailto:martin.gieseking@uos.de)

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, see <http://www.gnu.org/licenses/>.

See the file COPYING for details.

