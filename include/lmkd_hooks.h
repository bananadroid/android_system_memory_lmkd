/*
 *  Copyright 2022 Google, Inc
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*
 * This file defines no-op hook functions for LMKD. To override these
 * definitions, enable the use_lmkd_hooks product variable and create a library
 * "liblmkdhooks" that supplies definitions for the hook functions in your
 * vendor folder.
 */

#ifndef _LMKD_HOOKS_H_
#define _LMKD_HOOKS_H_

#include <sys/types.h>

__BEGIN_DECLS

#ifdef LMKD_USE_HOOKS

/*
 * Allows for interception of a kill by LMKD. This hook may attempt to free
 * memory elsewhere to avoid the specified process being killed. Returns 0 to
 * proceed with the kill, or the number of memory pages freed elsewhere to skip
 * the kill.
 */
int lmkd_free_memory_before_kill_hook(struct proc* procp, int proc_size_pages,
                                      int proc_oom_score, int kill_reason);

#else /* LMKD_USE_HOOKS */

static inline int lmkd_free_memory_before_kill_hook(struct proc*, int, int,
                                                    int) {
  return 0;
}

#endif /* LMKD_USE_HOOKS */

__END_DECLS

#endif
