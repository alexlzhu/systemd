/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "analyze.h"
#include "analyze-unit-paths.h"
#include "path-lookup.h"
#include "strv.h"

int verb_unit_paths(int argc, char *argv[], void *userdata) {
        _cleanup_(lookup_paths_free) LookupPaths paths = {};
        int r;
        char **p;

        r = lookup_paths_init(&paths, arg_scope, 0, NULL);
        if (r < 0)
                return log_error_errno(r, "lookup_paths_init() failed: %m");

        STRV_FOREACH(p, paths.search_path)
                puts(*p);

        return 0;
}
