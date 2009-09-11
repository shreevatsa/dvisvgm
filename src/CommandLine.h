// This file was automatically generated by opt2cpp.
// It is part of the dvisvgm package and published under the terms
// of the GNU General Public License version 3 or later.
// See file COPYING for further details.
// (C) 2009 Martin Gieseking <martin.gieseking@uos.de>

#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include "CmdLineParserBase.h"

class CommandLine : public CmdLineParserBase
{
   public:
      CommandLine () {init();}
      CommandLine (int argc, char **argv, bool printErrors) {parse(argc, argv, printErrors);}
      void help () const;
      void status () const;
      int numOptions () const {return 22;}
      bool page_given () const {return _page_given;}
      unsigned page_arg () const {return _page_arg;}
      bool map_file_given () const {return _map_file_given;}
      const std::string& map_file_arg () const {return _map_file_arg;}
      bool bbox_format_given () const {return _bbox_format_given;}
      const std::string& bbox_format_arg () const {return _bbox_format_arg;}
      bool output_given () const {return _output_given;}
      const std::string& output_arg () const {return _output_arg;}
      bool stdout_given () const {return _stdout_given;}
      bool no_fonts_given () const {return _no_fonts_given;}
      bool no_styles_given () const {return _no_styles_given;}
      bool zip_given () const {return _zip_given;}
      int zip_arg () const {return _zip_arg;}
      bool rotate_given () const {return _rotate_given;}
      double rotate_arg () const {return _rotate_arg;}
      bool scale_given () const {return _scale_given;}
      const std::string& scale_arg () const {return _scale_arg;}
      bool translate_given () const {return _translate_given;}
      const std::string& translate_arg () const {return _translate_arg;}
      bool transform_given () const {return _transform_given;}
      const std::string& transform_arg () const {return _transform_arg;}
      bool cache_given () const {return _cache_given;}
      const std::string& cache_arg () const {return _cache_arg;}
      bool mag_given () const {return _mag_given;}
      double mag_arg () const {return _mag_arg;}
      bool no_mktexmf_given () const {return _no_mktexmf_given;}
      bool no_specials_given () const {return _no_specials_given;}
      const std::string& no_specials_arg () const {return _no_specials_arg;}
      bool trace_all_given () const {return _trace_all_given;}
      bool help_given () const {return _help_given;}
      bool list_specials_given () const {return _list_specials_given;}
      bool progress_given () const {return _progress_given;}
      unsigned progress_arg () const {return _progress_arg;}
      bool verbosity_given () const {return _verbosity_given;}
      unsigned verbosity_arg () const {return _verbosity_arg;}
      bool version_given () const {return _version_given;}

   protected:
      void init ();
      const CmdLineParserBase::Option* options () const {return _options;}
      void handle_page (InputReader &ir, const Option &opt, bool longopt);
      void handle_map_file (InputReader &ir, const Option &opt, bool longopt);
      void handle_bbox_format (InputReader &ir, const Option &opt, bool longopt);
      void handle_output (InputReader &ir, const Option &opt, bool longopt);
      void handle_stdout (InputReader &ir, const Option &opt, bool longopt);
      void handle_no_fonts (InputReader &ir, const Option &opt, bool longopt);
      void handle_no_styles (InputReader &ir, const Option &opt, bool longopt);
      void handle_zip (InputReader &ir, const Option &opt, bool longopt);
      void handle_rotate (InputReader &ir, const Option &opt, bool longopt);
      void handle_scale (InputReader &ir, const Option &opt, bool longopt);
      void handle_translate (InputReader &ir, const Option &opt, bool longopt);
      void handle_transform (InputReader &ir, const Option &opt, bool longopt);
      void handle_cache (InputReader &ir, const Option &opt, bool longopt);
      void handle_mag (InputReader &ir, const Option &opt, bool longopt);
      void handle_no_mktexmf (InputReader &ir, const Option &opt, bool longopt);
      void handle_no_specials (InputReader &ir, const Option &opt, bool longopt);
      void handle_trace_all (InputReader &ir, const Option &opt, bool longopt);
      void handle_help (InputReader &ir, const Option &opt, bool longopt);
      void handle_list_specials (InputReader &ir, const Option &opt, bool longopt);
      void handle_progress (InputReader &ir, const Option &opt, bool longopt);
      void handle_verbosity (InputReader &ir, const Option &opt, bool longopt);
      void handle_version (InputReader &ir, const Option &opt, bool longopt);

   private:
      static const CmdLineParserBase::Option _options[];
      bool _page_given;
      unsigned _page_arg;
      bool _map_file_given;
      std::string _map_file_arg;
      bool _bbox_format_given;
      std::string _bbox_format_arg;
      bool _output_given;
      std::string _output_arg;
      bool _stdout_given;
      bool _no_fonts_given;
      bool _no_styles_given;
      bool _zip_given;
      int _zip_arg;
      bool _rotate_given;
      double _rotate_arg;
      bool _scale_given;
      std::string _scale_arg;
      bool _translate_given;
      std::string _translate_arg;
      bool _transform_given;
      std::string _transform_arg;
      bool _cache_given;
      std::string _cache_arg;
      bool _mag_given;
      double _mag_arg;
      bool _no_mktexmf_given;
      bool _no_specials_given;
      std::string _no_specials_arg;
      bool _trace_all_given;
      bool _help_given;
      bool _list_specials_given;
      bool _progress_given;
      unsigned _progress_arg;
      bool _verbosity_given;
      unsigned _verbosity_arg;
      bool _version_given;
};

#endif