"""
Helper module for getting all notebooks in lectures and put them into ext links
with NBviewer, in addition, the raw cpp sources will be included.
"""

from __future__ import print_function
import os

__repo_abs_path__ = os.path.abspath(
    os.path.dirname(os.path.abspath(__file__)) + os.sep + '..')

# get branch

__branch__ = open(__repo_abs_path__ + os.sep + '.git' +
                  os.sep + 'HEAD', 'r').read().split('/')[-1]
__branch__ = __branch__[:__branch__.find('\n')]

print('ams562-notes branch: %s' % __branch__)

__lec_path__ = __repo_abs_path__ + os.sep + 'lectures'

# NOTE keep in mind that all notebooks should locate in
#  lectures/<num>/*.ipynb

__lecs__ = os.listdir(__lec_path__)
__lecs__ = [lec for lec in __lecs__ if os.path.isdir(
    __lec_path__ + os.sep + lec)]

__nbview_pattern__ = 'https://nbviewer.jupyter.org/github/chiao45/ams562-notes/blob/{}/notebooks/%s/'.format(
    __branch__)
__cpp_source__ = 'https://raw.githubusercontent.com/chiao45/ams562-notes/{}/programs/%s/'.format(
    __branch__)

_extlinks = {}
__alias_pattern__ = 'nblec_%s'
__cpp_src_pattern__ = 'cpplec_%s'
__prefix__ = 'notebook '
__cpp_prefix__ = 'program '

for lec in __lecs__:
    pat = __alias_pattern__ % lec
    url = __nbview_pattern__ % lec
    url += '%s.ipynb'
    pat_cpp = __cpp_src_pattern__ % lec
    url_cpp = __cpp_source__ % lec
    url_cpp += '%s.cpp'
    _extlinks[pat] = (url, __prefix__)
    _extlinks[pat_cpp] = (url_cpp, __cpp_prefix__)

# NOTE by default, when we write :nblec_?:`sample`, it will show as
# notebook sample

if __name__ == '__main__':
    print(_extlinks)
