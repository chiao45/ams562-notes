"""
Helper module for getting all notebooks in lectures and put them into ext links
with NBviewer
"""

from __future__ import print_function
import os

__repo_abs_path__ = os.path.abspath(
    os.path.dirname(os.path.abspath(__file__))+os.sep+'..')

# get branch

__branch__ = open(__repo_abs_path__+os.sep+'.git' +
                  os.sep+'HEAD', 'r').read()[:-2].split('/')[-1]

print('ams562-notes branch: %s' % __branch__)

__lec_path__ = __repo_abs_path__ + os.sep + 'lectures'

# NOTE keep in mind that all notebooks should locate in
#  lectures/<num>/*.ipynb

__lecs__ = os.listdir(__lec_path__)
__lecs__ = [lec for lec in __lecs__ if os.path.isdir(__lec_path__+os.sep+lec)]

__nbview_pattern__ = 'https://nbviewer.jupyter.org/github/chiao45/ams562-notes/blob/{}/lectures/%s/'.format(__branch__)

_extlinks = {}
__alias_pattern__ = 'nblec_%s'
__prefix__ = 'notebook '

for lec in __lecs__:
    pat = __alias_pattern__ % lec
    url = __nbview_pattern__ % lec
    url += '%s.ipynb'
    _extlinks[pat] = (url, __prefix__)

# NOTE by default, when we write :nblec_?:`sample`, it will show as
# notebook sample

if __name__ == '__main__':
    print(_extlinks)
