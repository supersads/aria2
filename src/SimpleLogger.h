/* <!-- copyright */
/*
 * aria2 - a simple utility for downloading files faster
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
/* copyright --> */
#ifndef _D_SIMPLE_LOGGER_H_
#define _D_SIMPLE_LOGGER_H_

#include "Logger.h"

class SimpleLogger:public Logger {
private:
  enum LEVEL {
    DEBUG,
    INFO,
    ERROR};
  void writeLog(int level, string msg, va_list ap, Exception* e = NULL) const;
  FILE* file;
public:
  SimpleLogger(string filename);
  SimpleLogger(FILE* logfile);
  ~SimpleLogger();

  void debug(string msg, ...) const;
  void debug(string msg, Exception* ex, ...) const;
  void info(string msg, ...) const;
  void info(string msg, Exception* ex, ...) const;
  void error(string msg, ...) const;
  void error(string msg, Exception* ex, ...) const;
};

#endif // _D_SIMPLE_LOGGER_H_

