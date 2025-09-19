#ifndef FONT_H
#define FONT_H

#define BOLD "\033[1m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_RED "\033[1;31m"
#define RESET_FONT "\033[0m"

#define MAKE_BOLD(ARG) BOLD ARG RESET_FONT
#define MAKE_BOLD_GREEN(ARG) BOLD_GREEN ARG RESET_FONT
#define MAKE_BOLD_RED(ARG) BOLD_RED ARG RESET_FONT

#endif // FONT_H
