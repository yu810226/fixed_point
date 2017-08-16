#!/bin/bash

find . \( -name "*.c" -or \
-name "*.cpp" -or \
-name "*.cc" -or \
-name "*.h" -or \
-name "*.hpp" -or \
-name "*.inc" -or \
-name "fixed_point" \) \
-and -not -path "./build/*" \
-and -not -path "./build_*/*" > cscope.files

cscope -Rbq -i cscope.files
ctags -R --c++-kinds=+p --fields=+iaS --extra=+q
