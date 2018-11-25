Documentation
#############

Philosophy
==========

The documentation is written in the same repository as the code for the
following reasons:

#. Foster the documentation to be up to date with the code implementation
#. Provide documentation versioning matching the project releases
#. Provide continuous generation and publishing of the documentation

Technology
==========

Choice
------
The documentation is built using `Sphinx <http://www.sphinx-doc.org>`_ using
`reStructuredText <http://docutils.sourceforge.net/rst.html>`_ as a markup
language. The technology choice is based on the following arguments:

* Sphinx is a mature project with a great integration with `Read the Docs <https://readthedocs.org/>`_ [#readthedocssphinx]_.
* reStructuredText has a single standard definition and
  battle-tested parsers [#elibendersky]_.
* reStructuredText has standard extension mechanisms that can help avoid
  duplicate in code [#zverovich]_.
* Both technologies proved to be good choices in large-scale documentation, most
  notably for Python's documentation [#pythondoc]_ and the Linux Kernel
  documentation [#linuxkerneldoc]_.

Tutorials
---------

Here is a non-exhaustive list of resources for writing documentation in
reStructuredText tutorials:

* `An introduction to Sphinx and Read the Docs for Technical Writers <http://www.ericholscher.com/blog/2016/jul/1/sphinx-and-rtd-for-writers>`_, by Eric Holscher.
* `reStructuredText Primer <http://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html>`_
* `Writing content <https://mcss.mosra.cz/pelican/writing-content/>`_, by Vladimír Von­druš.

Building
========

* `Read the Docs Sphinx Theme <https://sphinx-rtd-theme.readthedocs.io/en/latest/index.html>`_


References
==========

.. [#readthedocssphinx] `Getting Started with Sphinx <https://docs.readthedocs.io/en/latest/intro/getting-started-with-sphinx.html>`_
.. [#elibendersky] `reStructuredText vs. Markdown for technical documentation <https://eli.thegreenplace.net/2017/restructuredtext-vs-markdown-for-technical-documentation/#built-in-support-for-extensions>`_, Eli Bendersky.
.. [#zverovich] `reStructuredText vs Markdown for documentation <http://www.zverovich.net/2016/06/16/rst-vs-markdown.html>`_, Victor Zverovich.
.. [#pythondoc] `Documenting Python <https://devguide.python.org/documenting/>`_
.. [#linuxkerneldoc] `The Linux Kernel documentation <https://www.kernel.org/doc/html/latest/>`_
