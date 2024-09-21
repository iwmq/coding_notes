Fix Branches / Logs Displayed From Bottom
----
On my Manjaro system, for some unknown reason, when I run `gti branch` and the
result is just one line or two (e.g., I use one branch for testing repos), the
entire terminal is cleared and the result will display from bottom, causing a
very ugly, large empty area. The resulting branch name(s) is barely seen.

Ditto for `git log` if only one commit is added.

To fix, run:
```
git config --global core.pager more
```